#!/bin/bash

open=false
all=false
flagcounter=0
for arg in "$@"; do
	case $arg in
		-c)
		open=true
		((flagcounter+=1))
		;;
		-a)
		all=true
		((flagcounter+=1))
		;;
	esac
done

((pattern_index=$flagcounter+1))
pattern="${!pattern_index}"
if [ $flagcounter -eq $# ]; then
	echo "Error missing the pattern argument."
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
	exit 1
fi

((path_index=$flagcounter+2))
if [ -z ${!path_index} ]; then
	# if the element two arguments after the flags is empty, we take current directory to be the working one
	path="."
else
	# if the element two arguments after the flags is not empty, it is the path we search in
	path="${!#}"
fi 	


if [ ! -d $path ]; then
	echo "Error $path is not a valid directory"
	exit 1
fi

result=$(ls -a $path | grep $pattern)
if [[ -z $result ]]; then
	echo "Unable to locate any files that has pattern $pattern in its name in $path"
fi
for file in $result; do
	if [ "$open" = true ] && [ "$all" = false ]; then 
		echo "==== Contents of: $path/$file ===="
		cat $path/$file
		exit 0
	elif [ "$open" = true ] && [ "$all" = true ]; then
		echo "==== Contents of: $path/$file ===="
		cat $path/$file
	elif [ "$open" = false ] && [ "$all" = true ]; then
		echo "$path/$file"
	elif [ "$open" = false ] && [ "$all" = false ]; then
		echo "$path/$file"
		exit 0
	fi
done
