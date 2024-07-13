/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:29:05 by achahid-          #+#    #+#             */
/*   Updated: 2024/06/11 04:29:06 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

void		tokens_list_optimizer(token_ptr *tokens_list);
static void	whitespace_remover(token_ptr *tokens_list,
				token_ptr free_node, token_ptr previous);
void		node_remover(token_ptr *node);				
void		special_chars_refactor(token_ptr tokens_list);
t_bool		special_chars_finder(token_ptr *tokens_list, token_ptr node_add,
				int type);

/**
 * tokens_list_optimizer -
 */
void	tokens_list_optimizer(token_ptr *tokens_list)
{
	token_ptr	tmp;
	token_ptr	free_node;
	token_ptr	previous;

	tmp = *tokens_list;
	free_node = NULL;
	previous = NULL;
	whitespace_remover(tokens_list, free_node, previous);
	tokens_order(*tokens_list);
}

/**
 * whitespace_remover -
 */
static void	whitespace_remover(token_ptr *tokens_list,
				token_ptr free_node, token_ptr previous)
{
	token_ptr	tmp;

	tmp = *tokens_list;
	while (tmp)
	{
		if (tmp->token_length == 0)
		{
			free_node = tmp;
			previous = tmp->previous;
			tmp = tmp->next;
			if (previous != NULL)
				previous->next = tmp;
			else
				*tokens_list = tmp;
			if (tmp != NULL)
				tmp->previous = previous;
			if (previous == NULL && tmp == NULL)
				*tokens_list = NULL;
			free(free_node->token);
			free(free_node);
			free_node = NULL;
			continue ;
		}
		tmp = tmp->next;
	}
}

/**
 * node_remover -
*/
void	node_remover(token_ptr *node)
{
	token_ptr	tmp;
	token_ptr	free_node;
	token_ptr	previous;

	tmp = *node;
	free_node = tmp;
	previous = tmp->previous;
	tmp = tmp->next;
	if (previous != NULL)
		previous->next = tmp;
	else
		*node = tmp;
	if (tmp != NULL)
		tmp->previous = previous;
	if (previous == NULL && tmp == NULL)
		*node = NULL;
	*node = (*node)->next;
	free(free_node->token);
	free(free_node);
	free_node = NULL;
}

/**
 * special_chars_refactor -
 */
void	special_chars_refactor(token_ptr tokens_list)
{
	int			type;
	token_ptr	node_add;

	while (tokens_list)
	{
		type = tokens_list->token_type;
		if (special_chars_checker(type) == true)
		{
			tokens_list = tokens_list->next;
			while (tokens_list->token_type != type)
			{
				tokens_list = tokens_list->next;
				if (tokens_list == NULL)
					return ;
			}
			node_add = tokens_list;
			if (special_chars_finder(&tokens_list, node_add, type) == false)
				return ;
		}
		tokens_list = tokens_list->next;
		if (tokens_list == NULL)
			return ;
		if (tokens_list->token_type == pipe_token)
			return ;
	}
}

/**
 * special_chars_finder -
*/
t_bool	special_chars_finder(token_ptr *tokens_list, token_ptr node_add,
			int type)
{
	while (type != whitespace_token)
	{
		if (type == string_token || type == word_token || type == cmd)
		{
			node_add->token = ft_strjoin(node_add->token,
					(*tokens_list)->token);
			node_remover(tokens_list);
		}
		if ((*tokens_list) == NULL)
			return (false);
		if ((*tokens_list)->token_type == whitespace_token)
			return (true);
		(*tokens_list) = (*tokens_list)->next;
		if ((*tokens_list) == NULL)
			return (false);
		type = (*tokens_list)->token_type;
	}
	return (true);
}
