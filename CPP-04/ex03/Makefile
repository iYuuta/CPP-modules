SRC = AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAG = -Wall -Wextra -Werror -std=c++98

NAME = AMateria

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAG) $(OBJ) -o $(NAME)

%.o : %.cpp AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Character.hpp
	c++ $(CPPFLAG) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
