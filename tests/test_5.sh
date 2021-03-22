#!/bin/bash

while IFS= read -r line
do
	./push_swap $line | ./checker $line
	./push_swap $line | wc
done < "./5.txt"
