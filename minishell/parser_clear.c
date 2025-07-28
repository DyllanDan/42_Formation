# include "minishell.h"

char **clear_parser(char **parser)
{
    int i;
    int args;
    char **cleaned;

    i = 0;
    args = 0;
    while(parser[i])
    {
        if (parser[i][0] == '>' || parser[i][0] == '<')
            i++;
        else
        {
            i++;
            args++;
        }
    }
    cleaned = malloc(sizeof(char *) * (args + 1));
    i = 0;
    args = 0;
    while (parser[i])
    {
        if (parser[i][0] == '>' || parser[i][0] == '<')
            i++;
        else
        {
            cleaned[args] = ft_strdup(parser[i]);
            args++;
            i++;
        }
    }
    cleaned[args] = NULL;
    free_tokens(&parser);
    return (cleaned);
}