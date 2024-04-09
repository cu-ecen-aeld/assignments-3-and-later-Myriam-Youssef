#!/bin/sh

writefile=$1
writestr=$2

if [ "$#" -ne 2 ];then

echo "Please specify the correct arguments"
exit 1;

fi

touch "${writefile}"

if ! [ -f "${writefile}" ];then
echo "Error: path is not created"
exit 1

fi

echo "${writestr}" > "${writefile}"