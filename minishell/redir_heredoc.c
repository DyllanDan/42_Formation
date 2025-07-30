/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:16:16 by dydaniel          #+#    #+#             */
/*   Updated: 2025/07/12 16:16:19 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_redir_herdoc(t_data_val *data, int i)
{
    int j;
    int flag;

    j = 0;
    flag = NO_RD_HD;
    while(data->parser[i][j])
    {
        if (!ft_strncmp(data->parser[i][j], "<<", 3))
        {
            flag = HEREDOC;
            heredoc(data->parser[i][j + 1]);
            j++;
        }
        else if (!ft_strncmp(data->parser[i][j], ">>", 3))
        {
            flag = APPEND;
            change_fd(data, flag, i, j);
            j++;
        }
        else if (!ft_strncmp(data->parser[i][j], "<", 2))
        {
            flag = RD_IN;
            change_fd(data, flag, i, j);
            j++;
        }
        else if (!ft_strncmp(data->parser[i][j], ">", 2))
        {
            flag = RD_OUT;
            change_fd(data, flag, i, j);
            j++;
        }
        j++;
    }
    return (flag);
}

void change_fd(t_data_val *data, int redir_heredoc, int i, int j)
{
    int file_fd;

    file_fd = 0;
    if (!data->parser[i][j + 1])
    {
        ft_printf("Syntax error with abscense of token\n");
        exit (EXIT_FAILURE);
    }
    if (redir_heredoc == RD_OUT)
        file_fd = open(data->parser[i][j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else if (redir_heredoc == RD_IN)
        file_fd = open(data->parser[i][j + 1], O_RDONLY);
    else if (redir_heredoc == APPEND)
        file_fd = open(data->parser[i][j + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file_fd == -1)
    {
        perror(data->parser[i][j + 1]);
        exit(EXIT_FAILURE);
    }
    if (redir_heredoc == RD_OUT || redir_heredoc == APPEND)
        dup2(file_fd, STDOUT_FILENO);
    else if (redir_heredoc == RD_IN)
        dup2(file_fd, STDIN_FILENO);
    close(file_fd);
}


int solo_command_redir_heredoc(char **token, int i)
{
    int flag;
    int file_fd;

    flag = NO_RD_HD;
    while(token[i])
    {
        if (!ft_strncmp(token[i], "<<", 3))
        {
            flag = HEREDOC;
            i++;
        }
        else if (!ft_strncmp(token[i], ">>", 3))
        {
            flag = APPEND;
            file_fd = open(token[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
            i++;
        }
        else if (!ft_strncmp(token[i], "<", 2))
        {
            flag = RD_IN;
            file_fd = open(token[i + 1], O_RDONLY);
            i++;
        }
        else if (!ft_strncmp(token[i], ">", 2))
        {
            flag = RD_OUT;
            file_fd = open(token[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            i++;
        }
        if (flag == RD_OUT || flag == APPEND)
            dup2(file_fd, STDOUT_FILENO);
        else if (flag == RD_IN)
            dup2(file_fd, STDIN_FILENO);
        close(file_fd);
        i++;
    }
    return (flag);
}