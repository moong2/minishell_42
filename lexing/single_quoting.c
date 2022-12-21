/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quoting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:37:40 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/21 15:21:41 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	single_quoting(char *buff, t_lex *lex, t_list **arg)
{
	lex->i++;
	if (buff[lex->i] == '\'')
	{
		ft_lstadd_back(arg, ft_lstnew(ft_strdup(""), 1));
		lex->i++;
		return (0);
	}
	lex->argstart = lex->i;
	while (buff[lex->i])
	{
		if (buff[lex->i] == '\'')
		{
			lex->arglen = lex->i;
			ft_lexadd_back(arg, \
			ft_lstnew(ft_substr_lex(buff, lex->argstart, lex->arglen), 1));
			lex->i++;
			return (0);
		}
		lex->i++;
	}
	printf("Error: syntax error: uninterpreted single quote.\n");
	g_exit_status = 1;
	return (1);
}
