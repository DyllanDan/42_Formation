/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:54:54 by dydaniel          #+#    #+#             */
/*   Updated: 2025/06/16 20:16:05 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"  

void print_tokens(char **token)
{
    int i;

    i = 0;
    while(token[i])
    {
        printf("token %i: %s\n", i, token[i]);
        i++;
    }
}

void show_envp(char **envp)
{
    int i;  
    int j;  

    i = 0;
    while (envp[i])  
    {
        j = 0;
        while (envp[i][j]) 
        {
            ft_printf("%c", envp[i][j]);  
            j++;
        }
        ft_printf("\n"); 
        i++;
    }
}

int a_comma(char *c, char c_text)
{
    if (c_text == '"' || c_text == '\'')
    {
        *c = c_text;
        return (1);
    }
    else
        return (0);
}

void recive_inputs(t_data_val *data)
{
    while (1) 
    {
        data->text = readline("abc>>");  
        if (data->text == NULL)
        {
            write(STDOUT_FILENO, "exit\n", 5);
            break;
        }
        if (data->text != NULL &&  num_tokens(data->text) > 0)
            add_history(data->text);
        if (strcmp(data->text, "exit") == 0)  
        {
            rl_clear_history();
            free(data->text);
            break;       
        }
        divide_arguments(&data->token, data->text);// faz a tokenização
        data->path = check_path(data->token, data->envp);// pega o caminho absoluto se existir
        print_tokens(data->token);// visualização dos tokens individuais
        if (pipe(data->fd) == -1)// NOVO, NECESSÁRIO PARA TRATAR O PIPE
            return ;
        data->child_pid = fork();// cria processo filho
        exc_command(data);// executa o comando
        free(data->text);
        free_tokens(&data->token);
    }
}

//inicia e atribui valores da estrutura para enviar para 
//o resto do programa
void init_data(t_data_val **data, char **envp, int *fd)
{
    (*data)->envp = envp;
    (*data)->fd[0] = fd[0];
    (*data)->fd[1] = fd[1];
    (*data)->path = NULL;
    (*data)->text = NULL;
    (*data)->token = NULL;
    (*data)->child_pid = 0;
}

int main(int argc, char **argv, char **envp)
{
    t_data_val *data;
    int fd[2];

    (void)argc;  
    (void)argv;
    data = malloc(sizeof(t_data_val));
    if (!data)
        return (0);
    init_data(&data, envp, fd);//inicia a estrutura  
    configure_signal();
    recive_inputs(data);
    return (0); 
}
