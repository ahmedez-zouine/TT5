#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <stdlib.h>
int main()
{
	char *input;

	input = readline("minishell: ");
	printf("%s\n", input);

	return (0);
}
