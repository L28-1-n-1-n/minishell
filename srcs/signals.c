/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:49:48 by hlo               #+#    #+#             */
/*   Updated: 2020/07/15 12:54:18 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_fork(int signum)
{
	(void)signum;
	ft_printf("\n");
}

void	sigint_core(int signum)
{
	(void)signum;
	ft_printf("\n");
	display_prompt(NULL);
}
