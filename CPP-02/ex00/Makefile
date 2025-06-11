SRC = Fixed.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFALGS = -Wall -Werror -Wextra -std=c++98

NAME = Fixed

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFALGS) $(OBJ) -o $(NAME) 

%.o : %.cpp Fixed.hpp
	c++ $(CPPFALGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all