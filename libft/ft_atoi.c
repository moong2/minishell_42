/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:16:12 by jeyoung           #+#    #+#             */
/*   Updated: 2022/04/10 09:52:48 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	is_spac(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' || \
	c == '\f' || c == '\r' || c == ' ')
		return (true);
	else
		return (false);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	return_num;
	long long	tmp;

	sign = 1;
	return_num = 0;
	i = 0;
	while (is_spac(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = return_num * 10 + (str[i] - '0');
		if (tmp < return_num)
			return (-1 + (sign < 0));
		return_num = tmp;
		i++;
	}
	return ((int)(return_num * sign));
}
