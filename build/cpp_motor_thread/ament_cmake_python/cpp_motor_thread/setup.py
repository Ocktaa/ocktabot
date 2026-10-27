from setuptools import find_packages
from setuptools import setup

setup(
    name='cpp_motor_thread',
    version='0.0.0',
    packages=find_packages(
        include=('cpp_motor_thread', 'cpp_motor_thread.*')),
)
