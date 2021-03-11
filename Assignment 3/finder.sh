#!/bin/bash
if [ -f "a3config" ]; then #if a3congif is a file
	. ./a3config #execute a3config
	if [ -z "$DIRNAME" ] || [ -z "$EXTENSION" ]; then
		echo "Error DIRNAME and EXTENSION must be set"
		exit 2
	else
		if [ -d "$DIRNAME" ]; then
			output=$(ls -a $DIRNAME | grep ".$EXTENSION") #grep filenames with $EXTENSION in list of $DIRNAME items
			if [ -z "$output" ]; then
				echo "Unable to locate any files with extension $EXTENSION in $DIRNAME"
				exit 0
			else
				for i in $output; do
					if [ "$SHOW" = "true" ]; then
						echo "$DIRNAME/$i"
						cat $i
					else
						echo "$DIRNAME/$i"
					fi
				done
				exit 0
			fi
		else
			echo "Error directory $DIRNAME does not exist"
			exit 3
		fi
	fi
else
	echo "Error cannot find a3config"
	exit 1
fi


