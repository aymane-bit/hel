/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:08:26 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 21:54:52 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a > c && c > b)
		ft_ra(stack_a);
	else if (a > b)
		ft_sa(stack_a);
	else if (b > c && a > c)
		ft_rra(stack_a);
	else if (b > c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}
