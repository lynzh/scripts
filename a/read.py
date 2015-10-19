#!/usr/bin/python2.7
# filename read.py

from sys import argv
script, txt = argv

ifile = open(txt)

def checkit(f):
	f.read()

def closeit(f):
	f.close()

print checkit(ifile)

closeit(ifile)
