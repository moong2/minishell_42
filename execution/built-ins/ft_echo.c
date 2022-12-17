/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:25:19 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/12/17 20:22:57 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(char **content)
{
	int	i;
	int	yes;

	i = 1;
	yes = 0;
	while (ft_ncmp(content[i]) == 0)
	{
		i++;
		yes++;
		if (content[i] && !ft_strcmp(content[i], " "))
			i++;
	}
	while (content[i])
	{
		printf("%s", content[i]);
		i++;
	}
	if (yes == 0)
		printf("\n");
	return (0);
}
