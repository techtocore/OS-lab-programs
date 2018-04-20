#!/bin/bash

#program to perform 4 arithmetic operations

echo "Enter the first number"
read a
echo "Enter the second number"
read b

sum=`expr $a + $b`
echo The sum of a and b is: $sum

diff=`expr $a - $b`
echo "The difference of a and b is:" $diff

mul=`expr $a \* $b`
echo "The product of a and b is:" $mul

div=`expr $a / $b`
echo "The division of a and b is:" $div
