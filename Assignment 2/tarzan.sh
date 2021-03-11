#!/bin/bash
if [ $# -eq 2 ]; then 
	if [ -f $2 ]; then
		output="$(tar -tvf $2 | grep -l "$1")"
		if [[ -z $output ]]; then
			echo "$1 does not exist in $2"
		else
			echo "$1 exists in $2"
		fi
	else
		echo "Error, cannot find tar file $2"
	fi
else
	echo "Usage ./tarzan.sh filename tarfile"
fi
