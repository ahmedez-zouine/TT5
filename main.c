#include "minishell.h"

int main()
{
	char *string;
	char **Array;
	int i = 0;

	while (1)
	{
		string = readline("minishell: ");
		if (string == NULL)
			break;
		Array = ft_split_pipe(string, '|');
		i = 0;
		if (execve(Array[0], Array, NULL) == -1)
			printf("Error execve");
		while (Array[i])
			printf("%s\n",Array[i++]);
		
	}
}
