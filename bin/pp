#!/bin/sh
# Script to take screenshot and save to dir

FILENAME=$(date | sed -e 's/\ /_/g')
DIRECTORY='Pictures/printscreen'
Screenshot=$HOME/${DIRECTORY}/${FILENAME}

TakeShot() 
{
	import -window root $Screenshot.png 
}

OpenShot()
{
	iceweasel --new-tab $Screenshot.png
}

sleep 2;
TakeShot;
sleep 2;
OpenShot
