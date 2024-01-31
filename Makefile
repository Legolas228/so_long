# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pborrull <pborrull@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 09:12:18 by pborrull          #+#    #+#              #
#    Updated: 2024/01/16 10:02:55 by pborrull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
MAGENTA = \033[1;35m
BLUE = \033[38;5;75m

CFLAGS := -Wall -Werror -Wextra -MMD

SOURCE := so_long.c error_checker.c map.c exit.c graphics.c mov.c

OBJS :=  $(SOURCE:.c=.o)

DEPS = $(SOURCE:.c=.d)

LIBRARY := -L ./libx -lmlx -L ./libft -lft -framework OpenGL -framework AppKit 

MINILIBX := libx/

LIBFT := libft/

.SILENT:

all: 
	@make -C $(LIBFT) 
	@make $(NAME) 

$(NAME): $(OBJS)  Makefile so_long.h 
	@make -C $(MINILIBX) > /dev/null
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
	@echo  "$(GREEN)[OK]       $(YELLOW)All Compiled"

%.o: %.c 
	@$(CC) -c  $(CFLAGS) $< -o $@
	@echo "$(GREEN)[OK]       $(CYAN)Compiled"

clean:
		@rm -f $(OBJS) $(DEPS)
		@make clean -C $(MINILIBX) > /dev/null
		@make clean -C $(LIBFT) > /dev/null
		@echo "$(RED)[OK]       $(BLUE)All Clean"

fclean: clean
		@rm -f $(OBJS) $(DEPS) 
		@make clean -C $(MINILIBX) > /dev/null
		@make fclean -C $(LIBFT) > /dev/null
		@rm -f $(NAME)
		@echo  "$(RED)[OK]       $(MAGENTA)All Very Clean"

re: fclean all

-include $(DEPS)

.PHONY: all make clean fclean re
