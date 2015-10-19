#!/usr/bin/python
# Filename : rlights.py

import subprocess

def asd():
	subprocess.call(['date', '+%H.%M'])

ixp = asd()

offlights = [07.00, 08.00, 09.00, 10.00, 11.00, 12.00, 13.00, 14.00, 15.00, 16.00, 17.00, 18.00, 19.00]

onlights = [19.00, 20.00, 21.00, 22.00, 23.00, 24.00, 01.00, 02.00, 03.00, 04.00, 05.00, 06.00, 07.00]

if ixp > offlights:
	print("The lights are OFF")
if ixp > onlights:
	print("The lights are ON")

#elif ixp >= onlights:
#	print ("The time is: ", ixp, "The lights are ON")
