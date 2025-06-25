SRC = main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)

CPPflags = -Wall -Wextra -Werror -std=c++98

NAME = converter

%.o : %.cpp
	c++ $(CPPflags) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) Serializer.hpp Data.hpp
	c++ $(CPPflags) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all