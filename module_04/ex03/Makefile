CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Game

SRCS = main00.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp \
	   MateriaSource.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all