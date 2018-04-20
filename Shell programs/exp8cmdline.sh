#!/bin/bash

#usage of command line arguments

echo "File name is : $0"
echo "First parameter entered is :$1"
echo "Second parameter entered is :$2"


echo "Third parameter entered is :$#"
echo "Forth parameter entered is :$*"
echo "Fifth parameter entered is :$$"
echo "Sixth parameter entered is :$!"



echo ""
echo "******************"

echo "The command line parameters printed using for loop"

for token in $@
do 
echo "The command line parameters are: $token"
done


echo "Seventh parameter entered is :$?"
