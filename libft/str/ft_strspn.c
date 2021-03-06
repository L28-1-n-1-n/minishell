/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo      <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:22:13 by hlo               #+#    #+#             */
/*   Updated: 2019/03/21 14:22:14 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	len;

	len = 0;
	if (s && accept)
	{
		while (*s)
		{
			if (ft_strchr(accept, *s) == NULL)
				return (len);
			len++;
			s++;
		}
	}
	return (len);
}
