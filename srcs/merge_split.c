/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:31:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/19 16:24:44 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	atop_split_cnt(size_t n);
ssize_t	abot_split_cnt(size_t n);
ssize_t	btop_split_cnt(size_t n);
ssize_t	bbot_split_cnt(size_t n);

ssize_t	split_cnt(size_t n)
{
	return (atop_split_cnt(n));
}

ssize_t	atop_split_cnt(size_t n)
{
	ssize_t	cnt;

	if (n == 0)
		return (0);
	else if (n < 3)
		return (n);
	cnt = n - (n / 3);
	cnt += abot_split_cnt(n / 3);
	cnt += btop_split_cnt(n / 3);
	cnt += bbot_split_cnt(n - (n / 3) * 2);
	return (cnt);
}

ssize_t	abot_split_cnt(size_t n)
{
	ssize_t	cnt;

	if (n == 0)
		return (0);
	else if (n < 3)
		return (n);
	cnt = n - (n / 3);
	cnt += atop_split_cnt(n / 3);
	cnt += btop_split_cnt(n / 3);
	cnt += bbot_split_cnt(n - (n / 3) * 2);
	return (cnt);
}

ssize_t	btop_split_cnt(size_t n)
{
	ssize_t	cnt;

	if (n == 0)
		return (0);
	else if (n < 3)
		return (-n);
	cnt = (n / 3) - n;
	cnt += bbot_split_cnt(n / 3);
	cnt += atop_split_cnt(n / 3);
	cnt += abot_split_cnt(n - (n / 3) * 2);
	return (cnt);
}

ssize_t	bbot_split_cnt(size_t n)
{
	ssize_t	cnt;

	if (n == 0)
		return (0);
	else if (n < 3)
		return (-n);
	cnt = (n / 3) - n;
	cnt += btop_split_cnt(n / 3);
	cnt += atop_split_cnt(n / 3);
	cnt += abot_split_cnt(n - (n / 3) * 2);
	return (cnt);
}
