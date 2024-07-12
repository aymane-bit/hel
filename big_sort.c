/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:28:44 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/12 16:33:52 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_b_pusher(t_list **stack_a, t_list **stack_b, int range)
{
	int		i;
	int		index;
	t_list	*temp_a;

	i = 0;
	temp_a = *stack_a;
	while (ft_lstsize(*stack_a) != 0)
	{
		if (temp_a->rank <= range && temp_a->rank >= i)
		{
			ft_pb(stack_a, stack_b);
			i++;
			range++;
		}
		else if (temp_a->rank <= range)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			i++;
			range++;
		}
		else
			ft_ra(stack_a);
		temp_a = *stack_a;
	}
}

int	index_returner(t_list *stack_b)
{
	int		max_value;
	int		index;
	int		max_index;
	t_list	*current;

	max_index = 0;
	index = 0;
	max_value = stack_b->content;
	current = stack_b->next;
	while (current != NULL)
	{
		index++;
		if (current->content > max_value)
		{
			max_value = current->content;
			max_index = index;
		}
		current = current->next;
	}
	return (max_index);
}

void	ft_a_push(t_list **stack_a, t_list **stack_b, int index)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (index <= ft_lstsize(*stack_b) / 2)
	{
		while (index > 0)
		{
			ft_rb(stack_b);
			index--;
		}
	}
	else
	{
		index = ft_lstsize(*stack_b) - index;
		while (index != 0)
		{
			ft_rrb(stack_b);
			index--;
		}
	}
	ft_pa(stack_a, stack_b);
}

void	stack_a_pusher(t_list **stack_a, t_list **stack_b)
{
	int		index;
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (ft_lstsize(*stack_b) != 0)
	{
		index = index_returner(*stack_b);
		ft_a_push(stack_a, stack_b, index);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int		range;
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	i = 0;
	if (ft_lstsize(*stack_a) <= 250)
		range = 15;
	else
		range = 40;
	stack_b_pusher(stack_a, stack_b, range);
	stack_a_pusher(stack_a, stack_b);
}
