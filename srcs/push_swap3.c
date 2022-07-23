/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:39:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 20:39:46 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	rra(t_stack *a, t_stack *b, int print)
{
	(void)b;
	if (reverse_rotate(a))
	{
		if (print)
			ft_putstr_fd("rra\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rrb(t_stack *a, t_stack *b, int print)
{
	(void)a;
	if (reverse_rotate(b))
	{
		if (print)
			ft_putstr_fd("rrb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rrr(t_stack *a, t_stack *b, int print)
{
	if (reverse_rotate(a) + reverse_rotate(b))
	{
		if (print)
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
