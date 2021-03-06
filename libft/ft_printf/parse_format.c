/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo      <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:42:23 by hlo               #+#    #+#             */
/*   Updated: 2019/01/24 19:42:24 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		clean_quit(char **scat, char **tmp, int ret)
{
	ft_strdel(scat);
	ft_strdel(tmp);
	return (ret);
}

/*
**	Function that is used to add content in *str when it is still
**	pointing to NULL.
**	3 return values :
**	 1 	:	Success.
**	 0 	:	Malloc failed.
**	-1	:	No keyword, the string can be print directly.
*/

static int		create_str(const char **format, t_buf *buf, int nxt_kwd)
{
	if (nxt_kwd > 0)
	{
		if (!(buf->str = ft_strndup(*format, nxt_kwd)))
			return (0);
	}
	else
	{
		if (!(buf->str = ft_strdup(*format)))
			return (0);
		buf->len += ft_strlen(buf->str);
		return (-1);
	}
	*format += nxt_kwd;
	buf->len += ft_strlen(buf->str);
	return (1);
}

/*
**	Function that is used to append content to *str.
**	2 return values :
**	 1 	:	Success.
**	 0 	:	Malloc failed.
**	-1	:	No keyword left, the string can be print directly.
*/

static int		append_str(const char **format, t_buf *buf, int nxt_kwd)
{
	char	*tmp;
	char	*scat;

	tmp = (char*)buf->str;
	if (nxt_kwd > 0)
	{
		if (!(scat = ft_strndup(*format, nxt_kwd)))
			return (0);
		if (!(buf->str = ft_memjoin(buf->str, buf->len, scat, ft_strlen(scat))))
			return (clean_quit(&scat, NULL, 0));
		buf->len += ft_strlen(scat);
		ft_strdel(&scat);
	}
	else
	{
		if (!(scat = ft_strdup(*format)))
			return (0);
		if (!(buf->str = ft_memjoin(buf->str, buf->len, scat, ft_strlen(scat))))
			return (clean_quit(&scat, &tmp, 0));
		buf->len += ft_strlen(scat);
		return (clean_quit(&scat, &tmp, 0));
	}
	*format += nxt_kwd;
	return (clean_quit(NULL, &tmp, 1));
}

int				parse_format(const char **format, t_buf *buf)
{
	int		nxt_kwd;
	char	*nxt_conv;
	char	*nxt_col;

	nxt_conv = ft_strchr(*format, '%');
	nxt_col = ft_strchr(*format, '{');
	if (nxt_col == NULL && nxt_conv == NULL)
		nxt_kwd = 0;
	else if (nxt_col && nxt_conv == NULL)
		nxt_kwd = nxt_col - *format;
	else if (nxt_col == NULL && nxt_conv)
		nxt_kwd = nxt_conv - *format;
	else
		nxt_kwd = ((nxt_col < nxt_conv) ? nxt_col : nxt_conv) - *format;
	if (buf->str == NULL)
		return (create_str(format, buf, nxt_kwd));
	return (append_str(format, buf, nxt_kwd));
}
