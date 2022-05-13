#!/bin/bash

if cmp -s "res/res_vector.txt" "res/res_myvector.txt"; then
	echo -e "\033[0;33m"
	cat res/res_vector.txt | grep "TEST-"
	echo -e "\033[0m"
	echo -e "\033[0;32mTester Vector ------ ok\n\033[0m"
else
	echo -e "\033[0;31mTester Vector ------ ko\n\033[0m"
	echo "< = res/res_vector.txt | > = res/res_myvector.txt"
	echo -e "lines that are different :\n"
	diff res/res_vector.txt res/res_myvector.txt
	echo -e "\n"
fi
