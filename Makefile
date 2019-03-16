# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 22:15:45 by kibotrel          #+#    #+#              #
#    Updated: 2019/03/16 06:09:49 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= fractol

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
MLXDIR		= /usr/local/lib/
INCDIR		= ./incs/ ./libft/incs/

# Source files (Can be changed)

SRC			= main.c			setup.c				\
			  hud.c									\
													\
			  infos_colors.c						\
													\
			  mandelbrot.c		julia.c				\
			  burning_ship.c	burning_julia.c		\
													\
			  colorset.c		preset.c			\
			  color.c			image.c				\
													\
			  selector.c		hooks.c				\
			  process_input.c	process_input2.c	\
													\
			  utils.c			utils2.c			\
			  maths.c

LFT			= ./libft/libft.a

TOOLS		= OpenGL AppKit

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
INCLUDES	= $(foreach include, $(INCDIR), -I$(include))
FRAMEWORKS	= $(foreach framework, $(TOOLS), -framework $(framework))

# How files should be compiled with set flags (Can be changed)

CC			= gcc
OBJ			= $(SRC:.c=.o)
LIBS		= -L$(LFTDIR) -lft -L$(MLXDIR) -lmlx
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all: $(NAME)

$(NAME): $(LFT) $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) $(LIBS) $(FRAMEWORKS) -o $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library "libft"

$(LFT):
	@make -sC $(LFTDIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(COBJ)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFTDIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
