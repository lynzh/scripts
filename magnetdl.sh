#!/bin/bash

## usage: ./download_magnet_url.sh "magnet_link"
## magnet link shoul be enclosed in quotes.

cd "/home/lynzh/.rtorrent/watch" # set your watch directory here
[[ "$1" =~ xt=urn:btih:([^&/]+) ]] || exit;
echo "d10:magnet-uri${#1}:${1}e" > "meta-${BASH_REMATCH[1]}.torrent"

# use the script as following
# replace “magnet_link” with the real link.

# cd ~/bittorrent
