#!/usr/bin/python
# Filename : fixnet.py

import subprocess

def asd():
	subprocess.call(['ifconfig', 'eth0', '192.168.0.251', 'netmask', '255.255.255.0'])
