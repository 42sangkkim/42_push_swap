/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 13:51:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

char	*parse_int(int *value, char *str);

void	to_space(unsigned int i, char *s)
{
	if (i < 0)
		return ;
	if (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		*s = ' ';
}

//	인자 하나에 숫자가 아무것도 없으면 error 일까요?
int	build_stack(t_stack *stack, int argc, char **argv)
{
	size_t	i;
	char	*str;
	int		value;

	i = 1;
	while (i < (size_t)argc)
	{
		str = argv[i++];
		ft_striteri(str, &to_space);
		while (*str)
		{
			if (*str == ' ')
				str++;
			else if ('0' <= *str && *str <= '9')
			{
				str = parse_int(&value, str);
				if (str == NULL || push(stack, value) < 0)
					return (-1);
				rotate(stack);
			}
			else
				return (-1);
		}
	}
	return (0);
}
