/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:19:47 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 22:17:55 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_it(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

int	is_sorted(char **argv)
{
	int	a;
	int	i;
	int	b;

	i = 0;
	while (argv[i] && argv[i + 1])
	{
		a = ft_atoi(argv[i]);
		b = ft_atoi(argv[i + 1]);
		if (a > b)
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	ft_sort_init(int argc, char **argv, char *tmp)
{
	t_list	*stack_a;
	int		j;

	free(tmp);
	stack_a = NULL;
	ft_arg_checker(argv);
	j = ft_dup_detector(argv);
	if (is_sorted(argv) == 1)
		ft_exit(argv, 1);
	stack_a = stack_creator(argv);
	ft_sort(stack_a, j, argv);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*temp_tmp;

	i = 1;
	tmp = NULL;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		str = ft_strjoin(argv[i], " ");
		if (tmp == NULL)
			tmp = str;
		else
		{
			temp_tmp = ft_strjoin(tmp, str);
			free(tmp);
			tmp = temp_tmp;
			free(str);
		}
		i++;
	}
	argv = ft_split(tmp, ' ');
	ft_sort_init(argc, argv, tmp);
}
