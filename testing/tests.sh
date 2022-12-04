A=-10000
B=10000
ARG=$(seq $A $B | sort -R | tail -n $1 | tr '\n' ' ')
ERR=`./push_swap $ARG | ./testing/checker_Mac $ARG`
./push_swap $ARG
./push_swap $ARG | wc -l
echo $ARG
if [[ $ERR == "OK" ]]
then
	echo "\033[1;32m$ERR\033[0m"
else
	echo "\033[1;31mERROR ERRROR ERROR ERROR ERROR ERROR ERROR$ERR\033[0m"
fi
