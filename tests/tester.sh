#!/bin/bash

if cmp -s "bin/vector.txt" "bin/myvector.txt"; then
	echo -e "\033[0;33m"
	cat bin/vector.txt | grep "TEST-"
	echo -e "\033[0m"
	echo -e "\033[0;32m ------- TESTER VECTOR ------ OK\n\033[0m"
else
	echo -e "\033[0;31m ------- TESTER VECTOR ------ KO\n\033[0m"
	echo "< = bin/vector.txt | > = bin/myvector.txt"
	echo -e "lines that are different :\n"
	diff bin/vector.txt bin/myvector.txt
	echo -e "\n"
fi

if cmp -s "bin/stack.txt" "bin/mystack.txt"; then
	echo -e "\033[0;33m"
	cat bin/stack.txt | grep "TEST-"
	echo -e "\033[0m"
	echo -e "\033[0;32m ------- TESTER STACK ------ OK\n\033[0m"
else
	echo -e "\033[0;31m ------- TESTER STACK ------ KO\n\033[0m"
	echo "< = bin/stack.txt | > = bin/mystack.txt"
	echo -e "lines that are different :\n"
	diff bin/stack.txt bin/mystack.txt
	echo -e "\n"
fi