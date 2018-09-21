# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 15:00:17 by mmahloko          #+#    #+#              #
#    Updated: 2018/08/29 08:53:07 by mmahloko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

DIR_P = ./push_s/

DIR_C = ./check/

SRC_P = $(DIR_P)game_rules.c $(DIR_P)input.c $(DIR_P)push_swap.c\
	$(DIR_P)stack.c $(DIR_P)sorting_b.c $(DIR_P)heuristics.c\
	$(DIR_P)sorting_b2.c $(DIR_P)heuristics1.c $(DIR_P)heuristics2.c\
	$(DIR_P)sorting_a.c $(DIR_P)sorting_a2.c $(DIR_P)paths_for_max.c\
	$(DIR_P)paths_for_1.c $(DIR_P)paths_for_3.c

OBJ_P = game_rules.o input.o push_swap.o stack.o sorting_b.o\
	sorting_b2.o heuristics.o heuristics1.o heuristics2.o sorting_a.o\
	sorting_a2.o paths_for_max.o paths_for_3.o paths_for_1.o

SRC_C = $(DIR_P)game_rules.c $(DIR_P)input.c $(DIR_P)push_swap.c\
	$(DIR_P)stack.c $(DIR_C)checker.c

OBJ_C = game_rules.o input.o push_swap.o stack.o sorting_b.o checker.o\
	heuristics.o sorting_b2.o heuristics1.o heuristics2.o sorting_a.o\
	sorting_a2.o paths_for_max.o paths_for_3.o paths_for_1.o

CFLAGS = -Wall -Wextra -Werror

all : $(NAME_2) $(NAME_1)

$(NAME_1) : 
	@gcc -c $(CFLAGS) $(SRC_C)
	@gcc $(OBJ_C) $(CFLAGS) $(DIR_C)main.c libft/libft.a -o $(NAME_1)

$(NAME_2) : 
	@make -C libft
	@gcc -c $(CFLAGS) $(SRC_P)
	@gcc $(OBJ_P) $(CFLAGS) $(DIR_P)main.c libft/libft.a -o $(NAME_2)

clean :
	@make clean -C libft
	@/bin/rm -f $(OBJ_P)
	@/bin/rm -f $(OBJ_C)

fclean : clean
	@make fclean -C libft
	@/bin/rm -f checker
	@/bin/rm -f push_swap

re : fclean all

n :
	#make n -C libft
	norminette -R CheckForbiddenSourceHeader $(SRC_P) $(SRC_C)
	norminette -R CheckForbiddenSourceHeader $(DIR_C)main.c $(DIR_P)main.c
	norminette -R CheckForbiddenSourceHeader $(DIR_P)push_swap.h $(DIR_C)checker.h
