/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:09:12 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 21:54:01 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_pusher(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 0)
		ft_pb(stack_a, stack_b);
	else if (i == 1)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (i == 2)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (i == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (i == 4)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
}

void	five_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack_a;
	while (temp->rank != 0)
	{
		temp = temp->next;
		i++;
	}
	ft_min_pusher(i, stack_a, stack_b);
	four_sort(stack_a, stack_b, 1);
	ft_pa(stack_a, stack_b);
}
