/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:48:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 15:29:53 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "stack.h"

int		build_stack(t_stack *stack, int argc, char **argv);
int		sort_stack(t_stack stack_a, t_stack stack_b);
void	print_stack(t_stack stack);

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = new_stack();
	stack_b = new_stack();
	if (build_stack(&stack_a, argc, argv) < 0)
	{
		write(2, "Error\n", 6);
		destroy_stack(&stack_a);
		destroy_stack(&stack_b);
		return (-1);
	}
	if (sort_stack(stack_a, stack_b) < 0)
	{
		write(2, "Error\n", 6);
		destroy_stack(&stack_a);
		destroy_stack(&stack_b);
		return (-1);
	}
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (0);
}

void	print_stack(t_stack stack)
{
	int		*array;
	size_t	i;

	array = to_array(&stack);
	if (!array)
		return ;
	i = 0;
	while (i < stack.len)
	{
		ft_putnbr_fd(array[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	free(array);
}
