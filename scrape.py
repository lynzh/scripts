#!/usr/bin/python
import urllib
import re

htmltext = urllib.urlopen('http://www.google.com/finance?q=AAPL')
regex = '<span id="ref_[^.]*_1">(.+?)</span>'

pattern = re.compile(regex)
results = re.findall(pattern,htmltext)

print results
