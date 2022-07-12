/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:50:40 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 17:17:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

void	exe_swap(t_stack *stack_a, t_stack *stack_b, const char *exe);
int		exe_push(t_stack *stack_a, t_stack *stack_b, const char *exe);
void	exe_rotate(t_stack *stack_a, t_stack *stack_b, const char *exe);


void	print_stack(t_stack stack);

int	exe_operation(t_stack *stack_a, t_stack *stack_b, const char *exe)
{
	if (*exe == 's')
		exe_swap(stack_a, stack_b, exe);
	else if (*exe == 'p')
	{
		if (exe_push(stack_a, stack_b, exe) < 0)
			return (-1);
	}
	else if (*exe == 'r')
		exe_rotate(stack_a, stack_b, exe);
	ft_putstr_fd((char *)exe, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

void	exe_swap(t_stack *stack_a, t_stack *stack_b, const char *exe)
{
	if (ft_strncmp(exe, "sa", -1) == 0)
		swap(stack_a);
	else if (ft_strncmp(exe, "sb", -1) == 0)
		swap(stack_b);
	else if (ft_strncmp(exe, "ss", -1) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
}

int	exe_push(t_stack *stack_a, t_stack *stack_b, const char *exe)
{
	int	value;

	if (ft_strncmp(exe, "pa", -1) == 0)
	{
		if (pop(stack_b, &value) < 0 || push(stack_a, value) < 0)
			return (-1);
	}
	else if (ft_strncmp(exe, "pb", -1) == 0)
	{
		if (pop(stack_a, &value) < 0 || push(stack_b, value) < 0)
			return (-1);
	}
	return (0);
}

void	exe_rotate(t_stack *stack_a, t_stack *stack_b, const char *exe)
{
	if (ft_strncmp(exe, "ra", -1) == 0)
		rotate(stack_a);
	else if (ft_strncmp(exe, "rb", -1) == 0)
		rotate(stack_b);
	else if (ft_strncmp(exe, "rr", -1) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strncmp(exe, "rra", -1) == 0)
		r_rotate(stack_a);
	else if (ft_strncmp(exe, "rrb", -1) == 0)
		r_rotate(stack_b);
	else if (ft_strncmp(exe, "rrr", -1) == 0)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
}
