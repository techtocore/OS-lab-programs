#!/bin/bash

#to check if a number is divisible by a number

echo "Enter the numerator"
read num
echo "Enter the dinominator"
read din
d=`expr $num % $din`
if [ $d == 0 ]
then
	echo $num "is divisible by" $din
else
	echo $num "is not divisible by" $din
fi
