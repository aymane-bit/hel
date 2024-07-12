/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:18:39 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 21:54:27 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	last = *stack_a;
	second_last = NULL;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	ft_ra(t_list **head)
{
	t_list	*last;
	t_list	*first;

	last = *head;
	first = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **head)
{
	t_list	*last;
	t_list	*first;

	last = *head;
	first = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	ft_rrb(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	last = *stack_a;
	second_last = NULL;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rrb\n", 4);
}
