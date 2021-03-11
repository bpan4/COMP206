#!/bin/bash

if [[ $# != 2 ]];then
	echo -e "Error: inappropriate number of arguments \nUsage: ./delta.sh dir1 dir2"
	exit 1
fi
DIR1=$1
DIR2=$2
if [[ -d "$DIR1" ]] && [[ -d "$DIR2" ]];then #if arguments passed are valid directories
	for i in $DIR1/*; do #for every file in DIR1
        	name=$(basename "$i") #basename returns the name of the file
        	if [[ -f "$DIR2/$name" ]];then #if the file exists within DIR2
                	if cmp -s -- "$DIR1/$name" "$DIR2/$name";then #compares file content silently! 
                        	continue
			else
				echo -e "$name\n"
                	fi
        	fi
	done
else
	echo -e "Error: arguments passed are not valid directories\nUsage: ./delta.sh dir1 dir2"
	exit 2
fi
