from setuptools import find_packages
from setuptools import setup

setup(
    name='ocktabot_kinematics',
    version='0.0.0',
    packages=find_packages(
        include=('ocktabot_kinematics', 'ocktabot_kinematics.*')),
)
