/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:25:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/17 12:25:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "operation.h"

void	op_rra(t_stack *a, t_stack *b, size_t n)
{
	(void)b;
	while (n--)
	{
		if (reverse_rotate(a))
			write(1, "rra\n", 4);
	}
}

void	op_rrb(t_stack *a, t_stack *b, size_t n)
{
	(void)a;
	while (n--)
	{
		if (reverse_rotate(b))
			write(1, "rrb\n", 4);
	}
}

void	op_rrr(t_stack *a, t_stack *b, size_t n)
{
	while (n--)
	{
		if (reverse_rotate(a) + reverse_rotate(b))
			write(1, "rrr\n", 4);
	}
}
