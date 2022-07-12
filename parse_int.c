/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:04:12 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 12:23:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int	parse_hex(long long *value, char *str);
int	parse_octal(long long *value, char *str);
int	parse_binary(long long *value, char *str);
int	parse_decimal(long long *value, char *str);

//	0	: ok
//	-1	: empty value (not zero)
//	-2	: out of range

int	parse_int(int *value, char *str)
{
	long long	tmp_value;
	int			err_code;

	if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "-0x", 3)
		|| !ft_strncmp(str, "+0x", 3))
		err_code = parse_hex(&tmp_value, str);
	else if (!ft_strncmp(str, "0b", 2) || !ft_strncmp(str, "-0b", 3)
		|| !ft_strncmp(str, "+0b", 3))
		err_code = parse_binary(&tmp_value, str);
	else if (!ft_strncmp(str, "0", 1) || !ft_strncmp(str, "-0", 2)
		|| !ft_strncmp(str, "+0", 2))
		err_code = parse_octal(&tmp_value, str);
	else
		err_code = parse_decimal(&tmp_value, str);
	if (tmp_value < INT_MIN)
		*value = INT_MIN;
	else if (tmp_value > INT_MAX)
		*value = INT_MAX;
	else
		*value = (int)tmp_value;
	return (err_code);
}

int	parse_hex(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	str += 2;
	if (!('0' <= *str && *str <= '9') && !('A' <= *str && *str <= 'F')
		&& !('a' <= *str && *str <= 'f'))
		return (-1);
	*value = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			*value = *value * 16 + sign * (*str - '0');
		else if ('A' <= *str && *str <= 'F')
			*value = *value * 16 + sign * (*str - 'A' + 10);
		else if ('a' <= *str && *str <= 'f')
			*value = *value * 16 + sign * (*str - 'a' + 10);
		if (*value < INT_MIN || *value > INT_MAX)
			return (-2);
		str++;
	}
	*p = (int)value;
	return (0);
}

int	parse_octal(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	*value = 0;
	while ('0' <= *str && *str <= '7')
	{
		*value = *value * 8 + sign * (*str - '0');
		if (*value < INT_MIN || *value > INT_MAX)
			return (-2);
		str++;
	}
	return (0);
}

int	parse_binary(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	str += 2;
	if (*str < '0' || '1' < *str)
		return (-1);
	*value = 0;
	while ('0' <= *str && *str <= '1')
	{
		*value = *value * 2 + sign * (*str - '0');
		if (*value < INT_MIN || *value > INT_MAX)
			return (-2);
		str++;
	}
	return (0);
}

int	parse_decimal(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' || '9' <= *str)
		return (-1);
	*value = 0;
	while ('0' <= *str && *str <= '9')
	{
		*value = *value * 10 + sign * (*str - '0');
		if (*value < INT_MIN || *value > INT_MAX)
			return (-2);
		str++;
	}
	return (0);
}
