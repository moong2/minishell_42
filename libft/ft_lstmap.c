/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:26:56 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/19 20:37:14 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (lst)
	{
		res = ft_lstnew(f(lst->content), 0);
		if (!res)
		{
			ft_lstclear(&res, del);
			return (res);
		}
		res->next = ft_lstmap(lst->next, f, del);
		return (res);
	}
	return (NULL);
}
