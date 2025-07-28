/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:21:09 by dydaniel          #+#    #+#             */
/*   Updated: 2025/07/12 10:21:11 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void close_unused_fd(t_data_val *data, int i)
{
    int k;

    k = 0;
    while (k < data->num_pipes)
    {
        if (k != i - 1)
            close(data->fd[k][0]);
        if (k != i)
            close(data->fd[k][1]);
        k++;
    }
}

void exec_child_process(t_data_val *data, int i)
{
    int redir_heredoc;

    redir_heredoc = check_redir_herdoc(data, i);
    if (i == 0)
    {
        if (redir_heredoc == NO_RD_HD)
        {
            close(data->fd[0][0]);  // fecha leitura que não usa
            dup2(data->fd[0][1], STDOUT_FILENO);
            close(data->fd[0][1]);
        }
        else
            data->parser[i] = clear_parser(data->parser[i]);
        close_unused_fd(data, i);
    }
    else if (i == data->num_pipes) 
    {
        if (redir_heredoc == NO_RD_HD)
        {
            close(data->fd[i-1][1]); // fecha escrita que não usa
            dup2(data->fd[i-1][0], STDIN_FILENO);                   
            close(data->fd[i-1][0]);
        }
        else
            data->parser[i] = clear_parser(data->parser[i]);
        close_unused_fd(data, i);
    }
    else
    {
        if (redir_heredoc == NO_RD_HD)
        {
            dup2(data->fd[i-1][0], STDIN_FILENO);
            close(data->fd[i-1][0]);
            dup2(data->fd[i][1], STDOUT_FILENO);
            close(data->fd[i][1]);
        }
        else
            data->parser[i] = clear_parser(data->parser[i]);
        close_unused_fd(data, i);
    }
    if (!data->cmd_path)
    {
        ft_printf("command not found: %s\n", data->parser[i][0]);
        exit(127);
    }
    else
    {
        execve(data->cmd_path[i], data->parser[i], data->envp);
    }
    perror("execve falhou");
    exit(EXIT_FAILURE);
}

void exec_one_command(t_data_val *data, int *status)
{
    int i;

    i = 0;
    data->child_pid[0] = fork();
    if (data->child_pid[0] == 0)
    {
        while (data->token[i])
        {
            if (data->token[i][0] == '>' || data->token[i][0] == '<')
            {
                solo_command_redir_heredoc(data->token, i);
                break;
            }
            i++;
        }
        data->token = clear_parser(data->token);
        execve(data->cmd_path[0], data->token, data->envp);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else if (data->child_pid[0] > 0)
        waitpid(data->child_pid[0], status, 0);
    else
        perror("fork");
}