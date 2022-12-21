/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:50:47 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/20 14:09:04 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define STD_IN 0
# define STD_OUT 1
# define INFILE 10
# define OUTFILE 11
# define HERDOC 12
# define APPAND 13
# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"

# include <stdio.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <dirent.h>
# include <stdbool.h>
# include <paths.h>
# include "libft/libft.h"

int	g_exit_status;

typedef struct s_red
{
	char			*file_name;
	int				type;
	int				pipe_0;
	struct s_red	*next;
}					t_red;

typedef struct s_lex
{
	int		i;
	int		arglen;
	int		argstart;
}			t_lex;

typedef struct s_cmd
{
	char			**content;
	int				*quoted;
	int				*pipe;
	t_red			*red;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}				t_env;

// ft_env.c
void	ft_free_env(t_env *env);
void	print_env(t_env *env);
int		ft_env_cmd(t_env *env, char **content);
int		ft_start(char *s);
t_env	*ft_env(char **nv);

// env_utils.c
t_env	*ft_envnew(char *content, char *name);
t_env	*ft_envlast(t_env *env);
void	ft_envdelone(t_env *env, void (*del)(void*));
void	ft_envclear(t_env **env, void (*del)(void*));
void	ft_envadd_back(t_env **env, t_env *new);

#endif