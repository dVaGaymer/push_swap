#Rango - numero de valores
A=-10000
B=10000
ARG=$(seq $A $B | sort -R | tail -n $3 | tr '\n' ' ')
./push_swap $ARG
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./testing/checker_Mac $ARG
echo  "Tested $3 numbers in range [$A, $B]"
