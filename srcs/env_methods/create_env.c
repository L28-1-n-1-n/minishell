/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:43:11 by hlo               #+#    #+#             */
/*   Updated: 2020/07/15 15:24:33 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Increment SHLVL if exists or set it to 1 if not
*/

static void	increment_shell_level(t_shell *shell)
{
	char	*shell_lvl_content;
	int		shell_lvl;

	if ((shell_lvl_content = get_var_content("SHLVL", shell->env)))
	{
		shell_lvl = ft_atoi(shell_lvl_content) + 1;
		if ((shell_lvl_content = ft_itoa(shell_lvl)))
		{
			upsert_env(shell, "SHLVL", shell_lvl_content);
			ft_strdel(&shell_lvl_content);
		}
	}
	else
		upsert_env(shell, "SHLVL", "1");
}

static void	ensure_minimal_env(t_shell *shell)
{
	char	cwd[256];

	increment_shell_level(shell);
	if (getcwd(cwd, sizeof(cwd)))
		upsert_env(shell, "PWD", cwd);
}

int			create_env(t_shell *shell, char **const env)
{
	size_t	i;

	i = 0;
	while (env[i] && i < ARR_BUFF)
	{
		if (!(shell->env[i] = ft_strdup(env[i])))
		{
			shell->env_idx = i;
			free_env(shell->env, shell->env_idx);
			return (FAILURE);
		}
		i++;
	}
	shell->env_idx = i;
	ensure_minimal_env(shell);
	return (SUCCESS);
}
