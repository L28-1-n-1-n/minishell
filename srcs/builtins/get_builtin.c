/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:38:25 by hlo               #+#    #+#             */
/*   Updated: 2019/11/12 11:22:31 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	get_builtin(const char *cmd)
{
	if (ft_strcasecmp(cmd, ECHO) == 0)
		return (&echo_builtin);
	if (ft_strcasecmp(cmd, EXIT) == 0)
		return (&exit_builtin);
	if (ft_strcasecmp(cmd, CD) == 0)
		return (&cd_builtin);
	if (ft_strcasecmp(cmd, ENV) == 0)
		return (&env_builtin);
	if (ft_strcasecmp(cmd, SETENV) == 0)
		return (&setenv_builtin);
	if (ft_strcasecmp(cmd, UNSETENV) == 0)
		return (&unsetenv_builtin);
	return (NULL);
}
