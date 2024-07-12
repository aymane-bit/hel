/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymane <aymane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:55:14 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/11 22:19:27 by aymane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct stack
{
	int				content;
	int				rank;
	struct stack	*next;
}					t_stack;

void				free_stack(t_list *stack);
void				free1_array(void **array);
t_stack				*create_stack_from_array(int **arr, int size);
void				ft_stack_creator(t_stack *stack_a, int *argv);
void				ft_stack_free(t_list *stack_a);
t_list				*stack_creator(char **array);
int					*array_creator(t_list *stack_a, int size);
void				sort_beginner(t_list **stack_a, t_list **stack_b, int size);
int					ft_dup_detector(char **argv);
void				ft_arg_checker(char **argv);
void				ft_exit(char **argv, int i);
void				ft_lstprint_int(t_list *head);

int					**convert_char_to_int_array(char **array, int size);

void				print_stack_a(t_list *stack_a);
int					**char_to_int(char **input);
void				print_stack_b(t_list *stack_a);
void				ft_free_it(void **array);

// algo
void				ft_sort(t_list *stack_a, int size, char **array);
void				three_sort(t_list **stack_a);
void				five_sort(t_list **stack_a, t_list **stack_b);
void				four_sort(t_list **stack_a, t_list **stack_b, int index);
void				big_sort(t_list **stack_a, t_list **stack_b, int size);

// operation
void				ft_sa(t_list **stack_a);
void				ft_rra(t_list **head);
void				ft_ra(t_list **head);
void				ft_pb(t_list **stack_a, t_list **stack_b);
void				ft_pa(t_list **stack_a, t_list **stack_b);
void				ft_rb(t_list **head);
void				ft_rrb(t_list **stack_a);

#endif