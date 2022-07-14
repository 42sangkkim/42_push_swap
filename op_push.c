/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:41:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 16:02:08 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	op_pa(t_stack *a, t_stack *b, size_t n)
{
	t_node	*tmp;

	while (n--)
	{
		if (pop_node(b, &tmp) < 0)
			break ;
		push_node(a, tmp);
		write(1, "pa\n", 3);
	}
}

void	op_pb(t_stack *a, t_stack *b, size_t n)
{
	t_node	*tmp;

	while (n--)
	{
		if (pop_node(a, &tmp) < 0)
			break ;
		push_node(b, tmp);
		write(1, "pb\n", 3);
	}
}
