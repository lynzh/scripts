#!/usr/bin/python
# Filename : homebrew.py

import subprocess

def time():
	subprocess.call(['date', '+%H.%M'])

print time()


