NAME = Checker
#NAME2 = push_swap

libft = ./libft/libft.a

SRCS = ./checker/checker.c ./utils/operations.c ./utils/utils.c $(libft)
#SRCS2 = push_swap.c operations.c utils.c $(libft)

OBJECTS = $(SRCS:.c=.o)

all : $(NAME) $(NAME2)

$(NAME) : $(libft) $(SRCS)
	gcc -Wall -Werror -Wextra -g $(SRCS) -o $(NAME)

#$(NAME2) : $(libft) $(SRCS2)
#	@gcc -Wall -Werror -Wextra $(SRCS2) -o $(NAME2)
#	@stty -ctlecho

$(libft) :
	@make -C libft/
	@make clean -C libft/

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	make re -C libft/
.phony : all clean fclean re
