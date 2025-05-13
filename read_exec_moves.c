/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leggi_esegui_mosse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:54:40 by aosmenaj          #+#    #+#             */
/*   Updated: 2025/05/13 11:40:41 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

static void	execut_push(t_node **stack_a, t_node **stack_b, char *buffer)
{
	if (!ft_strncmp(buffer, "pa\n"))
		pa_bonus(stack_b, stack_a);
	else if (!ft_strncmp(buffer, "pb\n"))
		pb_bonus(stack_a, stack_b);
}

static void	contr_esegui_mossa(char *buffer, t_node **stack_a,
			t_node **stack_b, int *c)
{
	if (buffer)
	{
		if (!ft_strncmp(buffer, "pa\n") || !ft_strncmp(buffer, "pb\n"))
			execut_push(stack_a, stack_b, buffer);
		else if (!ft_strncmp(buffer, "ra\n"))
			ra_bonus(stack_a);
		else if (!ft_strncmp(buffer, "rb\n"))
			rb_bonus(stack_b);
		else if (!ft_strncmp(buffer, "rr\n"))
			rr_bonus(stack_a, stack_b);
		else if (!ft_strncmp(buffer, "rra\n"))
			rra_bonus(stack_a);
		else if (!ft_strncmp(buffer, "rrb\n"))
			rrb_bonus(stack_b);
		else if (!ft_strncmp(buffer, "rrr\n"))
			rrr_bonus(stack_a, stack_b);
		else if (!ft_strncmp(buffer, "sa\n"))
			sa_bonus(stack_a);
		else if (!ft_strncmp(buffer, "sb\n"))
			sb_bonus(stack_a);
		else if (!ft_strncmp(buffer, "ss\n"))
			ss_bonus(stack_a, stack_b);
		else
			*c = 0;
	}
}

void	read_moves(t_node **stack_a, t_node **stack_b)
{
	char	*buffer;
	int		*c;
	int		x;

	c = &x;
	*c = 1;
	buffer = "42";
	while (buffer)
	{
		buffer = get_next_line(0, 0);
		contr_esegui_mossa(buffer, stack_a, stack_b, c);
		if (*c == 0)
		{
			free(buffer);
			buffer = get_next_line(0, 1);
			ft_exit_bonus(stack_a, stack_b);
		}
		free(buffer);
	}
}
