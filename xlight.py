#!/usr/bin/python
# Filename : xlight.py

import subprocess

def asd():
	subprocess.call(['date', '+%H.%M'])

klokka = asd()
lights = True or False

def wossop():
	if klokka < 07.00:
		lights == True
	elif klokka > 07.00:
		lights == False
	elif klokka < 19.00:
		lights == False
	elif klokka > 19.00:
		lights == True
	return lights

if wossop() == True:
	print("The lights are on")
elif wossop() == False:
	print("The lights are off")

print 'The time is ', asd(), 'and the lights are ', lights
