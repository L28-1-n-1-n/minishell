/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:03:58 by hlo               #+#    #+#             */
/*   Updated: 2020/07/10 15:10:39 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	tilde_replacing(t_shell *shell, char **str,
				char *tilde, const char *var)
{
	char	*tmp;
	char	*content;

	tmp = *str;
	if (!(content = get_var_content(var, shell->env)))
		return (FAILURE);
	if (!(*str = replace_substr(*str, tilde, content)))
		return (FAILURE);
	ft_strdel(&tmp);
	return (SUCCESS);
}

int			exp_tilde(t_shell *shell, char **str)
{
	char	*tilde;

	tilde = ft_strchr(*str, '~');
	if (tilde)
	{
		if (tilde[1] == '/' || tilde[1] == '\0')
			return (tilde_replacing(shell, str, "~", "HOME"));
		else if (tilde[1] == '+')
			return (tilde_replacing(shell, str, "~+", "PWD"));
		else if (tilde[1] == '-')
			return (tilde_replacing(shell, str, "~-", "OLDPWD"));
		else
			return (throw_error(shell, "~",
					"no such named directory", CMD_ERROR));
	}
	else
		return (SUCCESS);
}
