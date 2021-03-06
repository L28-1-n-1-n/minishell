/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:17:51 by hlo               #+#    #+#             */
/*   Updated: 2019/08/19 23:14:36 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_instr(const char c, const char *accept)
{
	while (*accept)
	{
		if (c == *accept)
			return (1);
		accept++;
	}
	return (0);
}
