/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:47:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 01:33:08 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

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
int		push(t_stack *stack, int value);
int		pop(t_stack *stack, int *value);
int		*to_array(t_stack *stack);

// stack_util.c
int		swap(t_stack *stack);
int		rotate(t_stack *stack);
int		r_rotate(t_stack *stack);

#endif
