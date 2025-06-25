SRC = converter.cpp main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

CPPflags = -Wall -Werror -Wextra -std=c++98

NAME = converter

%.o : %.cpp
	c++ $(CPPflags) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) ScalarConverter.hpp
	c++ $(CPPflags) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all