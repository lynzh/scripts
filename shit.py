#!/usr/bin/python
import urllib
import re

i=0

while i< len(HrefGet[i]):
	url = 'http://lattis.se/playlist/'
	htmlfile = urllib.urlopen(url)
	htmltext = htmlfile.read()
	HrefGet = 'href=\"(.+?)\"'
	GETurl = 'http://lattis.se/playlist/' +HrefGet[i] 
	NameCompile = re.compile(HrefGet)
	Name = re.findall(NameCompile,htmltext)
	print 'Getting link' +Name[i] 
	i+=1

