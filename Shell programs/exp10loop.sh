#!/bin/bash

#an example of for loop with command line argument

echo "The multipication table for the number $1 is"

for((i=1;i<=10;i++))
do
#	echo "1 * $i =`expr 1 \* $i`"
echo "$1 * $i =`expr $1 \* $i`"
done 
