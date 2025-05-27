NAME		=	AmazingJob

CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

SRC			=	Account.cpp \
				tests.cpp	\

OBJ 		= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
