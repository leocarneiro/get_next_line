TARGETS	=	gnl

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -g

all: clean $(TARGETS)

$(TARGETS):
	$(CC) $(FLAGS) get_next_line.c get_next_line_utils.c main.c -o gnl

clean:
	rm -f $(TARGETS)
