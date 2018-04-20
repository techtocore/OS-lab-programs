#!/bin/bash

#an example of for in loop

echo "Enter the number"
read n
echo "The multipication table for the number $n is"

for i in 1 2 3 4 5 6 7 8 9 10
do
	echo "$n * $i =`expr $n \* $i`"
done 
