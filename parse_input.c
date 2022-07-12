/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 15:48:41 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

char	*parse_int(int *value, char *str);
int		parse_string(t_stack *stack, char *input);
int		check_duplicate(t_stack *stack);

void	to_space(unsigned int i, char *s)
{
	i = 0;
	if (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		*s = ' ';
}

int	parse_input(t_stack *stack, int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		ft_striteri(argv[i], &to_space);
		if (parse_string(stack, argv[i++]) <= 0)
			return (-1);
	}
	if (check_duplicate(stack) < 0)
		return (-1);
	return (0);
}

int	parse_string(t_stack *stack, char *input)
{
	int	cnt;
	int	value;

	cnt = 0;
	while (*input)
	{
		if (*input == ' ')
			input++;
		else if ('0' <= *input && *input <= '9')
		{
			cnt++;
			input = parse_int(&value, input);
			if (input == NULL)
				return (-1);
			if (push(stack, value) < 0)
				return (-1);
			rotate(stack);
		}
		else
			return (-1);
	}
	return (cnt);
}

int	check_duplicate(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		*array;

	array = to_array(stack);
	if (!array)
		return (-1);
	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (array[i] == array[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}