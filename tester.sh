#!/bin/bash

test_diff() {

	test=$(echo "$2" | sed 's;/;\ ;g')
	name=$(echo "$test" | cut -d" " -f3)

	if cmp -s $1 $2; then
			echo -e "\033[0;32m $name ok\033[0m"
		else
			echo -e "\033[0;31m $name ko\033[0m"
			diff $1 $2 >> "$2.diff"
	fi
}

ARRAY_STD=($(ls -d res/*/*_std))
ARRAY_MINE=($(ls -d res/*/*_mine))
ARRAY_STD_SAN=($(ls -d res/*/*_std_san))
ARRAY_MINE_SAN=($(ls -d res/*/*_mine_san))

IT=0
IT_END=($(ls res/*/*_std | wc -l))

while [ $IT -lt $IT_END ]
do
	test_diff ${ARRAY_STD[IT]} ${ARRAY_MINE[IT]}
	((++IT))
done