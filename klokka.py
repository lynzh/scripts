#!/usr/bin/python
# Filename : klokka.py

import subprocess

def klokka():
	subprocess.call(['date', '+%H.%M.%S'])
klokka()




