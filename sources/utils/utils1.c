/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:36:20 by achahid-          #+#    #+#             */
/*   Updated: 2024/05/24 18:37:47 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

token_ptr	find_last_node(token_ptr head);
t_bool		ft_isspace(char c);
char		*ft_realloc(char *to_free, int new_len);
void		dup_and_close(int *end, int i);
void		points_checker(t_var data, char **av);

/**
 * find_last_node - iterates over a linked list
 * to find the last node.
 * @head: pointer to the first node
 * 
 * Return: pointer to the last node.
*/
token_ptr	find_last_node(token_ptr head)
{
	while (head != NULL)
	{
		if (head->next == NULL)
			break ;
		head = head->next;
	}
	return (head);
}

/**
 * ft_isspace - checks if the character c
 * is a space or not.
 * @c: character
 * 
 * Return: boolean.
*/
t_bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

/**
 * ft_realloc -
*/
char	*ft_realloc(char *to_free, int new_len)
{
	char	*new_ptr;

	free(to_free);
	new_ptr = (char *)malloc(sizeof(char) * new_len + 1);
	return (new_ptr);
}

/**
 * dup_and_close -
*/
void	dup_and_close(int *end, int i)
{
	if (i == STDOUT)
	{
		dup2(end[i], STDOUT_FILENO);
		close(end[0]);
		close(end[1]);
	}
	else if (i == STDIN)
	{
		dup2(end[i], STDIN_FILENO);
		close(end[0]);
		close(end[1]);
	}
}

/**
 * points_checker -
*/
void	points_checker(t_var data, char **av)
{
	char	*path_cmd;

	path_cmd = data.path_to_cmd;
	while (*path_cmd)
	{
		if ((*path_cmd) == '.')
		{
			if (*(path_cmd + 1) == '.')
				path_cmd++;
			if (*(path_cmd + 1) == '\0' || ft_isspace(*(path_cmd + 1)) == true)
			{
				free_all(data.tokens_list, data.user_input, av);
				print_error("kssh: No such file or directory !\n");
				exit(EXIT_FAILURE);
			}
		}
		path_cmd++;
	}
}
