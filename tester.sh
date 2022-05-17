#!/bin/bash

STD="out_std"
FT="out_ft"
BIN_PATH="bin"
BIN_STD=$BIN_PATH/"out_std.txt"
BIN_FT=$BIN_PATH/"out_ft.txt"

if test -f "$STD" && test -f $FT; then
	mkdir -p $BIN_PATH
	./$STD >> $BIN_STD
	./$FT >> $BIN_FT

	if cmp -s $BIN_STD $BIN_FT; then
		echo -e "\033[0;32m OK\033[0m"
	else
		echo -e "\033[0;31m KO\033[0m"
		diff $BIN_STD $BIN_FT
	fi

else
	echo "$STD or $FT does not exist, please compile with 'make'"
fi


# if cmp -s "bin/vector.txt" "bin/myvector.txt"; then
# 	echo -e "\033[0;33m"
# 	cat bin/vector.txt | grep "TEST-"
# 	echo -e "\033[0m"
# 	echo -e "\033[0;32m ------- TESTER VECTOR ------ OK\n\033[0m"
# else
# 	echo -e "\033[0;31m ------- TESTER VECTOR ------ KO\n\033[0m"
# 	echo "< = bin/vector.txt | > = bin/myvector.txt"
# 	echo -e "lines that are different :\n"
# 	diff bin/vector.txt bin/myvector.txt
# 	echo -e "\n"
# fi

# if cmp -s "bin/stack.txt" "bin/mystack.txt"; then
# 	echo -e "\033[0;33m"
# 	cat bin/stack.txt | grep "TEST-"
# 	echo -e "\033[0m"
# 	echo -e "\033[0;32m ------- TESTER STACK ------ OK\n\033[0m"
# else
# 	echo -e "\033[0;31m ------- TESTER STACK ------ KO\n\033[0m"
# 	echo "< = bin/stack.txt | > = bin/mystack.txt"
# 	echo -e "lines that are different :\n"
# 	diff bin/stack.txt bin/mystack.txt
# 	echo -e "\n"
# fi