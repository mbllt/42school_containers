#!/bin/bash

if cmp -s "res/res_vector.txt" "res/res_myvector.txt"; then
	echo -e "\033[0;33m"
	cat res/res_vector.txt | grep "TEST-"
	echo -e "\033[0m"
	echo -e "\033[0;32m ------- TESTER VECTOR ------ OK\n\033[0m"
else
	echo -e "\033[0;31m ------- TESTER VECTOR ------ KO\n\033[0m"
	echo "< = res/res_vector.txt | > = res/res_myvector.txt"
	echo -e "lines that are different :\n"
	diff res/res_vector.txt res/res_myvector.txt
	echo -e "\n"
fi
