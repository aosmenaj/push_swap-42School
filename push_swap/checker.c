/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:02:18 by aosmenaj          #+#    #+#             */
/*   Updated: 2025/05/13 11:40:16 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	return ;
}

static	int	not_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	if ((*stack_a)->next == NULL)
		return (0);
	while (*stack_a)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			*stack_a = temp;
			return (1);
		}
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->next == NULL)
		{
			*stack_a = temp;
			return (0);
		}
	}
	*stack_a = temp;
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (!ft_check_if_valid_bonus(argv, argc))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	pute_node_bonus(&stack_a, &stack_b, argv, argc);
	read_moves(&stack_a, &stack_b);
	if (!not_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
