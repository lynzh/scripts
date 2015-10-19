#!/usr/bin/python
# Filename : fixnet.py

import subprocess

def ipadd():
	subprocess.call(['ifconfig', 'eth0', '192.168.0.251', 'netmask', '255.255.255.0'])


def gwadd():
	subprocess.call(['route', 'add', 'default', 'gw', '192.168.0.1'])

ipadd()
gwadd()
