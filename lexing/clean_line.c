/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:49:17 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/21 17:16:18 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dollar(t_list **arg, t_env *env)
{
	int		i;
	char	*tmp;
	int		sequenced_dollars;

	i = 0;
	sequenced_dollars = 0;
	ft_expand_exit_status(arg);
	while ((*arg)->content[i] && (*arg)->content[i] != '$')
		i++;
	if (i > 0)
	{
		ft_lstinsert(arg, ft_lstnew(ft_strdup(&(*arg)->content[i]), \
		(*arg)->quoted));
		tmp = (*arg)->content;
		(*arg)->content = ft_substr_lex((*arg)->content, 0, i);
		free(tmp);
	}
	while ((*arg)->content[i++] == '$' && (*arg)->content[i] == '$')
		sequenced_dollars++;
	if ((*arg)->content[0] == '$')
		ft_expand(arg, env, sequenced_dollars);
}

void	clean_line(t_list **arg, t_env *env)
{
	t_list	*tmp;

	tmp = (*arg);
	while (tmp)
	{
		ft_is_redirections(&tmp);
		define_pipe(&tmp);
		tmp = tmp->next;
	}
	ft_herdoc(arg, env);
	while (*arg)
	{
		if (((*arg)->quoted == 0 && ft_strcmp((*arg)->content, "|") == 0 \
		&& (*arg)->next && (*arg)->next->quoted == 0 \
		&& ft_strcmp((*arg)->next->content, " ") == 0))
			ft_dellst(arg, (*arg)->next);
		if ((*arg) && (*arg)->quoted != 1 && ft_strchr((*arg)->content, '$'))
			dollar(arg, env);
		(*arg) = (*arg)->next;
	}
}
