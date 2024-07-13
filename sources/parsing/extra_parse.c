/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:55:10 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/09 19:17:02 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

int     semicolon_checker(token_ptr tokens_list)
{
    token_ptr   tmp;
    
    tmp = tokens_list;
    while (tmp)
    {
        if (ft_strchr(tmp->token, ';') != NULL && tmp->token_type != 3)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token `;'\n", 2);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int     backslash_checker(token_ptr tokens_list)
{
    token_ptr   tmp;
    
    tmp = tokens_list;
    while (tmp)
    {
        if (ft_strchr(tmp->token, '\\') != NULL)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token `\\'\n", 2);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
/*
int     parentheses_checker2(token_ptr tokens_list)
{
    token_ptr   tmp;
    
    tmp = tokens_list;
    while (tmp)
    {
        if (ft_strchr(tmp->token, '(') != NULL && tmp->token_type != 3)
        {
            
        }
    
        tmp = tmp->next;
    }
    return 0;
}*/

int		parentheses_checker(token_ptr tokens_list)
{
	token_ptr	tmp;
	int			open;
	int			close;

	tmp = tokens_list;
	open = 0;
	close = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->token, '(') != NULL && tmp->token_type != 3)
			open++;
		if (ft_strchr(tmp->token, ')') != NULL && tmp->token_type != 3)
			close++;
		tmp = tmp->next;
	}
	if (open != close)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `('\n", 2);
		return 1;
	}
	return 0;
}
int     ft_env_search(char *tmp, char **envp)
{
    int i;
    int j;

    i = 0;
    while (envp[i])
    {
        j = 1;
        while (envp[i][j] == tmp[j])
        {
            if (envp[i][j] == '=')
                return 1;
            j++;
        }
        i++;
    }
    return 1;
}

char    *ft_expand_heredoc(char *line, char **envp)
{
    int i;
    int d;
    char **line_split;
    
    line_split = ft_advanced_split(line);
    i = 0;
    while (line_split[i])
    {
        d = 0;
        while (line_split[i][d])
        {
            if (line_split[i][d] == '$')
            {
                if (ft_env_search(line[i], envp) == 1)
                {
                    printf("kayn kayn\n");
                    
                }
            }
            d++;
        }
        i++;
    }
    return line;
}