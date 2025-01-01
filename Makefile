NAME = libftprintf.a

FT_PRINTF_SRC = $(wildcard *.c) 

SRC = $(FT_PRINTF_SRC)

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM)

fclean: clean
	$(RM) $(NAME)
	$(RM)

re: fclean all

.PHONY: all clean fclean re