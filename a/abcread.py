#!/usr/bin/python
# Filename abcread.py

from sys import argv
script, filename = argv

textfile = file(filename)

def checkdat(f):
	print f.read()

def closedat(f):
	f.close()

checkdat(textfile)

closedat(textfile)
