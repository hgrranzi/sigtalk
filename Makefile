NAME_ONE = sigtalk_server

NAME_TWO = sigtalk_client

COMPILE = clang -c -Wall -Wextra -Werror

LINK = clang -Wall -Wextra -Werror

SRCS_ONE = sigtalk_server.c sigtalk_utils.c

SRCS_TWO = sigtalk_client.c sigtalk_utils.c

OBJS_ONE =	$(SRCS_ONE:.c=.o)

OBJS_TWO =	$(SRCS_TWO:.c=.o)

all: $(NAME_ONE) $(NAME_TWO)

$(NAME_ONE): sigtalk.h $(OBJS_ONE)
	$(LINK) $(OBJS_ONE) -o $(NAME_ONE)

$(NAME_TWO): sigtalk.h $(OBJS_TWO)
	$(LINK) $(OBJS_TWO) -o $(NAME_TWO)

%.o: %.c sigtalk.h
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJS_ONE) $(OBJS_TWO)

fclean: clean
	rm -f $(NAME_ONE) $(NAME_TWO)

re: fclean all
