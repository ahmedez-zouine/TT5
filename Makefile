CC=cc
SRC= utils_string.c main.c 
OBS = $(SRC:.c=.o) 
NAME = minishell
CFLAGS= -Wall -Wextra -lreadline

all: $(NAME)

$(NAME): $(OBS)
	$(CC) $(CFLAGS) $(OBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f $(OBS)

fclean: clean
	$(RM) -f $(NAME)