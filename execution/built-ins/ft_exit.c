/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:54:50 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/12/17 15:29:06 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	exit_with_arg(char **content)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(content[1]))
	{
		if (!ft_isalnum(content[1][i]) || ft_isalpha(content[1][i]))
		{
			if ((content[1][i] != '+' && content[1][i] != '-'))
			{
				write(2, "minishell: exit: ", 17);
				write(2, content[1], ft_strlen(content[1]));
				write(2, ": numeric argument required\n", 28);
				return (255);
			}
		}
		i++;
	}
	return (ft_atoi(content[1]));
}

int	ft_exit(char **content, t_env *env)
{
	printf("exit\n");
	if (ft_dubstrlen(content) > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		g_exit_status = 1;
		return (255);
	}
	ft_free_env(env);
	if (ft_dubstrlen(content) == 2)
		exit(exit_with_arg(content));
	exit(0);
	return (0);
}
