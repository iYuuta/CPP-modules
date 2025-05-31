SRC = Contact.cpp PhoneBook.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = PhoneBook

CPPflags = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPflags) $(OBJ) -o $(NAME)

%.o : %.cpp PhoneBook.hpp Contact.hpp
	c++ $(CPPflags) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all