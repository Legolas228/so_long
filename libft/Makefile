# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 13:23:13 by pborrull          #+#    #+#              #
#    Updated: 2024/01/16 10:05:18 by pborrull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
MAGENTA = \033[1;35m
BLUE = \033[38;5;75m

SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c  ft_atoi.c \
  	ft_strdup.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c get_next_line.c \
	get_next_line_utils.c printf/ft_printf_i.c printf/ft_printf_p.c \
	printf/ft_printf.c printf/ft_extra.c printf/ft_printf_x.c \
	printf/ft_printf_xx.c printf/ft_printf_s.c printf/ft_printf_u.c

OBJECTS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

INCLUDES = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

all: $(NAME)
	make -C printf/

$(NAME): $(OBJECTS) Makefile libft.h
	@$(AR) -rcs $@ $(OBJECTS)

%.o: %.c $(INCLUDES) 
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "$(GREEN)[OK]       $(CYAN)Compiled"

clean:
	@make clean -C printf/ > /dev/null
	@rm -f $(OBJECTS) $(DEPS) 
	@echo "$(RED)[OK]       $(BLUE)All Clean"

fclean: clean
	@make fclean -C printf/ > /dev/null
	@rm -f $(OBJECTS) $(DEPS) $(NAME) libft.h.gch
	@echo  "$(RED)[OK]       $(MAGENTA)All Very Clean"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
