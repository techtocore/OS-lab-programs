#!/bin/bash

#an example of for loop with command line argument

echo "The multipication table for the number $1 is"
i=1

while [ $i -le 10 ]
do
	echo "$1 * $i =`expr $1 \* $i`"
  	#i=`expr $i + 1`
	  ((i++))
done 
