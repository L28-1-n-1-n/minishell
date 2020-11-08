/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo      <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:18:41 by hlo               #+#    #+#             */
/*   Updated: 2018/11/08 18:07:07 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
			|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (1);
	if (c == 32)
		return (1);
	return (0);
}
