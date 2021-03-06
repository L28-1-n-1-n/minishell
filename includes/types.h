/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:07:01 by hlo               #+#    #+#             */
/*   Updated: 2020/07/20 18:52:13 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "defines.h"

typedef enum	e_status
{
	STOPPED = 0,
	RUNNING
}				t_status;

typedef struct	s_vars
{
	char	*home;
}				t_vars;

typedef struct	s_envopts
{
	short	ignore_env;
	char	**unset_vars;
	size_t	len_unset_vars;
}				t_envopts;

/*
**	EXPANSIONS
*/

typedef struct	s_exp
{
	pid_t	pid;
	int		last_exit_status;
}				t_exp;

typedef struct	s_shell
{
	char		*path_bin[ARR_BUFF];
	char		*env[ARR_BUFF];
	t_vars		vars;
	char		**argv;
	char		*pathname;
	size_t		path_bin_size;
	size_t		argc;
	size_t		env_idx;
	t_exp		exps;
	t_status	status;
	t_bool		nl_required;
}				t_shell;

typedef int		(*t_builtin)(t_shell*);

#endif
