/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:22:24 by hlo               #+#    #+#             */
/*   Updated: 2020/07/10 14:12:20 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_path(char *env[ARR_BUFF], t_shell *shell)
{
	size_t	i;
	size_t	j;

	if ((i = get_var_idx("PATH", env)) == 0xDEADBABE)
		return (MINOR_ERROR);
	j = 4;
	while (env[i][j++] && shell->path_bin_size < ARR_BUFF)
	{
		if (!(shell->path_bin[shell->path_bin_size++] = ft_strcdup(&env[i][j],
			PATH_DELIMITER)))
		{
			ft_tabdel((void**)shell->path_bin, shell->path_bin_size);
			shell->path_bin_size = 0;
			return (FAILURE);
		}
		while (env[i][j] && env[i][j] != ':')
			j++;
	}
	return (SUCCESS);
}
