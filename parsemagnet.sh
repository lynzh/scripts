#!/bin/zsh
# script attempts to extract the main magnet link from kickass.to torrent page.

# I say attempt because this is a very ugly hack and probably fails in most cases
# We are looking for that one case were it doesent fail!:)

cat "$@" | \
grep -P "data-nop\ title="Magnet\ link"\ href="magnet:\?xt=urn:btih:[[:alnum:]]{40}&dn=[%[:alnum:]\+]{1,}&[%[:alnum:]=.]{1,}&[[:alnum:]%=]{1,}\.[[:alnum:]]{1,}\.[[:alnum:]]{1,5}%3A[[:alnum:]]{1,}" | sed 's/\ \ \ \ <a\ class="kaGiantButton\ "\ data-nop\ title="Magnet\ link"\ href="//g' | sed 's/"\ ><i\ class="ka\ ka-magnet"><\/i><\/a>//g'
