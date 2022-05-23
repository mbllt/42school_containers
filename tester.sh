#!/bin/bash

test_diff() {

	arg=$(echo "$2" | sed 's;/;\ ;g' | sed 's/_mine//g' | sed 's/_san//g')
	name=$(echo "$arg" | cut -d" " -f4)

	mkdir res res/$name

	if [ "$3" -eq 1 ]; then
		$1 >> res/$name/san_std
		$2 >> res/$name/san_mine
	elif [ "$3" -eq 2 ]; then
		$1 >> res/$name/leak_std
		$2 >> res/$name/leak_mine
	else
		$1 >> res/$name/out_std
		$2 >> res/$name/out_mine
	fi

	if cmp -s res/$name/out_std res/$name/out_mine; then
			printf "\033[0;32m     %-20s ✅\033[0m\n" $name
		else
			printf "\033[0;32m     %-20s ❌\033[0m\n" $name
			diff res/$name/out_std res/$name/out_mine >> res/$name/diff
	fi
}

ARRAY_STD=($(ls -d bin/*/*_std))
ARRAY_MINE=($(ls -d bin/*/*_mine))
ARRAY_STD_SAN=($(ls -d bin/*/*_std_san))
ARRAY_MINE_SAN=($(ls -d bin/*/*_mine_san))

echo $ARRAY_STD

IT=0
IT_END=($(ls bin/*/*_std | wc -l))

while [ $IT -lt $IT_END ]
do
	test_diff ./${ARRAY_STD[IT]} ./${ARRAY_MINE[IT]} 0
	test_diff ./${ARRAY_STD_SAN[IT]} ./${ARRAY_MINE_SAN[IT]} 1
	test_diff ./${ARRAY_STD[IT]} ./${ARRAY_MINE[IT]} 2
	((++IT))
done