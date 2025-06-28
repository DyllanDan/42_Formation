/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:20:08 by dydaniel          #+#    #+#             */
/*   Updated: 2025/06/03 20:20:10 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
#include <readline/history.h>
# include "ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>     
#include <sys/types.h> 
#include <sys/wait.h>  

/* Estrutura para armazenar dados
fd[2] -> usado no pipe. Necessário para exercutar comando de |
text -> input do terminal
token -> tokenização do texto
path -> caminho absoluto do comando, quando existir
child_pid -> pid do processo filho

*/
typedef struct s_data_val
{
    int argc;
    char **envp;
    int **fd;
    char *text;
    char **token;
    char ***parser;
    char *path;
    char *envp_path;
    int num_pipes;
    pid_t *child_pid;
}   t_data_val;


size_t	ft_strlcpy(char *dest, const char *src, size_t size);
long	ft_atoi_base(const char *nptr, int base);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
int ft_isspace(char c);
void    configure_signal();
void    handle_ctrlc(int sig);
void divide_arguments(char ***token, char *text);
int num_tokens(char *text);
void free_tokens(char ***token);
void populate_token(char **token, char *text);
int size_of_str(char *text);
int a_comma(char *c, char c_text);
char *check_path(char **token, char **envp);
void exc_command(t_data_val *data);
//remove
void print_tokens(char **token);
void parse_token(t_data_val **data);
#endif
