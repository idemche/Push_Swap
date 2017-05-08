# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 14:05:14 by idemchen          #+#    #+#              #
#    Updated: 2017/05/06 16:31:05 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

PS_NAME = push_swap
CHECKER_NAME = checker
FLAGS = -Wall -Werror -Wextra -O3
ALLSRC = ft_auxiliary.c \
			ft_auxiliary_functions.c \
			ft_buffer_operations.c \
			ft_cheating.c \
			ft_read_it_all.c \
			ft_libft_usages.c \
			ft_list_operations.c \
			ft_list_operations_two.c \
			ft_push_or_swap.c \
			ft_sorts.c \
			ft_stack_check.c \
			ft_swap_or_push_else.c \
			ft_swap_or_push.c \
			ft_check_three_elem.c \
			ft_universal_functions.c \
			get_next_line.c \
			get_next_line_helper.c

PS_SRC = push_swap.c
CHECKER_SRC = ft_checker.c

PS_OBJ = $(patsubst %.c, %.o, $(PS_SRC) $(ALLSRC))
CHECKER_OBJ = $(patsubst %.c, %.o, $(CHECKER_SRC) $(ALLSRC))

all: $(PS_NAME) $(CHECKER_NAME)

$(PS_NAME): $(PS_OBJ)
	@clang $(FLAGS) -o $@ $(PS_SRC) $(ALLSRC)
	@rm -f $(PS_OBJ) $(CHECKER_OBJ)
	@echo "\033[0;34mpush_swap\t\033[1;33mPush_swap compilation\t\033[0;32m[Done]\033[0m"

$(CHECKER_NAME): $(CHECKER_OBJ)
	@clang $(FLAGS) -o $@ $(CHECKER_SRC) $(ALLSRC)
	@rm -f $(PS_OBJ) $(CHECKER_OBJ)
	@echo "\033[0;34mpush_swap\t\033[1;33mChecker compilation\t\033[0;32m[Done]\033[0m"

%.o: %.c
	@clang $(FLAGS) -o $@ -c $<

remake:
	@echo "\033[0;34mpush_swap\t\033[1;33mRemake\t\033[0;32m		[In Progress]\033[0m"

clean:
	@rm -f $(PS_OBJ) $(PS_NAME)
	@rm -f $(CHECKER_OBJ) $(CHECKER_NAME)
	@echo "\033[0;34mpush_swap\t\033[1;33mCleaning obj\t\033[0;32m	[Done]\033[0m"

fclean: clean
	@rm -f $(PS_OBJ) $(PS_NAME)
	@rm -f $(CHECKER_OBJ) $(CHECKER_NAME)
	@echo "\033[0;34mpush_swap\t\033[1;33mCleaning executives\t\033[0;32m[Done]\033[0m"

re: remake fclean all

norme:
	@norminette $(PS_SRC) $(CHECKER_SRC) $(ALLSRC)
	@echo "\033[1;34mpush_swap\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"
