/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:09 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/21 17:50:32 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next-> previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	(*head)->previous = NULL;
}

void	sa(t_node **a)
{
	if (!*a || !(*a + 1))
		return ;
	swap(a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_node **b)
{
	if (!*b || !(*b + 1))
		return ;
	swap(b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_node **a, t_node **b)
{
	if (!*a || !(*a + 1) || !*b || !(*b + 1))
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	return ;
}
