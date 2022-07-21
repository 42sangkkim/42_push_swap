/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:12:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 22:01:55 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	len;
	t_node	*top;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
}	t_push_swap;

int	sa(t_push_swap *push_swap);
int	sb(t_push_swap *push_swap);
int	ss(t_push_swap *push_swap);
int	pa(t_push_swap *push_swap);
int	pb(t_push_swap *push_swap);
int	ra(t_push_swap *push_swap);
int	rb(t_push_swap *push_swap);
int	rr(t_push_swap *push_swap);
int	rra(t_push_swap *push_swap);
int	rrb(t_push_swap *push_swap);
int	rrr(t_push_swap *push_swap);

#endif