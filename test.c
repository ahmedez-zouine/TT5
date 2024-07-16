#include <unistd.h>
#include <stdio.h>
int	main()
{
	char *argv[] = {"ls", "-a", "-l", NULL};
	if (execve(argv[0], argv, NULL) == -1)
		printf("ERROR");
	return (0);
}
