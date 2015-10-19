#!/usr/bin/python
import urllib
import re
#symbols = ["Glock", "Desert Eagle", "P2000", "Negev", "P250", "AK-47","m4a1-s","CZ75-auto","USP-S","AWP","P90","mac-10","AUG","Desert Eagle","FAMAS","G3SG1","PP-Bizon","Nova","MP7","MP9","Dual Berettas","UMP-45","Sawed-Off"]

SymbolsList = open("csgosymbols")
Symbols = SymbolsList.read() 
NewSymbols = Symbols.split("\n")
i=0


while i< len(NewSymbols):
	url = 'http://steamcommunity.com/market/search?q=appid:730+StaTrak' +NewSymbols[i] 
	htmlfile = urllib.urlopen(url)
	htmltext = htmlfile.read()
	NameRegex = '<span id=\"result_0_name\" class=\"market_listing_item_name\" style=\"color: #CF6A32;\">(.+?)</span>'
	MoneyRegex = '<span style=\"color:white\">(.+?)</span>'
	NameCompile = re.compile(NameRegex)
	MoneyCompile = re.compile(MoneyRegex)
	Name = re.findall(NameCompile,htmltext)
	Money = re.findall(MoneyCompile,htmltext)

	print 'price of  ' ,NewSymbols[i][0:8],'\t is ' ,Money[1] ,' and is type ' ,Name 
	i+=1

