/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:51:28 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/21 18:37:37 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_envnew(char *content, char *name)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->name = name;
	env->content = content;
	env->next = NULL;
	return (env);
}

t_env	*ft_envlast(t_env *env)
{
	if (env == NULL)
		return (0);
	while (env->next != NULL)
		env = env->next;
	return (env);
}

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*env1;

	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	env1 = ft_envlast(*env);
	env1->next = new;
}
