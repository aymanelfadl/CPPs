CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = main

# Fixed: updated source file name to match corrected class name
SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all