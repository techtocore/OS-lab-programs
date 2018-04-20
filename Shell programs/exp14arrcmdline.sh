#!/bin/bash

#to read elements using command line arguments and assigning to an array

for i in $*
do
	 arr[$i]=$i
	 ((i++))
done

echo "Entered elements are"

for i in $*
do
	echo ${arr[$i]}
done




