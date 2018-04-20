#!/bin/bash

#using arrays

echo "enter the array index"
read n

echo "Enter the array elements"
for((i=0;i<$n;i++))
do

	read arr[$i]
done


echo "Entered elements are"
for((i=0;i<$n;i++))
do
	echo ${arr[$i]}
done

