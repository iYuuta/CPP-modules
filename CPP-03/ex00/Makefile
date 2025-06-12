SRC = ClapTrap.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAG = -Wall -Wextra -Werror -std=c++98

NAME = ClapTrap

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAG) $(OBJ) -o $(NAME)

%.o : %.cpp ClapTrap.hpp
	c++ $(CPPFLAG) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all