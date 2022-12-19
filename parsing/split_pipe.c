/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:55:40 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/19 20:00:41 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*quots(int *cmdquoted, int quoted, int len)
{
	int	*new_quoted;
	int	i;

	if (cmdquoted == NULL)
	{
		new_quoted = malloc(sizeof(int));
		new_quoted[0] = quoted;
	}
	else
	{
		new_quoted = malloc(sizeof(int) * len);
		i = 0;
		while (i < len - 1)
		{
			new_quoted[i] = cmdquoted[i];
			i++;
		}
		new_quoted[i] = quoted;
		free(cmdquoted);
	}
	return (new_quoted);
}

void	ft_loop(t_list **arg, t_cmd **cmd)
{
	char	**content;
	int		*quoted;
	int		*pipe;

	content = NULL;
	pipe = NULL;
	quoted = NULL;
	while (*arg)
	{
		if (ft_strcmp((*arg)->content, "|") \
		|| (ft_strcmp((*arg)->content, "|") == 0 && (*arg)->quoted))
		{
			content = reallocate_dub(content, (*arg)->content);
			quoted = quots(quoted, (*arg)->quoted, ft_dubstrlen(content));
			pipe = quots(pipe, (*arg)->pipe_0, ft_dubstrlen(content));
		}
		else
			break ;
		(*arg) = (*arg)->next;
	}
	ft_cmdadd_back(cmd, ft_cmdnew(content, quoted, pipe));
}
