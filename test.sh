# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 21:10:34 by idemchen          #+#    #+#              #
#    Updated: 2017/05/08 21:10:35 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

echo "\033[1;33mShould return that stack is sorted and checker must say that there is a wrong output\033[0m\n"
./push_swap 4 5 12 25 89
./push_swap 4 5 12 25 89 | ./checker 4 5 12 25 89
echo "\n"
echo "\033[1;33m 2 operations at max\033[0m\n"
./push_swap 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1
echo "\n"
echo "\033[1;33mShould be done in only one swap\033[0m\n"
./push_swap 2 1 3
./push_swap 2 1 3 | ./checker 2 1 3
echo "\n"
echo "\033[1;33mShould be done in less than 20 operations\033[0m\n"
./push_swap 4 6 10 12 19 25 36 29
./push_swap 4 6 10 12 19 25 36 29 | ./checker 4 6 10 12 19 25 36 29
echo "\n"
echo "\033[1;33mShould be done between 5 and 20 operations\033[0m\n"
./push_swap 100 1000 10 100000 10000
./push_swap 100 1000 10 100000 10000 | ./checker 100 1000 10 100000 10000
echo "\n"
echo "\033[1;33mShould be done between 5 and 20 operations too\033[0m\n"
./push_swap 12 25 5 154 89
./push_swap 12 25 5 154 89 | ./checker 12 25 5 154 89
echo "\n"
echo "\033[1;33mShould return that nothing to sort and check\033[0m\n"
./push_swap
./push_swap | ./checker
echo "\n"
echo "\033[1;33mShould return Error (Non-digit arguments)\033[0m\n"
./push_swap 56 76 lulz 67 62
./push_swap 56 76 ololol 67 62
./push_swap lolka 56 121 45 5
./push_swap l
./push_swap 56 76 lulz 67 62 | ./checker 56 76 lulz 67 62
./push_swap 56 76 ololol 67 62 | ./checker 56 76 ololol 67 62
./push_swap lolka 56 121 45 5 | ./checker lolka 56 121 45 5
echo "\033[1;33mShould return Two errors for both checker and Push-swap\033[0m\n"
./push_swap l | ./checker l
echo "\n"
echo "\033[1;33mShould return Error (double)\033[0m"
./push_swap 15 15
./push_swap 45 12 57 52 33 33
./push_swap 45 12 57 52 33 45
./push_swap 15 15 | ./checker 15 15
./push_swap 45 12 57 52 33 33 | ./checker 45 12 57 52 33 33
./push_swap 45 12 57 52 33 45 | ./checker 45 12 57 52 33 45
echo "\n"
echo "\033[1;33mShould return Error (bigger than integer)\033[0m\n"
./push_swap 2147483648
./push_swap 29999999999
./push_swap -2147483649
./push_swap -29999999999
./push_swap 2147483648 | ./checker 2147483648
./push_swap 29999999999 | ./checker 29999999999
./push_swap -2147483649 | ./checker -2147483649
./push_swap -29999999999 | ./checker -29999999999
echo "\n"
echo "\033[1;33mShould that stack is sorted + checker error\033[0m\n"
./push_swap 2
./push_swap 2 | ./checker 2
echo "\n"
echo "\033[1;33mRandom numbers in stack 5 6 2 9 1 3\033[0m\n"
./push_swap 5 6 2 9 1 3
./push_swap 5 6 2 9 1 3 | ./checker 5 6 2 9 1 3
echo "\n"
echo "\033[1;33mRead with string\033[0m\n"
./push_swap "5 6 2 9 1 3"
./push_swap "5 6 2 9 1 3" 8 7
./push_swap "5 6" -100 -200 -300 999
./push_swap 1 2 3 4 5 6 "-999" "13" "12"
./push_swap "5 6 2 9 1 3" | ./checker "5 6 2 9 1 3"
./push_swap "5 6 2 9 1 3" 8 7 | ./checker "5 6 2 9 1 3" 8 7
./push_swap "5 6" -100 -200 -300 999 | ./checker "5 6" -100 -200 -300 999
./push_swap 1 2 3 4 5 6 "-999" "13" "12" | ./checker 1 2 3 4 5 6 "-999" "13" "12"

./push_swap 5 6 2 9 1 3 | ./checker 5 6 2 9 1 3
echo "\n"
echo "\033[1;33mTests with negatives and positives\033[0m\n"
./push_swap 2 -5 26 -7888 -998 564 12
./push_swap 2 -5 26 -7888 -998 564 12 | ./checker 2 -5 26 -7888 -998 564 12
echo "\n"
echo "\033[1;33mTests with only negatives\033[0m\n"
./push_swap -2 -5 -26 -7888 -998 -564 -12
./push_swap -2 -5 -26 -7888 -998 -564 -12 | ./checker -2 -5 -26 -7888 -998 -564 -12
echo "\n"

echo "\033[1;33mDifferent Ko's\033[0m\n"
./push_swap -2 -5 -26 -7888 -564 -998 -12 | ./checker -2 -5 -26 -7888 -998 -564 -12
./push_swap -5 -4 0 -7888 -564 -1 -12 | ./checker -2 -5 -26 -7888 -998 -564 -12
echo "(one element in checker):"
./push_swap -5 -4 0 -7888 -564 -1 -12 | ./checker 2
echo "(Ko again):"
./push_swap -5 -4 0 -7888 -564 -1 -12 | ./checker 2 3
echo "\n"
echo "\033[1;33mRandom 100 numbers\033[0m\n"
ruby -e "puts (0..99).to_a.shuffle.join(' ')" > lolich
echo "checker result:"
./push_swap -s lolich | ./checker -s lolich
echo "quantity:"
./push_swap -s lolich  | wc -l
rm -r lolich
echo "\n"
echo "\033[1;33mRandom 100 numbers negative\033[0m\n"
ruby -e "puts (-99..0).to_a.shuffle.join(' ')" > lolich
echo "checker result:"
./push_swap -s lolich | ./checker -s lolich
echo "quantity:"
./push_swap -s lolich  | wc -l
rm -r lolich
echo "\n"
echo "\033[1;33mRandom 201 numbers negative + positive\033[0m\n"
ruby -e "puts (-100..100).to_a.shuffle.join(' ')" > lolich
echo "checker result:"
./push_swap -s lolich | ./checker -s lolich
echo "quantity:"
./push_swap -s lolich  | wc -l
rm -r lolich
echo "\n"
echo "\033[1;33mRandom 501 numbers positive + negative\033[0m\n"
ruby -e "puts (-250..249).to_a.shuffle.join(' ')" > lolich
echo "checker result:"
./push_swap -s lolich | ./checker -s lolich
echo "quantity:"
./push_swap -s lolich  | wc -l
rm -r lolich
echo "\n"
##echo "\033[1;33mWhat is happening with a lot of parameters?\033[0m\n"
##./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"`

##echo "\033[1;33mWhat is happening with even more parameters?\033[0m\n"
##./push_swap `ruby -e "puts (-5000..5000).to_a.reverse.insert(rand(8000) + 1000, 10001).join(' ')"` | wc -l
