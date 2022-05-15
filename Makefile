# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:29:08 by anfreire          #+#    #+#              #
#    Updated: 2022/05/14 17:55:09 by anfreire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
LIBFT			= libft
LIBFT_LIB		= libft.a
FT_PRINTF		= ft_printf 
FT_PRINTF_LIB 	= ft_printf.a

SRCS		= main.c \
			  mlx_n_img.c \
			  hooks.c \
			  errors.c \
			  map_checker.c \
			  get_next_line.c \
			  ft_printf.c \
			  utils1.c \
			  utils2.c



OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -L./libft -lft -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus