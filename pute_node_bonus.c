/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pute_node_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:09:53 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/23 17:23:14 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	t_node	*find_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static	int	repeat_contr(t_node *stack, long long n)
{
	if (n > 2147483647 || n < -2147483648)
		return (1);
	while (stack)
	{
		if (stack->content == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static	void	fill_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->content = n;
	node->target = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	pute_node_bonus(t_node **stack_a, t_node **stack_b,
			char **argv, int argc)
{
	int	n;
	int	i;
	int	error;
	int	pos;

	i = 1;
	while (argc > i)
	{
		pos = 0;
		while (pos != -1)
		{
			n = myatoi_bonus(argv[i], &error, &pos);
			if (error || repeat_contr(*stack_a, n))
				ft_exit_bonus(stack_a, stack_b);
			fill_node(stack_a, n);
		}
		i++;
	}
	return ;
}
