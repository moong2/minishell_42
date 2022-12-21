/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:49:19 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/21 18:36:25 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_start(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '=')
			return (i);
	}
	return (0);
}

t_env	*ft_env(char **nv)
{
	int		i;
	int		start;
	t_env	*env;

	i = -1;
	env = NULL;
	while (nv[++i])
	{
		start = ft_start(nv[i]);
		ft_envadd_back(&env, ft_envnew(ft_substr_lex(nv[i], start, \
		ft_strlen(nv[i])), ft_substr_lex(nv[i], 0, start - 1)));
		if (ft_strcmp(ft_envlast(env)->name, "SHLVL") == 0)
			ft_envlast(env)->content[0]++;
	}
	if (!env)
	{
		ft_envadd_back(&env, ft_envnew(getcwd(NULL, 0), ft_strdup("PWD")));
		ft_envadd_back(&env, ft_envnew(ft_strdup("1"), ft_strdup("SHLVL")));
		ft_envadd_back(&env, ft_envnew(ft_strdup("/usr/bin/env"), \
		ft_strdup("_")));
	}
	ft_envadd_back(&env, ft_envnew(ft_strdup(PATH), ft_strdup("SPATH")));
	return (env);
}
