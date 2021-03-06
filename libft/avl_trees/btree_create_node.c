/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:23:32 by hlo               #+#    #+#             */
/*   Updated: 2019/03/21 14:23:34 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *data)
{
	t_btree	*node;

	if (!(node = (t_btree*)malloc(sizeof(*node))))
		return (NULL);
	node->data = data;
	node->height = 0;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
