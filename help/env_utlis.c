/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:38 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/20 14:07:13 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_envnew(char *content, char *name)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == 0)
		return (NULL);
	env->name = name;
	env->content = content;
	env->next = NULL;
	return (env);
}

t_env	*ft_envlast(t_env *env)
{
	if (env == NULL)
		return (NULL);
	while (env->next != NULL)
		env = env->next;
	return (env);
}

void	ft_envdelone(t_env *env, void (*del)(void*))
{
	del(env->name);
	del(env->content);
	free(env);
}

void	ft_envclear(t_env **env, void (*del)(void*))
{
	t_env	*tmp;

	tmp = NULL;
	while (*env != NULL)
	{
		tmp = *env;
		*env = (*env)->next;
		ft_envdelone(tmp, del);
	}
	*env = NULL;
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
