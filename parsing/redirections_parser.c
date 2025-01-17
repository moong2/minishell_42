/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:11:34 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:43:25 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_set_red(t_cmd *cmd, int i)
{
	if ((ft_strcmp(cmd->content[i], "<<") == 0
			|| ft_strcmp(cmd->content[i], ">>") == 0
			|| ft_strcmp(cmd->content[i], "<") == 0
			|| ft_strcmp(cmd->content[i], ">") == 0) && cmd->quoted[i] == 0)
	{
		if (cmd->content[i + 1] && cmd->quoted[i + 1] == 0
			&& ft_strcmp(cmd->content[i + 1], " ") == 0)
			cmd->content = remove_str(cmd->content, i + 1);
		ft_redadd_back(&cmd->red, ft_rednew(ft_strdup(cmd->content[i + 1])));
		if (ft_strcmp(cmd->content[i], ">") == 0)
			ft_redlast(cmd->red)->type = OUTFILE;
		else if (ft_strcmp(cmd->content[i], ">>") == 0)
			ft_redlast(cmd->red)->type = APPAND;
		else if (ft_strcmp(cmd->content[i], "<") == 0)
			ft_redlast(cmd->red)->type = INFILE;
		else if (ft_strcmp(cmd->content[i], "<<") == 0)
		{
			ft_redlast(cmd->red)->type = HERDOC;
			ft_redlast(cmd->red)->pipe_0 = cmd->pipe[i];
		}
		return (1);
	}
	return (0);
}

static void	ft_rem(t_cmd *cmd, int i)
{
	cmd->quoted = remove_array_column(cmd->quoted,
			ft_dubstrlen(cmd->content), i);
	cmd->pipe = remove_array_column(cmd->pipe,
			ft_dubstrlen(cmd->content), i);
	cmd->content = remove_str(cmd->content, i);
	cmd->quoted = remove_array_column(cmd->quoted,
			ft_dubstrlen(cmd->content), i);
	cmd->pipe = remove_array_column(cmd->pipe,
			ft_dubstrlen(cmd->content), i);
	cmd->content = remove_str(cmd->content, i);
	if (cmd->content[i] && cmd->quoted[i] == 0
		&& ft_strcmp(cmd->content[i], " ") == 0)
		cmd->content = remove_str(cmd->content, i);
}

void	redirections_parser(t_cmd *cmd)
{
	int	i;
	
	while (cmd)
	{
		i = 0;
		while (cmd->content[i])
		{
			if (cmd->quoted[i] == 0 && ft_set_red(cmd, i))
				ft_rem(cmd, i);
			else
				i++;
		}
		if (i - 1 != 0 && cmd->content[i - 1] && \
		ft_strcmp(" ", cmd->content[i - 1]) == 0)
			cmd->content = remove_str(cmd->content, i - 1);
		cmd = cmd->next;
	}
}
