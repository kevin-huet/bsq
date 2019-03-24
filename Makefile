##
## EPITECH PROJECT, 2018
## f
## File description:
## f
##

NAME	= bsq

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./check_number.c \
	  ./square.c \
	  ./small_size.c \
	  ./my_getnbr.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I 
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
