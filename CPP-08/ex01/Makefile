# COLORS

PURPLE			=	\x1b[0m\x1b[38;2;128;0;128m
LIGHT_PURPLE	=	\x1b[0m\x1b[38;2;204;153;255m
DARK_PURPLE		=	\x1b[1m\x1b[38;2;75;0;130m

# PROGRAM NAME
NAME		=	EasyFind

MAKEFLAGS	=	-s
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98

# FILES
FILES		=	main					\
				Span					\

SRC			=	$(addsuffix .cpp, $(FILES))
OBJ			=	$(addsuffix .o, $(FILES))

#RULES
all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(CXX) $(CXXFLAGS) $^ -o $@
				echo -e '$(LIGHT_PURPLE) \tCompiled$(DARK_PURPLE) $@'

clean		:
				$(RM) $(OBJ)
				echo -e '$(LIGHT_PURPLE) \tCleaned$(PURPLE) $(OBJ)'

fclean		:	clean
				$(RM) $(NAME)
				echo -e '$(LIGHT_PURPLE) \tCleaned$(DARK_PURPLE) $(NAME)'

re			:	fclean all

.PHONY		=	all clean fclean re
