/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:58:11 by dydaniel          #+#    #+#             */
/*   Updated: 2025/07/05 17:42:24 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_command(t_data_val *data)
{
   divide_arguments(&data->token, data->text);
    if (execute_builtin(data))
    {
        free_tokens(&data->token);
        free(data->fd);
        return;
    }
    exc_command(data);
    free_tokens(&data->token);
    free(data->fd); 
}

char *check_path(char **token, char **envp)
{
    char *path_env;
    char **splitted_path;
    char *aux;
    char *full_path;
    int i;

    i = 0;
    (void)envp;
    path_env = getenv("PATH");//Pega os caminhos
    splitted_path = ft_split(path_env, ':');//Separa cada caminho
    while(splitted_path[i])//Percorre os caminhos
    {
        aux = ft_strjoin(splitted_path[i], "/");
        full_path = ft_strjoin(aux, token[0]);//Adiciona o comando no caminho
        free(aux);
        if (access(full_path, X_OK) == 0)//verifica se é executavel e retorna o caminho
            return (full_path);
        free(full_path);
        i++;
    }
    return (NULL);
}

//Executa o comando, os comentados são o inicio do tratamento do pipe
void exc_command(t_data_val *data)
{
    int i;

    i = 0;
    parse_token(&data);
    data->child_pid = malloc(sizeof(pid_t) * (data->num_pipes + 1));
    if (!data->child_pid)
        ft_printf("ERROR\n");
    if (data->parser)
    {
        while (i <= data->num_pipes)
        {
            data->child_pid[i] = fork();
            if (data->child_pid[i] < 0)
                ft_printf("ERROR ON CREATING CHILD PROCESS!\n");
            else if (data->child_pid[i] == 0)
                ft_printf("PASS COMAND!");
            i++;
        }
    }
    else
    {
         //excev(token)
    }
       
}
/*if (i == 0) {
    // Primeiro processo: só redireciona stdout para fd[0][1]
    close(fd[i][0]);  // fecha leitura que não usa
    dup2(fd[i][1], STDOUT_FILENO);
    close(fd[i][1]);
}
else if (i == data->num_pipes) {
    // Último processo: redireciona stdin para fd[i-1][0]
    close(fd[i-1][1]); // fecha escrita que não usa
    dup2(fd[i-1][0], STDIN_FILENO);
    close(fd[i-1][0]);
}
else {
    // Processo intermediário: redireciona stdin e stdout
    close(fd[i-1][1]); // fecha escrita do pipe anterior
    dup2(fd[i-1][0], STDIN_FILENO);
    close(fd[i-1][0]);

    close(fd[i][0]); // fecha leitura do pipe atual
    dup2(fd[i][1], STDOUT_FILENO);
    close(fd[i][1]);
}*/