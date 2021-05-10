#!/bin/bash

while IFS= read -r line
do
	../push_swap $line | ../checker $line
	echo -n "> "
	../push_swap $line | wc | tr -s ' ' | cut -d' ' -f 2
done < $*
