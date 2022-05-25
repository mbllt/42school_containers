#!/bin/bash

rm -rf res

test_diff() {

	arg=$(echo "$2" | sed 's;/;\ ;g' | sed 's/_mine//g' | sed 's/_san//g')
	name=$(echo "$arg" | cut -d" " -f4)

	mkdir -p res res/$name

	if [ "$3" -eq 1 ]; then
		$1 >> res/$name/san_std
		$2 >> res/$name/san_mine
		if cmp -s res/$name/san_std res/$name/san_mine; then
				printf "\033[0;32m     %-25s ✅\033[0m\n" san_$name
			else
				printf "\033[0;32m     %-25s ❌\033[0m\n" san_$name
				diff res/$name/san_std res/$name/san_mine >> res/$name/diff
		fi
	else
		$1 >> res/$name/out_std
		$2 >> res/$name/out_mine
		if cmp -s res/$name/out_std res/$name/out_mine; then
				printf "\033[0;32m     %-25s ✅\033[0m\n" $name
			else
				printf "\033[0;32m     %-25s ❌\033[0m\n" $name
				diff res/$name/out_std res/$name/out_mine >> res/$name/diff
		fi
	fi
}

ARRAY_STD=($(ls -d bin/*/*_std))
ARRAY_MINE=($(ls -d bin/*/*_mine))
ARRAY_STD_SAN=($(ls -d bin/*/*_std_san))
ARRAY_MINE_SAN=($(ls -d bin/*/*_mine_san))

IT=0
IT_END=($(ls bin/*/*_std | wc -l))

while [ $IT -lt $IT_END ]
do
	test_diff ./${ARRAY_STD[IT]} ./${ARRAY_MINE[IT]} 0
	test_diff ./${ARRAY_STD_SAN[IT]} ./${ARRAY_MINE_SAN[IT]} 1
	((++IT))
done