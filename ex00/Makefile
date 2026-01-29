CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Bureaucrat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
