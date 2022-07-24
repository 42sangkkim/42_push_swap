/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:12:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 15:13:35 by sangkkim         ###   ########.fr       */
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

int	sa(t_push_swap *push_swap, int print);
int	sb(t_push_swap *push_swap, int print);
int	ss(t_push_swap *push_swap, int print);
int	pa(t_push_swap *push_swap, int print);
int	pb(t_push_swap *push_swap, int print);
int	ra(t_push_swap *push_swap, int print);
int	rb(t_push_swap *push_swap, int print);
int	rr(t_push_swap *push_swap, int print);
int	rra(t_push_swap *push_swap, int print);
int	rrb(t_push_swap *push_swap, int print);
int	rrr(t_push_swap *push_swap, int print);

#endif