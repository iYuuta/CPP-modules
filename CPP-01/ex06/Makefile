SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -std=c++98

NAME = harlFilter

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Harl.hpp
	c++ $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all