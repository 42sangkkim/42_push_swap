#!/bin/bash


NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
YELLOW='\033[1;33m'

printf "${PURPLE}Evaluation test cases\n"

printf "Error manegement test ${NOCOLOR}\n\
Not number arguments\n"





echo "Error management test"

echo "Not number arguments"
echo "./push_swap one two three"
./push_swap one two three
echo "./push_swap dasd"
./push_swap dasd

echo "Duplicated arguments"
echo "./push_swap 1 2 3 1"
./push_swap 1 2 3 1
echo "./push_swap 0 1 -1 1"
./push_swap 0 1 -1 1

echo "Bigger than MAXINT or smaller than MININT"
echo "./push_swap 2147483648"
./push_swap 2147483648
echo "./push_swap -2147483649"
./push_swap -2147483649

echo "No arguments"
echo "./push_swap"
./push_swap

echo "신원 테스트"
echo "./push_swap 42"
./push_swap 42
echo "./push_swap 0 1 2 3"
./push_swap 0 1 2 3
echo "./push_swap 0 1 2 3 4 5 6 7 8 9"
./push_swap 0 1 2 3 4 5 6 7 8 9

echo "Simple version"
echo "ARG=\"2 1 0\" exec, ./push_swap \$ARG | ./checker_Mac \$ARG"
ARG="2 1 0" exec, ./push_swap $ARG | ./checker $ARG
echo "./push_swap \$ARG | wc -l"
./push_swap $ARG | wc -l

echo "Another simple version"
echo "ARG=\"1 5 2 4 3\" exec, ./push_swap \$ARG | ./checker_Mac \$ARG"
ARG="1 5 2 4 3" exec, ./push_swap $ARG | ./checker $ARG
echo "./push_swap \$ARG | wc -l"
./push_swap $ARG | wc -l
echo "5 random values"
echo 