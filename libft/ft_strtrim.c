/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:40:22 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/10 14:20:33 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	check_set(char const c1, char const *set)
{
	bool	check;

	check = false;
	while (*set != '\0')
	{
		if (*set == c1)
		{
			check = true;
			break ;
		}
		set++;
	}
	return (check);
}

static int	get_length(char const *s1, char const *set,	int *i, int *j)
{
	bool	ch_prefix;
	bool	ch_suffix;

	*i = 0;
	*j = ft_strlen(s1) - 1;
	while (*i <= *j)
	{
		ch_prefix = check_set(s1[*i], set);
		ch_suffix = check_set(s1[*j], set);
		if (!ch_prefix && !ch_suffix)
			break ;
		if (ch_prefix)
			(*i)++;
		if (ch_suffix)
			(*j)--;
	}
	return (*j - *i + 2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		ptr_index;
	int		length;

	ptr_index = 0;
	if (!set || !s1)
		return (NULL);
	length = get_length(s1, set, &i, &j);
	if (length == 0)
		length = 1;
	ptr = (char *)malloc(sizeof(char) * length);
	if (!ptr)
		return (NULL);
	while (i <= j)
	{
		ptr[ptr_index] = s1[i];
		i++;
		ptr_index++;
	}
	ptr[ptr_index] = '\0';
	return (ptr);
}
