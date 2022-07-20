/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:48:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 16:15:29 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

int		parse_input(t_stack *stack, int argc, char **argv);
int		sort_stack(t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (parse_input(&stack_a, argc, argv) < 0)
	{
		write(2, "Error\n", 6);
		destroy_stack(&stack_a);
		destroy_stack(&stack_b);
		return (-1);
	}
	sort_stack(&stack_a, &stack_b);
	print_stack(&stack_a);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (0);
}
