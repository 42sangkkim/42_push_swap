/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:34:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/17 11:37:39 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	op_sa(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_sb(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_ss(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_pa(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_pb(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_ra(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_rb(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_rr(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_rra(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_rrb(t_stack *a, t_stack *b, t_op op, size_t n);
void	op_rrr(t_stack *a, t_stack *b, t_op op, size_t n);

void	operation(t_stack *a, t_stack *b, t_op op, size_t n)
{
	if (op == sa)
		op_sa(a, b, n);
	else if (op == sb)
		op_sb(a, b, n);
	else if (op == ss)
		op_ss(a, b, n);
	else if (op == pa)
		op_pa(a, b, n);
	else if (op == pb)
		op_pb(a, b, n);
	else if (op == ra)
		op_ra(a, b, n);
	else if (op == rb)
		op_rb(a, b, n);
	else if (op == rr)
		op_rr(a, b, n);
	else if (op == rra)
		op_rra(a, b, n);
	else if (op == rrb)
		op_rrb(a, b, n);
	else if (op == rrr)
		op_rrr(a, b, n);
}

void	op_sa(t_stack *a, t_stack *b, size_t n)
{
	(void)b;
	while (n--)
	{
		if (swap(a))
			write(1, "sa\n", 3);
	}
}

void	op_sb(t_stack *a, t_stack *b, size_t n)
{
	(void)a;
	while (n--)
	{
		if (swap(b))
			write(1, "sb\n", 3);
	}
}

void	op_ss(t_stack *a, t_stack *b, size_t n)
{
	while (n--)
	{
		if (swap(b) + swap(a))
			write(1, "ss\n", 3);
	}
}
