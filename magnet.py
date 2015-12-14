#!/usr/bin/python

from urllib.parse import urlparse
import urllib
import subprocess

GetUrl = subprocess.call(['sh', '/home/lynzh/scripts/bin/magparse', '/home/lynzh/magnet.file'])
ParseResult = urllib.parse.urlparse(GetUrl)
