/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 03:25:19 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/07 19:11:07 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*curent;

	if (lst == NULL)
		return (0);
	curent = lst;
	count = 0;
	while (curent != NULL)
	{
		count++;
		curent = curent->next;
	}
	return (count);
}
