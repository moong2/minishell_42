/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:46:00 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/19 20:38:03 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content, int quoted)
{
	t_list	*moh;

	moh = malloc(sizeof(t_list));
	if (moh == 0)
		return (0);
	moh->content = content;
	moh->quoted = quoted;
	moh->pipe_0 = 0;
	moh->next = NULL;
	return (moh);
}
