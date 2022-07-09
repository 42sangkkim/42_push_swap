/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:06:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 22:49:54 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

int	parse_int(int *value, char *str);
int	check_duplicate(t_stack *stack);

int	init_stack(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
	size_t	i;

	*stack_a = new_stack(argc - 1);
	*stack_b = new_stack(argc - 1);
	if (!*stack_a || !*stack_b)
	{
		write(2, "\033[0;31m[ERROR] memory allocation fail\n", 38);
		exit(-1);
	}
	i = 1;
	while (i < (size_t)argc)
	{
		if (parse_int(&((*stack_a)->data[argc - 1 - i]), argv[i]) < 0)
			return (-1);
		i++;
	}
	(*stack_a)->top = argc - 1;
	if (check_duplicate(*stack_a) < 0)
	{
		write(1, "\033[0;33m[WARNING] duplicated data detected\n", 42);
		return (-2);
	}
	return (0);
}

int	check_duplicate(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < stack->size)
	{
		tmp = stack->data[i];
		j = i + 1;
		while (j < stack->size)
		{
			if (tmp == stack->data[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
