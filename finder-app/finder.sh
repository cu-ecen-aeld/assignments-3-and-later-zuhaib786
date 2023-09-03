#!/bin/bash
if [ $# -lt 2 ]
then
    echo "ERROR: Invalid Number of arguments"
    echo "Total number of argumnets should be 2"
    echo "The order of the argyments path should be:"
    echo "  1)Filer Directory Path."
    echo "  2)String to be searched in the specified directory path."
fi
filesdir="$1"
searchstr="$2"
if [ -d "$filesdir" ]
then
    X=$(find "$filesdir" -type f | wc -l)
    Y=$(grep -r "$searchstr" "$filesdir"| wc -l)
    echo "The number of files are $X and the number of matching lines are $Y"
    exit 0
else    
    echo "Path \"$filesdir\" does not exist"
    exit 1
fi