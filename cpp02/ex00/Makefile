NAME = fixed

SRCS = main.cpp Fixed.cpp

CXX = c++

OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(OBJS:%.o=%.d)

CPPFLAGS = -Werror -Wextra -Wall -std=c++98 -MMD # MMD = Make My Dependence

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re