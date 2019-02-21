# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:35:03 by kibotrel          #+#    #+#              #
#    Updated: 2019/02/21 16:51:15 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= libft.a

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
INCDIR		= ./incs/

# Source files (Can be changed)

SRC			= ft_putchar.c				ft_putchar_fd.c			\
		  	  ft_putstr.c				ft_putstr_fd.c			\
			  ft_putnbr.c				ft_putnbr_fd.c			\
			  ft_putendl.c				ft_putendl_fd.c			\
			  ft_print_error.c									\
			  													\
			  ft_memset.c				ft_memdel.c				\
			  ft_memcmp.c				ft_memchr.c				\
			  ft_memcpy.c				ft_memccpy.c			\
			  ft_memmove.c										\
			  													\
			  ft_atoi.c					ft_itoa.c				\
			  ft_strdup.c				ft_strlen.c				\
			  ft_strnew.c				ft_strdel.c				\
			  ft_strclr.c				ft_strsplit.c			\
			  ft_bzero.c				ft_strtrim.c			\
			  ft_strlcat.c				ft_memalloc.c			\
			  ft_create_elem.c			ft_itoa_base.c			\
			  													\
			  ft_strstr.c				ft_strnstr.c			\
			  ft_strcmp.c				ft_strncmp.c			\
			  ft_strcpy.c				ft_strncpy.c			\
			  ft_strequ.c				ft_strnequ.c			\
			  ft_strcat.c				ft_strncat.c			\
			  ft_striter.c				ft_striteri.c			\
			  ft_strmap.c				ft_strmapi.c			\
			  ft_strchr.c				ft_strrchr.c			\
			  ft_strjoin.c				ft_strsub.c				\
			  ft_strrev.c				ft_numlen.c				\
			  ft_word_count.c			ft_word_length.c		\
			  													\
			  ft_str_is_uppercase.c		ft_str_is_lowercase.c	\
			  ft_strupcase.c			ft_strlowcase.c			\
			  ft_toupper.c				ft_tolower.c			\
			  ft_isalpha.c				ft_isdigit.c			\
			  ft_isalnum.c				ft_isascii.c			\
			  ft_isprint.c				ft_isspace.c			\
			  													\
			  ft_count_if.c				ft_foreach.c			\
			  ft_is_sort.c				ft_foreach.c			\
			  													\
			  ft_lstnew.c				ft_lstadd.c				\
			  ft_lstdel.c				ft_lstdelone.c			\
			  ft_lstmap.c				ft_lstiter.c			\
			  													\
			  ft_list_at.c				ft_list_size.c			\
			  ft_list_foreach.c			ft_list_foreach_if.c	\
			  ft_list_push_back.c		ft_list_push_front.c	\
			  ft_list_last.c			ft_list_remove_if.c		\
			  ft_list_reverse.c									\
			  													\
			  ft_match.c				ft_nmatch.c				\
			  ft_power.c				ft_fibonacci.c			\
			  ft_is_prime.c				ft_find_next_prime.c	\
			  ft_is_negative.c			ft_sort_int_tab.c		\
			  													\
			  ft_btree_create_node.c	ft_btree_search_item.c	\
			  ft_btree_apply_infix.c	ft_btree_apply_suffix.c	\
			  ft_btree_apply_prefix.c							\
			  													\
			  ft_get_next_line.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
CHECKDIR	= $(shell if [ ! -d "$(OBJDIR)" ]; then	mkdir $(OBJDIR); fi)

# How files should be compiled with set flags (Can be changed)

OBJ			= $(SRC:.c=.o)
CFLAGS		= -I$(INCDIR) -Wall -Wextra -Werror
CC			= gcc

# Build the library when all .c files are compiled into .o files and then indexing it

$(NAME): $(CHECKDIR) $(COBJ)
	@echo "\033[33m\n      - Building \033[0m$(NAME) \033[33m...\n\033[0m"
	@ar rc $(NAME) $(COBJ)
	@echo "\033[33m      - Indexing \033[0m$(NAME) \033[33m...\n\033[0m"
	@ranlib $(NAME)
	@echo "\033[32m***   Project $(NAME) successfully compiled   ***\n\033[0m"

all: $(NAME)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "\033[33m      - Compiling :\033[0m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Deleting all .o files and then the directory where they were located

clean:
	@echo "\033[32m***   Deleting all object files from $(NAME)   ...   ***\n\033[0m"
	@rm -rf $(COBJ)

# Deleting the library after cleaning up all .o files

fclean: clean
	@echo "\033[32m***   Deleting executable file from $(NAME)   ...   ***\n\033[0m"
	@rm -rf $(NAME)

# Delete all .o files then the library and rebuild the whole thing again

re: fclean all

.PHONY: all clean fclean re
