/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:14:52 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 21:54:22 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_min_pusher(int i, t_list **stack_a, t_list **stack_b)
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
		ft_pb(stack_a, stack_b);
	}
}

void	four_sort(t_list **stack_a, t_list **stack_b, int index)
{
	int		d;
	int		i;
	t_list	*temp1;

	i = 0;
	temp1 = *stack_a;
	if (index == 1)
		d = 1;
	else
		d = 0;
	while (temp1->rank != d)
	{
		temp1 = temp1->next;
		i++;
	}
	four_min_pusher(i, stack_a, stack_b);
	three_sort(stack_a);
	ft_pa(stack_a, stack_b);
}
