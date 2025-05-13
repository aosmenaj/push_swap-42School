/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:09 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/23 17:42:20 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	sa_bonus(t_node **a)
{
	if (!*a || !(*a + 1))
		return ;
	swap(a);
	return ;
}

void	sb_bonus(t_node **b)
{
	if (!*b || !(*b + 1))
		return ;
	swap(b);
	return ;
}

void	ss_bonus(t_node **a, t_node **b)
{
	if (!*a || !(*a + 1) || !*b || !(*b + 1))
		return ;
	swap(a);
	swap(b);
	return ;
}
