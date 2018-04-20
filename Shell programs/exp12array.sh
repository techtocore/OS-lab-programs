#!/bin/bash

#using arrays

arr=(2 4 1 6)

size=${#arr[@]}

for((i=0;i<4;i++))
do
	echo ${arr[$i]}
done

echo $size