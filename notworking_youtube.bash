#!/bin/bash
# emit a last gasp of information
function croak {
  echo "$0: $2" >&2;  exit $1;
}
# parse incoming html and return evaluable bash code setting the t and video_id variables
function get_params { 
  grep '^[ ]*var[ ]\+swfArgs[ ]*=[ ]*{[ ]*' \
  | sed 's/.*{\s*//;  # remove begin section
    s/}\s*;\s*$//;    # remove end section
    s/"\([^"]*\)"\s*:\s*\("[^"]*"\)\s*,\?\s*/\1=\2\n/g  # translate js array mappings into bash assignments' \
  | egrep '^(t|video_id)=' \
  || croak 1 "couldn't grep url parameters; pipe status='${PIPESTATUS[@]}'";
}
# get the html and make it parseable
function get_html {
  { curl -s "$1" || croak 2 "error $? from curl"; } | tidy -quiet -wrap 0 2>/dev/null;
}
# fetch the frontend web page and parse the backend url out of it
function get_url {
  eval "$(get_html "$1" | get_params)";
  echo  "
}
