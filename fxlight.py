#!/usr/bin/python
# Filename : fxlight.py

import subprocess

a1 = [07, 08.00, 09.00, 10, 11, 12, 13, 14, 15, 16, 17, 18]
a2 = [19, 20, 21, 22, 23, 24, 00, 01, 02, 03, 04, 05, 06]

def asd():
	subprocess.call(['date', '+%H.%M'])

fxl = asd()

def whatif():
	if fxl > a1:
		print ("lightoff")
whatif()

def whatsup():
	if fxl > a2:
		print ("lighton")

whatsup()

