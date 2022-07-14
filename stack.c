/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:50:14 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 13:43:05 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

t_stack	new_stack(void)
{
	t_stack	stack;

	stack.len = 0;
	stack.top = NULL;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (stack->len)
		pop_node(stack, NULL);
}

int	*to_array(t_stack *stack)
{
	int		*array;
	size_t	i;
	t_node	*node;

	array = malloc(stack->len * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	node = stack->top;
	while (i < stack->len)
	{
		array[i++] = node->value;
		node = node->next;
	}
	return (array);
}

void	rotate(t_stack *stack)
{
	if (stack->len < 2)
		return ;
	else
		stack->top = stack->top->next;
}

void	print_stack(t_stack *stack)
{
	int		*array;
	size_t	i;

	array = to_array(stack);
	if (!array)
		return ;
	i = 0;
	while (i < stack->len)
	{
		ft_putnbr_fd(array[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	free(array);
}
