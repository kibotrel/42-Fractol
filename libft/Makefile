# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:35:03 by kibotrel          #+#    #+#              #
#    Updated: 2019/07/08 11:14:21 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= libft.a

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
INCDIR		= incs/
INCS		= libft.h
OBJSUBDIRS	= control conversion display file memory string

# Source files (Can be changed)

SRC			= display/ft_putchar.c				display/ft_putchar_fd.c			\
		  	  display/ft_putstr.c				display/ft_putstr_fd.c			\
			  display/ft_putnbr.c				display/ft_putnbr_fd.c			\
			  display/ft_putendl.c				display/ft_putendl_fd.c			\
			  display/ft_print_error.c											\
																				\
			  control/ft_isalpha.c				control/ft_isdigit.c			\
			  control/ft_isalnum.c				control/ft_isascii.c			\
			  control/ft_isprint.c				control/ft_isspace.c			\
			  control/ft_charrcount.c			control/ft_charcount.c			\
			  control/ft_str_is_uppercase.c		control/ft_str_is_lowercase.c	\
			  control/ft_strequ.c				control/ft_strnequ.c			\
			  control/ft_strcmp.c				control/ft_strncmp.c			\
			  control/ft_strstr.c				control/ft_strnstr.c			\
			  control/ft_wordcount.c			control/ft_wordlength.c			\
			  control/ft_strlen.c				control/ft_numlen.c				\
			  control/ft_memcmp.c				control/ft_isvalidname.c		\
																				\
			  string/ft_strdup.c				string/ft_strrev.c				\
			  string/ft_strtrim.c				string/ft_strchr.c				\
			  string/ft_strsplit.c				string/ft_strjoin.c				\
			  string/ft_strcat.c				string/ft_strncat.c				\
			  string/ft_strcpy.c				string/ft_strncpy.c				\
			  string/ft_strsub.c												\
																				\
			  conversion/ft_strupcase.c			conversion/ft_strlowcase.c		\
			  conversion/ft_toupper.c			conversion/ft_tolower.c			\
			  conversion/ft_itoa.c				conversion/ft_itoa_base.c		\
			  conversion/ft_atoi.c												\
																				\
			  memory/ft_memalloc.c				memory/ft_bzero.c				\
			  memory/ft_memchr.c				memory/ft_memcpy.c				\
			  memory/ft_memccpy.c				memory/ft_memmove.c				\
			  memory/ft_memset.c				memory/ft_strnew.c				\
																				\
			  file/ft_get_next_line.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
HEADERS		= $(foreach header, $(INCS), $(INCDIR)$(header))
SUBDIRS		= $(foreach dir, $(OBJSUBDIRS), $(OBJDIR)$(dir))
INCLUDES	= $(foreach include, $(INCDIR), -I./$(include))

# How files should be compiled with set flags (Can be changed)

CC			= gcc
OBJ			= $(SRC:.c=.o)
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror

# Rule called upon 'make'

all: $(SUBDIRS) $(NAME)

# Tries to create all subdirectories in objs

$(SUBDIRS):
	@mkdir -p $(SUBDIRS)

# Build the library when all .c files are compiled into .o files and then indexing it

$(NAME): $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@ar rcs $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Tries to create objs directory

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Deleting all .o files and then the directory where they were located

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(COBJ)

# Deleting the library after cleaning up all .o files

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Delete all .o files then the library and rebuild the whole thing again

re: fclean all

.PHONY: all clean fclean re
