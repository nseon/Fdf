# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 10:00:18 by nseon             #+#    #+#              #
#    Updated: 2025/02/12 16:10:08 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fdf

# ---------------FILES--------------- #

MAKE_DIR	=	.make/

SRC_DIR		=	src/

OBJ			=	$(patsubst %.c, $(MAKE_DIR)%.o, $(SRC))

DEP			=	$(patsubst %.c, $(MAKE_DIR)%.d, $(SRC))

# ---------------MAIN---------------- #

SRC			=	fdf.c\

# ---------------DRAW---------------- #

SRC			+=	$(addprefix $(DRW_DIR), $(DRW_SRC))

DRW_SRC		=	draw_line.c\
				draw_map.c

DRW_DIR		=	draw/

# -------------PARSING--------------- #

SRC			+=	$(addprefix $(PRS_DIR), $(PRS_SRC))

PRS_SRC		=	parsing.c

PRS_DIR		=	parsing/

# ---------------ZOOM---------------- #

SRC			+=	$(addprefix $(ZOO_DIR), $(ZOO_SRC))

ZOO_SRC		=	spacing.c

ZOO_DIR		=	zoom/

# -----------LIBS / INCLUDES--------- #

LIB_DIR 	=	lib/
LIB_PATH	=	Libft/libft.a\
				minilibx-linux/libmlx.a
LIB_PATH	:=	$(addprefix $(LIB_DIR), $(LIB_PATH))
LIB			=	$(patsubst lib%.a, %, $(notdir $(LIB_PATH)))

INC_DIR 	=	includes/
INCLUDES	=	$(INC_DIR)\
				$(addsuffix $(INC_DIR), $(dir $(LIB_PATH)))

# --------------CONFIGS-------------- #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-MMD -MP $(addprefix -I, $(INCLUDES))

LDFLAGS		+=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		+=	$(addprefix -l, $(LIB)) -lXext -lX11

# --------------TARGETS-------------- #

.PHONY: all
all: $(NAME)

$(NAME): $(LIB_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(MAKE_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB_PATH): force
	$(MAKE) -C $(@D)

.PHONY: norminette
norminette:
	norminette $(INC_DIR) $(SRC_DIR) lib/Libft

.PHONY: clean
clean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(NAME) $(MAKE_DIR)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: force
force:

-include $(DEP)

.DEFAULT_GOAL := all
