# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 22:15:45 by kibotrel          #+#    #+#              #
#    Updated: 2019/04/01 15:49:16 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= fractol

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
OBJSUBDIRS	= usage events fractals hud setup parsing utils maths core menu hooks
SRCDIR		= srcs/
LFTDIR		= libft/
MLXDIR		= /usr/local/lib/
INCDIR		= ./incs/ ./libft/incs/

# Source files (Can be changed)

SRC			= core/main.c					core/selector.c				\
			  core/threads.c											\
																		\
			  parsing/parsing.c											\
																		\
			  setup/setup.c					setup/color_preset.c		\
			  setup/set_checks.c			setup/set_bounds.c			\
			  setup/set_menu_params.c		setup/set_fractal_params.c	\
																		\
			  fractals/mandelbrot.c			fractals/julia.c			\
			  fractals/burning_ship.c		fractals/burning_julia.c	\
			  fractals/sierpinski.c			fractals/koch.c				\
			  fractals/barnsley.c			fractals/flower.c			\
																		\
			  events/change_fractal.c 		events/change_sound.c		\
			  events/update_colors.c		events/shift_palettes.c		\
			  events/offset.c				events/details.c			\
			  events/reset.c				events/psycho_effect.c		\
			  events/quit.c					events/zoom.c				\
																		\
			  maths/complex.c				maths/normalize.c			\
			  maths/update_bounds.c			maths/ratio.c				\
			  maths/functions.c											\
																		\
			  utils/draw_line.c				utils/image.c				\
			  utils/color.c					utils/clean.c				\
			  utils/selected_settings.c									\
																		\
			  hud/hud.c						hud/infos_colors.c			\
			  hud/infos_controls.c			hud/infos_complex.c			\
			  hud/infos_zoom.c				hud/fractal_name.c			\
																		\
			  menu/menu.c					menu/infos_menu.c			\
			  menu/animations_menu.c		menu/interactions_menu.c	\
			  menu/hover_settings.c			menu/click_settings.c		\
																		\
			  usage/usage.c												\
																		\
			  hooks/hooks.c					hooks/fractal_hooks.c		\
			  hooks/menu_hooks.c

LFT			= ./libft/libft.a

TOOLS		= OpenGL AppKit

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
SUBDIRS		= $(foreach dir, $(OBJSUBDIRS), $(OBJDIR)$(dir))
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

all: $(SUBDIRS) $(NAME)

$(NAME): $(LFT) $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) $(LIBS) $(FRAMEWORKS) -o $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(SUBDIRS):
	@mkdir -p $(SUBDIRS)
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
