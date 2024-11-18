#!/bin/bash

g++ $1.cpp -Wall -DONPC -o $1

cnt=0
for i in incp*.txt; do
	echo "Running test $((cnt+1))"
	./$1 < $i > outcp$cnt.txt
	if !(cmp -s "outcp$cnt.txt" "expcp$cnt.txt")
	then
		echo "Error found!"
		echo -e "\e[4mInput\e[0m"
		cat $i
		echo -e "\e[4mWrong Output\e[0m"
		cat outcp$cnt.txt
		echo -e "\e[4mCorrect Output\e[0m"
		cat expcp$cnt.txt
	fi
	cnt=$((cnt+1))
done;
