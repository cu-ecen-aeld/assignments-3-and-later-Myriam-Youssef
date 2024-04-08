#!/bin/sh
filesdir=$1
searchstr=$2
x= 
y= 

if [ "$#" -ne 2 ]
then
    echo " Error in input parameters"
    exit 1
fi

if ! [ -d "$filesdir" ]
then
    echo "Error ${filesdir} is not a directory."
    exit 1
fi

x=$(find "${filesdir}" -type f | wc -l)
y=$(grep -r --include="*" "${searchstr}" "${filesdir}" | wc -l)

echo "The number of files are ${x} and the number of matching lines are ${y}."
exit 0
