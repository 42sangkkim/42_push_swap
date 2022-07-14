/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:47:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 13:41:53 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	size_t	len;
	t_node	*top;
}	t_stack;

// stack.c
t_stack	new_stack(void);
void	destroy_stack(t_stack *stack);
int		*to_array(t_stack *stack);
void	rotate(t_stack *stack);
void	print_stack(t_stack *stack);

// stack2.c
int		pop_node(t_stack *stack, t_node **node_p);
int		push_node(t_stack *stack, t_node *node);
int		pop_value(t_stack *stack, int *value_p);
int		push_value(t_stack *stack, int value);

// stack_util.c
int		is_sorted(t_stack *stack, size_t len);
int		is_rev_sorted(t_stack *stack, size_t len);

#endif
