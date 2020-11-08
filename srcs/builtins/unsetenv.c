/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:09:45 by hlo               #+#    #+#             */
/*   Updated: 2020/07/10 14:05:28 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			unsetenv_builtin(t_shell *shell)
{
	size_t	i;

	i = 1;
	while (i < shell->argc)
	{
		del_entry_env(shell, shell->argv[i]);
		i++;
	}
	shell->exps.last_exit_status = 0;
	return (SUCCESS);
}
