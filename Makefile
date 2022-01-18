NAME = ft_containers
CXX = clang++ -Wall -Werror -Wextra
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) 1 2
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
