/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:30:53 by hlo               #+#    #+#             */
/*   Updated: 2020/07/15 11:43:13 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_accessible(const char *pathname)
{
	return (access(pathname, F_OK | X_OK) >= 0);
}

/*
**	Returns a malloc'ed string corresponding to the file pathname
**	or NULL if the filename is not found.
*/

char	*access_file(const char *path, const char *filename)
{
	char	*pathname;

	if (!(pathname = glue_str(path, filename, '/')))
	{
		throw_err_msg("malloc() failed");
		return (NULL);
	}
	if (!is_accessible(pathname))
	{
		ft_strdel(&pathname);
		return (NULL);
	}
	return (pathname);
}
