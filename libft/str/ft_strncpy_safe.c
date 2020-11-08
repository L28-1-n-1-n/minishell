/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:56:05 by hlo               #+#    #+#             */
/*   Updated: 2019/08/20 18:51:24 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_safe(char *dest, const char *src, size_t n)
{
	if (n > 0)
	{
		ft_memcpy((void*)dest, (const void*)src, n - 1);
		dest[n - 1] = '\0';
	}
	return (dest);
}
