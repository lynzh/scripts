#!/usr/bin/python2.7
# Filename : lights.py

import subprocess

a = "Street lights are ON"
b = "Street lights are OFF"

def asd():
	subprocess.call(['date', '+%H.%M'])

ixp = asd()

def craptaken():
	if ixp > 19.00:
		print(a, ixp)
	else:
		if ixp >= 00.00:
			print(a)
		else:
			if ixp > 07.00:
				print(b)
			return 0
		return 0
	return 0
print craptaken()
