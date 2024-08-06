CC			=	cc
NAME		=	minishell
CFLAGS		=	-Wall -Wextra -Werror
LIBRARY		=	-lreadline
LDFLAGS		=	"-L/Users/$(USER)/.brew/opt/readline/lib"
CPPFLAGS	=	"-I/Users/$(USER)/.brew/opt/readline/include"

SRC			=	ft_fill_token.c ft_parsing.c ft_parsing2.c\
				ft_split.c ft_strtrim.c main.c tools1.c\
				tools2.c tools3.c\

OBJS		=	$(SRC:.c=.o)

all			=	$(NAME)

$(NAME)		:	$(OBJS)
			@$(CC) $(LIBRARY) $(LDFLAGS) $(CPPFLAGS) $(FLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c minishell.h
			@$(CC)  $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) -c $< -o $@

clean		:
			@rm -f $(OBJS)

fclean		:	clean
			@rm -f $(NAME)

re			: fclean all

.PHONY		:	clean