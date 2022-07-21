/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:15:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/19 16:30:12 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "operation.h"

ssize_t	split_cnt(size_t n);
void	atop_merge(t_stack *a, t_stack *b, size_t len);

void	sort_stack(t_stack *a, t_stack *b)
{
	ssize_t	pb_cnt;

	pb_cnt = split_cnt(a->len);
	write(1, "\n", 1);
	ft_putnbr_fd((int)pb_cnt, 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	operation(a, b, pb, (size_t)pb_cnt);
	atop_merge(a, b, a->len);
}
