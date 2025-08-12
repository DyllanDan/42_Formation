/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:35:13 by helde-so          #+#    #+#             */
/*   Updated: 2025/07/26 12:04:51 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_builtin(char *cmd)
{
    int flag_builtin;

    flag_builtin = NO_BUILTIN;
    if (!ft_strcmp(cmd, "cd"))
        flag_builtin = CD;
    else if (!ft_strcmp(cmd, "echo"))
        flag_builtin = ECHO;
    else if (!ft_strcmp(cmd, "export"))
        flag_builtin = EXPORT;
    else if (!ft_strcmp(cmd, "pwd"))
        flag_builtin = PWD;
    else if (!ft_strcmp(cmd, "env"))
        flag_builtin = ENV;        
    else if (!ft_strcmp(cmd, "unset"))
        flag_builtin = UNSET;
    else if (!ft_strcmp(cmd, "exit"))
        flag_builtin = EXIT;
    return (flag_builtin);
}

int builtin_pack_1(t_data_val *data, char **token, int flag)
{
    if(flag == PWD)
    {
        ft_pwd();
        return (1); 
    }
    if(flag == ENV)
    {
        ft_env(data, token);
        return (1);
    }
    if (flag == ECHO)
    {
        ft_echo(data, token);
        return (1);
    }
    if(flag == CD)
    {
        g_exit_status = analize_cd_arguments(data, token);
        return (1);
    }
    return (0);
}
int builtin_pack_2(t_data_val *data, char **token, int flag)
{
    if (flag == UNSET)
    {
        ft_unset_args(token, data); // executa unset para todos os args
        return (1); 
    }
    if (flag == EXPORT)
    {
		g_exit_status = ft_export(token, data);
        return (1);
    }
    return (0);
}


int execute_builtin(t_data_val *data, char **token) //identifica se é um builtin e executa ele se for.
{
    int j;
    int flag;

    j = 0;
    flag = check_builtin(token[0]);
    if (flag == EXIT)
        return (ft_exit(token));
    else if (builtin_pack_1(data, token, flag) || builtin_pack_2(data, token, flag))
        return (1);
    return (0);
}

//mensagem de permissão
int ft_exit(char **parser_i)
{
    int exit_code;

    if (parser_i[2])
    {
        ft_printf("exit\n");
        ft_printf("minishell: exit: too many arguments\n");
        return (1);
    }
    else if (parser_i[1])
    {
        if (ft_isnumeric(parser_i[1]))
        {
            exit_code = ft_atoi_base(parser_i[1], 10);
            exit(exit_code);
        }
        else
        {
            ft_printf("exit\n");
            ft_printf("exit: %s: numeric argument required\n", parser_i[1]);
            exit(255);
        }
    }
    exit(0);
    return (0);
}

/*void ft_pwd(t_data_val *data)
{
    char cwd[1024];
    (void)data;
    if(getcwd(cwd, sizeof(cwd)) == NULL)
    {
        ft_printf("pwd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n");
        return;
    }
    ft_putstr_fd(cwd, 1);
    ft_putstr_fd("\n", 1);
}*/

void ft_env(t_data_val *data, char **token)
{
    int i;

    i = 0;
    if (token[1])
    {
        ft_putstr_fd("env: ", 2);
        ft_putstr_fd(token[1], 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        data->last_exit = 127;         
        return;
    }
    printf("aqui\n");
    while (data->envp[i])
    {
        ft_printf("%s\n", data->envp[i]);
        i++;
    }
    data->last_exit = 0; 
}

char *get_env_value(char *name, char **envp)
{
	int     i;
	size_t  len;

	len = ft_strlen(name);//calcula o tamanho da variavel
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], name, len) && envp[i][len] == '=')
			return (envp[i] + len + 1); // pula o "NAME=" e retorna valor
		i++;
	}
	return ("");
}





