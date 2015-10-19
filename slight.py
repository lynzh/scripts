#!/usr/bin/python
# Filename : slight.py

import subprocess

def asd():
	subprocess.call(['date', '+%H.%M'])

time = asd()

def callback():
	if time > 19.00:
		print "The lights are ON"
	else:
		print "The lights are OFF"

callback()

