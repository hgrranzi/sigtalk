NAME_ONE = sigtalk_server

NAME_TWO = sigtalk_client

COMPILE = gcc -c -Wall -Wextra -Werror

LINK = gcc -Wall -Wextra -Werror

SRCS_ONE = sigtalk_server.c

SRCS_TWO = sigtalk_client.c

OBJS_ONE =	$(SRCS_ONE:.c=.o)

OBJS_TWO =	$(SRCS_TWO:.c=.o)

all: $(NAME_ONE) $(NAME_TWO)

$(NAME_ONE): sigtalk.h $(OBJS_ONE)
	$(LINK) $(OBJS_ONE) -o $(NAME_ONE)

$(NAME_TWO): sigtalk.h $(OBJS_TWO)
	$(LINK) $(OBJS_TWO) -o $(NAME_TWO)

%.o: %.c sigtalk.h
	$(COMPILE) $< -o $@

check: $(NAME_ONE)

sort: $(NAME_TWO)

clean:
	rm -f $(OBJS_ONE) $(OBJS_TWO)

fclean: clean
	rm -f $(NAME_ONE) $(NAME_TWO)

re: fclean all