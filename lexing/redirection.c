/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:12:30 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/21 17:34:21 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	inset_allocat(t_list **arg, int i)
{
	ft_lstinsert(arg, ft_lstnew(ft_substr_lex((*arg)->content, i, \
	ft_strlen((*arg)->content)), 0));
	reallocate(arg, ft_substr_lex((*arg)->content, 0, i));
}

int	ft_tbd(t_list **arg, int *i, char c)
{
	if ((*i) == 0 && (*arg)->content[(*i)] == c)
	{
		(*i)++;
		if ((*arg)->content[(*i)] == c)
		{
			(*i)++;
			if ((*arg)->content[(*i)] == c)
			{
				(*i)++;
				if ((*arg)->content[(*i)] != '\0')
					insert_allocat(arg, (*i));
			}
			else if ((*arg)->content[(*i)])
				insert_allocat(arg, (*i));
			return (1);
		}
	}
	return (0);
}

void	ft_is_redirecetions(t_list **arg)
{
	int	i;

	i = 0;
	while ((*arg)->quoted == 0 && (*arg)->content[i])
	{
		if (ft_tbd(arg, &i, '<') || ft_tbd(arg, &i, '>'))
			break ;
		else if ((*arg)->content[i] == '>' || (*arg)->content[i] == '<')
		{
			insert_allocat(arg, i);
			break ;
		}
		i++;
	}
}
