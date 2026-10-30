"""Animate the CSV written by stewart_stacked (replaces the MATLAB animation block).

Usage:
    python3 plot_frames.py stewart_frames.csv            # interactive window
    python3 plot_frames.py stewart_frames.csv --gif out.gif
Needs: numpy, matplotlib  (pip install numpy matplotlib)
"""
import argparse
import csv

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation, PillowWriter

JOINTS = "RST"
JOINT_COLORS = ["#d9541a", "#0072bd", "#77ab30"]                  # links to R, S, T
PLATE_COLORS = ["#4d99f2", "#f2a640", "#8ccc73", "#bf8ce6"]       # top1, top2, ...


def load(path):
    with open(path, newline="") as fh:
        rows = list(csv.DictReader(fh))
    cols = rows[0].keys()
    n_stages = max(int(c[1:c.index("_")]) for c in cols if c.startswith("s") and "_" in c)
    rows = [r for r in rows if r["valid"] == "1"]            # skip unsolved frames
    if not rows:
        raise SystemExit("no valid frames in " + path)

    def pts(r, k, grp):
        """3x3 array, columns = R, S, T (same layout as the C++ Mat3)."""
        return np.array([[float(r[f"s{k}_{grp}{j}_{c}"]) for j in JOINTS] for c in "xyz"])

    frames = []
    for r in rows:
        stages = []
        for k in range(1, n_stages + 1):
            stages.append({
                "P": pts(r, k, "P"),            # joints
                "O": pts(r, k, "O"),            # top hinge corners
                "B": pts(r, k, "B"),            # bottom hinge corners
                "Q": np.array([[float(r[f"s{k}_Q{a}{b}"]) for b in range(3)] for a in range(3)]),
                "pose": [float(r[f"s{k}_{n}"]) for n in ("x", "y", "z", "roll", "pitch", "yaw")],
            })
        frames.append({"frame": int(r["frame"]),
                       "inputs": [float(r[f"in_{j}"]) for j in JOINTS],
                       "stages": stages})
    return frames, n_stages, len(rows)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("csv")
    ap.add_argument("--gif", help="save the animation as a GIF instead of showing it")
    ap.add_argument("--interval", type=int, default=30, help="ms between frames")
    args = ap.parse_args()

    frames, n_stages, n_valid = load(args.csv)
    fig = plt.figure(figsize=(9, 8))
    ax = fig.add_subplot(projection="3d")

    # fixed axis limits from every point of every frame
    allp = np.hstack([np.hstack([s[g] for s in f["stages"] for g in "POB"]) for f in frames])
    lo, hi = allp.min(axis=1) - 0.6, allp.max(axis=1) + 0.6
    lo[2] = min(lo[2], -0.6)
    span = (hi - lo).max() / 2
    mid = (hi + lo) / 2

    # base plate (static) = bottom corners of stage 1
    base = frames[0]["stages"][0]["B"]
    ax.plot(*np.c_[base, base[:, :1]], "k-", lw=2)

    # artists that move
    tops, bot_links, top_links, tris, axes = [], [], [], [], []
    for k in range(n_stages):
        col = PLATE_COLORS[k % len(PLATE_COLORS)]
        tops.append(ax.plot([], [], [], "-", color=col, lw=3)[0])
        bot_links.append([ax.plot([], [], [], "-", color=c, lw=3)[0] for c in JOINT_COLORS])
        top_links.append([ax.plot([], [], [], "-", color=c, lw=3)[0] for c in JOINT_COLORS])
        tris.append(ax.plot([], [], [], "k--o", lw=1, ms=4, mfc="w")[0])
        axes.append([ax.plot([], [], [], "-", color=c, lw=2)[0] for c in ("r", "g", "b")])
    title = ax.set_title("")
    frame_len = 1.2

    def draw(i):
        f = frames[i]
        for k, s in enumerate(f["stages"]):
            O, P, B, Q = s["O"], s["P"], s["B"], s["Q"]
            tops[k].set_data_3d(*np.c_[O, O[:, :1]])
            for j in range(3):
                bot_links[k][j].set_data_3d(*np.c_[B[:, j], P[:, j]])
                top_links[k][j].set_data_3d(*np.c_[O[:, j], P[:, j]])
            tris[k].set_data_3d(*np.c_[P, P[:, :1]])
            c = O.mean(axis=1)
            for a in range(3):   # plate frame: columns of Q
                axes[k][a].set_data_3d(*np.c_[c, c + frame_len * Q[:, a]])
        x, y, z, ro, pi, ya = f["stages"][-1]["pose"]
        title.set_text(f"frame {f['frame']}   inputs {f['inputs'][0]:.1f}° {f['inputs'][1]:.1f}° "
                       f"{f['inputs'][2]:.1f}°\ntop{n_stages}: ({x:.2f}, {y:.2f}, {z:.2f})  "
                       f"roll {ro:.1f}°  pitch {pi:.1f}°  yaw {ya:.1f}°")
        return []

    ax.set_xlim(mid[0] - span, mid[0] + span)
    ax.set_ylim(mid[1] - span, mid[1] + span)
    ax.set_zlim(lo[2], lo[2] + 2 * span)
    ax.set_box_aspect((1, 1, 1))
    ax.set_xlabel("x"), ax.set_ylabel("y"), ax.set_zlabel("z")
    ax.view_init(elev=15, azim=35)

    anim = FuncAnimation(fig, draw, frames=n_valid, interval=args.interval, blit=False)
    if args.gif:
        anim.save(args.gif, writer=PillowWriter(fps=max(1, 1000 // args.interval)))
        print("saved", args.gif)
    else:
        plt.show()


if __name__ == "__main__":
    main()
