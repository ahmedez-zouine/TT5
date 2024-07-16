#include "minishell.h"

int ft_isspace(char c, char check)
{
    return (c == check);
}

// int check_ddq(char *str, int i)
// {
//     while (str[i] && str[i] != "\"")
//         i++;
//     return (i);
// }

int get_count_word(char *str, char check)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i]  && ft_isspace(str[i], check))
            i++;
        if (str[i])
            count++;
        while (str[i] && !ft_isspace(str[i], check))
            i++;
    }
    return (count);
}

char *ft_create_word(char *str,int i, char check)
{
    int j = 0;
    char *word;

    while (str[i] != check && str[i])
    {
        j++;
        i++;
    }
    word = (char *)malloc(j + 1);
    if (!word)
        return (NULL);
    i -= j;
    j = 0;
    while (str[i] && str[i] != check)
    {
        word[j] = str[i];
        j++;
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split_pipe(char *str, char check)
{
    int i;
    int j;
    int size;

    char **tab;
    j = 0;
    i =0;
    size = get_count_word(str, check);
    tab = (char **)malloc(sizeof(char *) * size + 1);
    if (!tab)
        return (NULL);
    while (str[i])
    {
        while (str[i] && ft_isspace(str[i], check))
            i++;
        if (str[i])
            tab[j++] = ft_create_word(str, i, check);
        while (str[i] && !ft_isspace(str[i], check))
            i++;
    }
    tab[j] = NULL;
    return (tab);
}

int ft_strcmp(char *s2, char *s1)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (0);
        s1++;
        s2++;
    }
    return (*s1 == *s2);
}

// int main(int argc, char *argv[])
// {
//     char c = '|';
//     char *string = "Hello | from me | m m";
//     printf("%d\n",get_count_word(string, c));
//     printf("----------------------------\n");
//     char **words = ft_split_pipe(string, '|');
//     int i = 0;
//     while (words[i] != NULL)
//         printf("word %d --> %s\n",i, words[i++]);
// }
