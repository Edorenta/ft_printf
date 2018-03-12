# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 02:57:04 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/03 00:07:21 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libftprintf.a
MKDIR_P		= mkdir -p
SRC_PATH	= srcs/
OBJ_PATH	= objs/
FLAGS		= -g -Wextra -Wall -Wpedantic
CC			= gcc $(FLAGS)
SRC_SUFFIX	= .c
#SRC_PREFIX	= 
SRC_RAW		=	ft_printf			conv_picker				get_flags			\
				get_digits			get_digits2				io_str				\
				io_nbr				io_nbr_base				io_nbr_base2		\
				utilities			unicode					mod_b				\
				mod_cs				mod_d					mod_h				\
				mod_hh				mod_j					mod_l				\
				mod_ll				mod_z					print_plain			\
				print_plain2		print_j					print_l				\
				print_z

#SRC_RAW2	= $(addprefix ${SRC_PREFIX},${SRC_RAW})
SRC_FILES	= $(addsuffix $(SRC_SUFFIX),$(SRC_RAW))
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRC			= $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_FILES))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib	$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@${MKDIR_P} $(OBJ_PATH)
	$(CC) -I./include -o $@ -c $<

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

norm :
	@norminette srcs/ include/

.PHONY: all clean fclean re norm
