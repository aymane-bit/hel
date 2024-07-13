/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_executor_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:56:29 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/08 17:45:04 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

char    *ft_last_del(char *delimiter)
{
    int count;
    int i;
    char *tmp;

    i = 0;
    count = 0;
    while (delimiter[i])
    {
        if (delimiter[i] == '\'' || delimiter[i] == '\"')
            count++;
        i++;
    }
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(delimiter) - count + 1));
    i = 0;
    count = 0;
    while (delimiter[i])
    {
        if (delimiter[i] == '\'' || delimiter[i] == '\"')
            while (delimiter[i] && (delimiter[i] == '\'' || delimiter[i] == '\"'))
                i++;
        if (delimiter[i] == '\0')
            break;
        tmp[count] = delimiter[i];
        count++;
        i++;
    }
    tmp[count] = '\0';
    return (free(delimiter),tmp);
}

char    *ft_first_del(token_ptr tokens_list)
{
    token_ptr tmp;
    char *delimiter;
    int flag;
    
    flag = 0;
    delimiter = NULL;
    tmp = tokens_list;
    while (tmp && (tmp->token_type == 4 || tmp->token_type == 5 || tmp->token_type == 2 
    || tmp->token_type == 3))
    {
        if (flag == 0 && (tmp->token_type != 4 && tmp->token_type != 5))
        {
            tmp->token_type = 20;
            flag = 1;
        }
        delimiter = ft_strjoin(delimiter, tmp->token);
        tmp = tmp->next;
    }
    return (delimiter);
}

char    *ft_delimiter_handler(token_ptr tokens_list)
{
    token_ptr tmp;
    char *delimiter;

    tmp = tokens_list;
    tmp = tmp->next;
    if (tmp->token_type == 0)
        while (tmp && tmp->token_type == 0)
            tmp = tmp->next;
    delimiter = ft_first_del(tmp);
    // printf("delimiter: (%s)\n", delimiter);
    delimiter = ft_last_del(delimiter);
    printf("delimiter: (%s)\n", delimiter);
    return (delimiter);
}

char    *ft_delimiter(token_ptr tokens_list, int order)
{
    char *delimiter;
    token_ptr tmp;

    tmp = tokens_list;
    while (tmp)
    {
        if (tmp->order == order)
        {
            delimiter = ft_delimiter_handler(tmp);
            return (delimiter);
        }
        tmp = tmp->next;
    }
    return (NULL);
}