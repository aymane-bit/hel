/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:43:56 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 21:54:34 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	if (*stack_a == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = *stack_b;
	*stack_b = first;
	write(1, "pb\n", 3);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	first = *stack_b;
	if (*stack_b == NULL)
		return ;
	*stack_b = first->next;
	first->next = *stack_a;
	*stack_a = first;
	write(1, "pa\n", 3);
}
