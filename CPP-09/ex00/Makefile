SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = #-Wall -Wextra -Werror -std=c++98

NAME = btc

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp BitcoinExchange.hpp
	c++ $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all