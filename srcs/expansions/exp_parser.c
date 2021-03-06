/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:05:12 by hlo               #+#    #+#             */
/*   Updated: 2020/07/10 15:20:31 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exp_parser(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->argv[i])
	{
		if (exp_tilde(shell, &shell->argv[i]) < 0 ||
				exp_param(shell, &shell->argv[i]) < 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
