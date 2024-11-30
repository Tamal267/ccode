#!/bin/bash

cnt=0
for i in incp*.txt; do
	cnt=$((cnt + 1));
done;

echo -e "\e[4mInput $cnt\e[0m"
cat > tempInp.txt 

echo -e "\e[4mExpected $cnt\e[0m"
cat > tempExp.txt

cat tempInp.txt > incp$cnt.txt
cat tempExp.txt > expcp$cnt.txt
