/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:22:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 21:49:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

void	op_sa(t_stack *a, t_stack *b, size_t n);
void	op_sb(t_stack *a, t_stack *b, size_t n);
void	op_ss(t_stack *a, t_stack *b, size_t n);
void	op_pa(t_stack *a, t_stack *b, size_t n);
void	op_pb(t_stack *a, t_stack *b, size_t n);
void	op_ra(t_stack *a, t_stack *b, size_t n);
void	op_rb(t_stack *a, t_stack *b, size_t n);
void	op_rr(t_stack *a, t_stack *b, size_t n);
void	op_rra(t_stack *a, t_stack *b, size_t n);
void	op_rrb(t_stack *a, t_stack *b, size_t n);
void	op_rrr(t_stack *a, t_stack *b, size_t n);

void	operate(t_stack *a, t_stack *b, int op, size_t n)
{
	if (op == OP_SA)
		op_sa(a, b, n);
	else if (op == OP_SB)
		op_sb(a, b, n);
	else if (op == OP_SS)
		op_sa(a, b, n);
	else if (op == OP_PA)
		op_pa(a, b, n);
	else if (op == OP_PB)
		op_pb(a, b, n);
	else if (op == OP_RA)
		op_ra(a, b, n);
	else if (op == OP_RB)
		op_rb(a, b, n);
	else if (op == OP_RR)
		op_rr(a, b, n);
	else if (op == OP_RRA)
		op_rra(a, b, n);
	else if (op == OP_RRB)
		op_rrb(a, b, n);
	else if (op == OP_RRR)
		op_rrr(a, b, n);
}
