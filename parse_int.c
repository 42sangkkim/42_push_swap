/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:04:12 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 22:57:04 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int	parse_hex(int *p, char *str);
int	parse_octal(int *p, char *str);
int	parse_binary(int *p, char *str);
int	parse_decimal(int *p, char *str);

int	parse_int(int *value, char *str)
{
	int	err_code;

	if (!*str)
	{
		write(1, "\033[0;33m[WARNING] empty string detected\n", 39);
		return (-2);
	}
	if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "-0x", 3)
		|| !ft_strncmp(str, "+0x", 3))
		err_code = parse_hex(value, str);
	else if (!ft_strncmp(str, "0b", 2) || !ft_strncmp(str, "-0b", 3)
		|| !ft_strncmp(str, "+0b", 3))
		err_code = parse_binary(value, str);
	else if (!ft_strncmp(str, "0", 1) || !ft_strncmp(str, "-0", 2)
		|| !ft_strncmp(str, "+0", 2))
		err_code = parse_octal(value, str);
	else
		err_code = parse_decimal(value, str);
	if (err_code == -2)
		write(1, "\033[0;33m[WARNING] wrong character detected\n", 42);
	else if (err_code == -3)
		write(1, "\033[0;33m[WARNING] out of integer range\n", 38);
	return (err_code);
}

int	parse_hex(int *p, char *str)
{
	long long	sign;
	long long	value;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	str += 2;
	value = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			value = value * 16 + sign * (*str - '0');
		else if ('A' <= *str && *str <= 'F')
			value = value * 16 + sign * (*str - 'A' + 10);
		else if ('a' <= *str && *str <= 'f')
			value = value * 16 + sign * (*str - 'a' + 10);
		else
			return (-2);
		if (value < INT_MIN || value > INT_MAX)
			return (-3);
		str++;
	}
	*p = (int)value;
	return (0);
}

int	parse_octal(int *p, char *str)
{
	long long	sign;
	long long	value;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	value = 0;
	while ('0' <= *str && *str <= '7')
	{
		value = value * 8 + sign * (*str - '0');
		if (value < INT_MIN || value > INT_MAX)
			return (-3);
		str++;
	}
	if (*str)
		return (-2);
	*p = (int)value;
	return (0);
}

int	parse_binary(int *p, char *str)
{
	long long	sign;
	long long	value;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	str += 2;
	value = 0;
	while ('0' <= *str && *str <= '1')
	{
		value = value * 2 + sign * (*str - '0');
		if (value < INT_MIN || value > INT_MAX)
			return (-3);
		str++;
	}
	if (*str)
		return (-2);
	*p = (int)value;
	return (0);
}

int	parse_decimal(int *p, char *str)
{
	long long	sign;
	long long	value;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	value = 0;
	while ('0' <= *str && *str <= '9')
	{
		value = value * 10 + sign * (*str - '0');
		if (value < INT_MIN || value > INT_MAX)
			return (-3);
		str++;
	}
	if (*str)
		return (-2);
	*p = (int)value;
	return (0);
}
