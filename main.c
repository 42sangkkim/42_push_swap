/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:48:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 12:37:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "stack.h"

int		build_stack(t_stack *stack, int argc, char **argv);
void	print_stack(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = new_stack();
	if (!stack_a)
		return (-1);
	stack_b = new_stack();
	if (!stack_b)
		return (-1);
	if (build_stack(&stack_a, argc, argv) < 0)
		return (-1);
	print_stack(stack_a);
}

void	print_stack(t_stack stack)
{
	int		*array;
	size_t	i;

	array = to_array(&stack);
	if (!array)
		return ;
	i = 0;
	while (i < stack->size)
	{
		ft_putnbr_fd(array[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}
