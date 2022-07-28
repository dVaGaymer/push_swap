TEST_PATH="/Users/alopez-g/Documents/42/rank02/push_swap/testing/logs"
TEST_PATH="/Users/al7aro/Development/42/rank02/push_swap/testing/logs"
#Rango - numero de valores
A=-10000
B=10000
ARG=$(seq $A $B | sort -R | tail -n $3 | tr '\n' ' ')
ERR=`./push_swap $ARG | ./testing/checker_Mac $ARG`
if [[ $4 == "1" ]]
then
	./push_swap $ARG
	./push_swap $ARG | wc -l
	echo $ARG
	if [[ $ERR == "OK" ]]
	then
		echo "\033[1;32m$ERR\033[0m"
	else
		echo "\033[1;31mERROR ERRROR ERROR ERROR ERROR ERROR ERROR$ERR\033[0m"
		echo $ARG >> $TEST_PATH/error_log
	fi
fi
echo  "Tested $3 numbers in range [$A, $B] \033[1;32m$ERR\033[0m" >> $TEST_PATH/$3_log
