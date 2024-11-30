#!/bin/bash

reset

g++ $1.cpp -Wall -DONPC -o $1

cnt=0
for i in incp*.txt; do
	./$1 < $i > outcp$cnt.txt
	sed -i 's/[ \t]*$//' outcp$cnt.txt
	if !(cmp -s "outcp$cnt.txt" "expcp$cnt.txt")
	then
		echo -e "\e[101mError in test $cnt!\e[0m"
		echo -e "\e[103;100mInput\e[0m"
		cat $i
		echo -e "\e[41mWrong Output\e[0m"
		cat outcp$cnt.txt
		echo -e "\e[44;33mCorrect Output\e[0m"
		cat expcp$cnt.txt
	else
		echo -e "\e[42;97mPassed $cnt\e[0m"
	fi
	cnt=$((cnt+1))
done;
