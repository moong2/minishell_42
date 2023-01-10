/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:32:14 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:43:34 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	invalid_dollar(t_list *arg)
{
	if (ft_lstsize(arg) == 1 && arg->quoted == 4)
	{
		g_exit_status = 0;
		return (1);
	}
	return (0);
}

static int	ft_is_red(t_list *arg)
{
	if (ft_strcmp(arg->content, "<<") == 0
		|| ft_strcmp(arg->content, ">>") == 0
		|| ft_strcmp(arg->content, "<") == 0
		|| ft_strcmp(arg->content, ">") == 0)
		return (1);
	return (0);
}

static int	ft_dub_opp(t_list *arg)
{
	int	i;

	i = 0;
	while (arg)
	{
		if ((ft_strcmp(arg->content, "|") == 0 && arg->quoted == 0 && arg->next
				&& ft_strcmp(arg->next->content, "|") == 0
				&& arg->next->quoted == 0)
			|| (ft_strcmp(arg->content, "|") == 0 && arg->quoted == 0 && i == 0)
			|| (ft_is_red(arg) && arg->quoted == 0 && arg->next
				&& ft_is_opp(arg->next) && arg->next->quoted == 0)
			|| (ft_lstsize(arg) == 1 && ft_is_opp(arg) && arg->quoted == 0))
		{
			ft_error("Error:\n Invalid opperators parsing.\n");
			g_exit_status = 258;
			return (1);
		}
		i++;
		arg = arg->next;
	}
	return (0);
}

int	ft_errors(t_list *arg)
{
	if (invalid_dollar(arg) || ft_dub_opp(arg))
		return (1);
	return (0);
}
