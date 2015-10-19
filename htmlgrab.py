#!/usr/bin/python
import urllib
import re
url2s = ["http://steamcommunity.com/market/listings/730/StatTrak%E2%84%A2%20AK-47%20|%20Redline%20%28Battle-Scarred%29?filter=StaTrak"]

urls = ["http://itavisen.no","http://digi.no"]
i=0
regex = '<title>(.+?)</title>'
pattern = re.compile(regex)
regex2 = '<span class(.+?)with_fee(.+?)</span>'
pattern2 = re.compile(regex2)

while i< len(url2s):
	steamfile = urllib.urlopen(url2s[i])
	steamtxt = steamfile.read()
	money = re.findall(pattern2,steamtxt)
	print money
	i=+1 
i = 0
while i< len(urls):
	htmlfile = urllib.urlopen(urls[i])
	htmltext = htmlfile.read()
	titles	= re.findall(pattern,htmltext)
	
	print titles
	i=+1
