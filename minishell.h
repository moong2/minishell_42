/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:03:54 by jeykim            #+#    #+#             */
/*   Updated: 2022/12/21 18:34:13 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"

# include <signal.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
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

// builtins
t_env	*ft_env(char **nv);
int		ft_start(char *s);

// lexing
int		lex(char *buff, t_list **arg, t_env *env);
// utils
char	*ft_substr_lex(char *s, unsigned int start, size_t end);

#endif