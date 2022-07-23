/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:37:13 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 20:39:15 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ra(t_stack *a, t_stack *b, int print)
{
	(void)b;
	if (rotate(a))
	{
		if (print)
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rb(t_stack *a, t_stack *b, int print)
{
	(void)a;
	if (rotate(b))
	{
		if (print)
			ft_putstr_fd("rb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rr(t_stack *a, t_stack *b, int print)
{
	if (rotate(a) + rotate(b))
	{
		if (print)
			ft_putstr_fd("rr\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
