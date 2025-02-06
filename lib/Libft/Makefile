# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 10:00:18 by nseon             #+#    #+#              #
#    Updated: 2025/01/14 13:46:47 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a

# ---------------FILES--------------- #

MAKE_DIR	=	.make/

SRC_DIR		=	src/

OBJ			=	$(patsubst %.c, $(MAKE_DIR)%.o, $(SRC))

DEP			=	$(patsubst %.c, $(MAKE_DIR)%.d, $(SRC))

# --------------ft_printf------------ #

SRC			=	$(addprefix $(PRINTF_DIR), $(PRINTF_SRC))

PRINTF_DIR	=	ft_printf/

PRINTF_SRC	=	fcts.c\
				fill.c\
				lens.c\
				printf.c

# ---------------GNL----------------- #

SRC			+=	$(addprefix $(GNL_DIR), $(GNL_SRC))

GNL_DIR		=	GetNextLine/

GNL_SRC		=	get_next_line.c\
				get_next_line_utils.c

# ---------------CHAR---------------- #

SRC			+=	$(addprefix $(CHAR_DIR), $(CHAR_SRC))

CHAR_DIR	=	char/

CHAR_SRC	=	ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c

# ----------------STR--------------- #

SRC			+=	$(addprefix $(STR_DIR), $(STR_SRC))

STR_DIR	=	str/

STR_SRC	=	ft_strjoin.c\
			ft_atoi.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_striteri.c\
			ft_strlen.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_strdup.c\
			ft_strnstr.c\
			ft_substr.c\
			ft_strtrim.c

# ---------------MEMORY-------------- #

SRC			+=	$(addprefix $(MEM_DIR), $(MEM_SRC))

MEM_DIR		=	memory/

MEM_SRC		=	ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_calloc.c

# ----------------PUT---------------- #

SRC			+=	$(addprefix $(PUT_DIR), $(PUT_SRC))

PUT_DIR		=	put/

PUT_SRC		=	ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c

# ---------------LIST---------------- #

SRC			+=	$(addprefix $(LST_DIR), $(LST_SRC))

LST_DIR		=	list/

LST_SRC		=	ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c


# -----------LIBS / INCLUDES--------- #

LIB_DIR 	=
LIB_PATH	=
LIB_PATH	:=	$(addprefix $(LIB_DIR), $(LIB_PATH))
LIB			=	$(patsubst lib%a, %, $(notdir $(LIBS_PATH)))

INC_DIR 	=	includes/
INCLUDES	=	$(INC_DIR)\
				$(addsuffix $(INC_DIR), $(dir $(LIB_PATH)))

# --------------CONFIGS-------------- #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-MMD -MP $(addprefix -I, $(INCLUDES))

LDFLAGS		+=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		+=	$(addprefix -l, $(LIB))

# --------------TARGETS-------------- #

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

$(MAKE_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEP)

bonus :
	$(MAKE) SRC="$(SRC_BNS)"

clean :
	rm -rf $(MAKE_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
