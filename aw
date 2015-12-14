#!/bin/sh
#
# script to pass arguments to $HOME/scripts/acdc_inven

file=$HOME/scripts/acdc_inven

usage()
{
	echo "This script passes information to your arduino shopping list\n\tUsage $0 {ITEM NUMBER} {ITEM NAME} {QUANTITY WANT} {PRICE PER ITEM}"
	exit 1
}

if [ $# -lt 1 ]
then
	usage
fi

echo "$@" >> $file 
