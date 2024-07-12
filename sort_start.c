/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:59:47 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 22:37:08 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_boble_sort(int **arr)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[j] != NULL)
		{
			if (*arr[i] < *arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	free1_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	get_rank(t_list **stack_a, char **array)
{
	t_list	*temp;
	int		**res;
	int		i;

	temp = *stack_a;
	i = 0;
	res = char_to_int(array);
	ft_boble_sort(res);
	while (temp != NULL)
	{
		while (res[i] != NULL)
		{
			if (temp->content == *res[i])
				temp->rank = i;
			i++;
		}
		i = 0;
		temp = temp->next;
	}
	free1_array((void **)res);
}

void	ft_sort(t_list *stack_a, int size, char **array)
{
	t_list	*stack_b;

	stack_b = NULL;
	get_rank(&stack_a, array);
	if (size == 2)
		ft_sa(&stack_a);
	else if (size == 3)
		three_sort(&stack_a);
	else if (size == 4)
		four_sort(&stack_a, &stack_b, 0);
	else if (size == 5)
		five_sort(&stack_a, &stack_b);
	else if (size > 5)
		big_sort(&stack_a, &stack_b, size);
	free_stack(stack_a);
	free1_array((void **)array);
}
