/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 14:58:05 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

char	*parse_int(int *value, char *str);
int		push_input(t_stack *stack, char *input);

void	to_space(unsigned int i, char *s)
{
	i = 0;
	if (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		*s = ' ';
}

int	build_stack(t_stack *stack, int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (push_input(stack, argv[i++]) <= 0)
			return (-1);
	}
	return (0);
}

int	push_input(t_stack *stack, char *input)
{
	int	cnt;
	int	value;

	cnt = 0;
	ft_striteri(input, &to_space);
	while (*input)
	{
		if (*input == ' ')
			input++;
		else if ('0' <= *input && *input <= '9')
		{
			cnt++;
			input = parse_int(&value, input);
			if (input == NULL || push(stack, value) < 0)
				return (-1);
			rotate(stack);
		}
		else
			return (-1);
	}
	return (cnt);
}
