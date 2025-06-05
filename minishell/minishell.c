/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:54:54 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/24 16:54:56 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void show_envp(char **envp) //mostra as variaveis de ambiente
{
    int i;
    int j;

    i = 0;
    while(envp[i])
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


int ft_isspace(char c)
{
    if (c== '\r' || c == '\t' || c == '\f' || \
				c == '\n' || c== ' ' || c == '\v')
                return (1);
    else
        return (0);
}

void a_comma(int *j, char *text, int *i)//função que verifica aspas no par, avança i até a próxima aspas e faz j++, caso
//contrário j = -1 indicando erro
{
    while(text[*i])
    {
        if (text[*i] == '"')
        {
            (*j)++;
            return ;
        }
        (*i)++;
    }
    (*j) = -1;
}

int num_tokens(char *text) // calcular quantidade de termos para mallocar certinho
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (text[i])
    {
        //check space_char...char_space
        while (ft_isspace(text[i]))
            i++;
        if (!ft_isspace(text[0]) && text[0] != '"')
            j++;
        //check aspas
        if (text[i] == '"')
        {
            i++;
            a_comma(&j, text, &i);
            if (j == -1)
                return (-1);
        }
        if (i != 0 && text[0] != '"' && ft_isspace(text[i - 1]) && !ft_isspace(text[i]))
            j++;
        i++;
    }
    return (j);
}

void divide_arguments(char **token, char *text)//função para separar os espaços *e outras veriicações*
{
    int num_tk;

    (void)token;
    //checar LETRAS MAIUSCULAS, o shell interpreta de uma forma
    num_tk = num_tokens(text);
    if (num_tk == -1)
        ft_printf ("ERROR, open comma!\n");
}

void    recive_inputs(char **argv, char **envp)// função para receber continuamente os inputs
{
    char    *text;
    char    **token;// variavel que vai armazenar os tokens, vai ser um array de strings

    (void)envp;
    (void)argv;
    (void)token;
    while (1)
    {
        text = readline("abc>>");
        divide_arguments(token, text);
        if (text[0] == 'x')
        {
            free(text);
            break ;
        }
        free(text);
    }
}

//char **envp são variaveis de ambiente, é um array de strings com informações gerais do SHELL
int main(int argc, char **argv, char **envp)
{
    argc = 0;
    recive_inputs(argv, envp);
    ft_printf("\n");
    return (0);
}