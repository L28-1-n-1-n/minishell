/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo      <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:57 by hlo               #+#    #+#             */
/*   Updated: 2019/01/07 00:07:58 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Malloc and set each field of a bitfield struct `t_flags` to 0.
*/

t_flags		*init_flags(void)
{
	t_flags		*new;

	if (!(new = (t_flags*)malloc(sizeof(*new))))
		return (NULL);
	new->hh = 0;
	new->h = 0;
	new->l = 0;
	new->ll = 0;
	new->lm = 0;
	new->dz = 0;
	new->f0 = 0;
	new->mo = 0;
	new->pl = 0;
	new->sp = 0;
	new->com = 0;
	new->prc = -1;
	new->pad = -1;
	new->c = '\0';
	new->base = 10;
	return (new);
}

/*
**	A special swap coded to swap bits from differents fields inside a bitfield.
*/

static void	swap_flag(t_flags *fl, char field)
{
	if (field == 'h')
	{
		fl->h ^= fl->hh;
		fl->hh ^= fl->h;
		fl->h ^= fl->hh;
	}
	else if (field == 'l')
	{
		fl->l ^= fl->ll;
		fl->ll ^= fl->l;
		fl->l ^= fl->ll;
	}
}

/*
**	Adding flags in struct `t_flags *fl`.
*/

void		add_flag(const char c, t_flags *fl)
{
	if (c == 'h')
		(fl->h == 0) ? fl->h = 1 : swap_flag(fl, 'h');
	else if (c == 'l')
		(fl->l == 0) ? fl->l = 1 : swap_flag(fl, 'l');
	else if (c == 'L')
		fl->lm = 1;
	else if (c == '#')
		fl->dz = 1;
	else if (c == '0')
		fl->f0 = 1;
	else if (c == '-')
		fl->mo = 1;
	else if (c == '+')
		fl->pl = 1;
	else if (c == ' ')
		fl->sp = 1;
	else if (c == ',')
		fl->com = 1;
}

/*
**	Malloc the main struct that contains the buffer and its len.
*/

t_buf		*init_buf(void)
{
	t_buf	*new;

	if (!(new = (t_buf*)malloc(sizeof(*new))))
		return (NULL);
	new->str = NULL;
	new->len = 0;
	return (new);
}
