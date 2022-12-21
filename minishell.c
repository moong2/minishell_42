/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:50:15 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/20 17:42:34 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_line(char *buff, t_env *env)
{
	t_list	*arg;
	t_cmd	*cmd;

	arg = NULL;
	if (buff[0])
	{
		add_history(buff);
		if (lex(buff, &arg, env) || only_space(arg))
			ft_lstclear(&arg, free);
		else
		{
			ft_wildcard(&arg);
			cmd = split_pipe(arg);
			redirections_parser(cmd);
			exec_all(cmd, &env);
			signal(SIGINT, handler);
			ft_lstclear(&arg, free);
			ft_cmdclear(&cmd, free);
		}
	}
}

void	handler(int signo)
{
	if (signo == SIGINT)
		write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 1;
}

int	main(int ac, char **av, char **nv)
{
	char	*buff;
	t_env	*env;

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	(void) ac;
	(void) av;
	ac = 0;
	av = NULL;
	env = ft_env(nv);
	while (1)
	{
		buff = readline("minishell:~$ ");
		if (!buff)
		{
			ft_free_env(env);
			printf("exit\n");
			exit(0);
		}
		check_line(buff, env);
		free(buff);
	}
	return (0);
}
