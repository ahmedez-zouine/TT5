#ifndef MINISHELL_H
#define MINISHELL_H

//---------> Variable <-----------

#define BUFFUER_READ 1000


// ---------> include <------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

//---------------------------------

typedef struct s_command
{
    char *name;
    char **Argm;
    struct s_command *next;
} t_command;

//--------> Helper Function -------

// int	ft_strtrim(char *str);
// char	**ft_split(char *str);
// int	ft_check_input(char *str);
char **ft_split_pipe(char *str, char check);
int ft_strcmp(char *s2, char *s1);




//---------------------------------


#endif
