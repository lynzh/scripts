#!/usr/bin/python2.7
# Filename : calltime.py

import subprocess

def calldate(f):
	subprocess.call(['date +%H:%M:%S'])

print calldate
print calldate
