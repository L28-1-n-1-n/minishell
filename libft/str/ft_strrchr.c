/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:38:00 by hlo               #+#    #+#             */
/*   Updated: 2019/11/15 12:53:22 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*rchr;

	rchr = NULL;
	while (*s)
	{
		if (*s == c)
			rchr = s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return ((char*)rchr);
}
