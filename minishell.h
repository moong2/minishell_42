/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:50:47 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/19 20:35:40 by jeykim           ###   ########.fr       */
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

#endif