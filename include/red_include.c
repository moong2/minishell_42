/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_include.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:24:56 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:46:02 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include "../minishell.h"

t_red	*ft_rednew(char *file_name)
{
	t_red	*red;

	red = malloc(sizeof(t_red));
	if (red == 0)
		return (0);
	red->file_name = file_name;
	red->type = 0;
	red->next = NULL;
	return (red);
}

t_red	*ft_redlast(t_red *red)
{
	if (red == NULL)
		return (0);
	while (red->next != NULL)
		red = red->next;
	return (red);
}

void	ft_reddelone(t_red *red, void (*del)(void*))
{
	del(red->file_name);
	free(red);
}

void	ft_redclear(t_red **red, void (*del)(void*))
{
	t_red	*tmp;

	tmp = NULL;
	while (*red != NULL)
	{
		tmp = *red;
		*red = (*red)->next;
		ft_reddelone(tmp, del);
	}
	*red = NULL;
}

void	ft_redadd_back(t_red **red, t_red *new)
{
	t_red	*red1;

	if (*red == NULL)
	{
		*red = new;
		return ;
	}
	red1 = ft_redlast(*red);
	red1->next = new;
}
