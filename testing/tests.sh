#Rango - numero de valores
ARG=$(seq $1 $2 | sort -R | tail -n $3 | tr '\n' ' ')
./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./testing/checker_Mac $ARG
echo  "Tested $3 numbers in range [$1,$2]"
