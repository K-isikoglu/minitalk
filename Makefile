.PHONY: all server client clean fclean make-libft re

NAME = server
NAME2 = client
OBJECTS = $(SRCS:.c=.o)
OBJECTS2 = $(SRCS2:.c=.o)

SRCS := server.c
SRCS2 := client.c

all: make-libft $(NAME) $(NAME2)

make-libft:
	@bash -c "make -s -C libft"

$(NAME): $(OBJECTS)
	@cc $(OBJECTS) libft/libft.a -o $(NAME)

$(NAME2): $(OBJECTS2)
	@cc $(OBJECTS2) libft/libft.a -o $(NAME2)

$(OBJECTS): $(SRCS)
	@cc -c $^ -Wall -Wextra -Werror

$(OBJECTS2): $(SRCS2)
	@cc -c $^ -Wall -Wextra -Werror

clean:
	@rm -f $(OBJECTS) $(OBJECTS2)

fclean: clean
	@rm -f $(NAME) $(NAME2)

re: fclean all
