#!/bin/bash

#case construct 

echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "Enter the options
	1 for addition
	2 for subtraction
	3 for multiplication
	4 for division
	5 for exit
"
read op

case $op in
1)
sum=`expr $a + $b`
echo "The sum of a and b is:" $sum
;;

2)
diff=`expr $a - $b`
echo "The difference of a and b is:" $diff
;;

3)
mul=`expr $a \* $b`
echo "The product of a and b is:" $mul
;;

4)
div=`expr $a / $b`
echo "The division of a and b is:" $div
;;

5) exit
;;

*)echo"Invalid option"
;;
esac
