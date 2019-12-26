/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pave_the_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:01:51 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/26 18:01:53 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

avl_node		***pave_the_way(avl_tree *root)
{
	list_link	*tmp;
	list_link	*short_way;
	avl_node	***ways;
	avl_node	*tmp_an;
	size_t		i;
	size_t		y;
	int			size;

	size = 0;
	i = 0;
	short_way = NULL;
	tmp = root->end->link_room;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	ways = (avl_node***)malloc(sizeof(avl_node**) * size);
	ft_memset(ways, 0, sizeof(avl_node**) * size);
	tmp = root->end->link_room;
	while (0 < size)
	{
		tmp = root->end->link_room;
		short_way = NULL;
		while (tmp && (!tmp->data->level || tmp->incld_in_way))
			tmp = tmp->next;
		if (tmp)
			short_way = tmp;
		while (tmp)
		{
			if (short_way->data->level > tmp->data->level && !tmp->incld_in_way)
				short_way = tmp;
			tmp = tmp->next;
		}
		if (short_way)
		{
			y = 0;
			ways[i] = (avl_node**)malloc(sizeof(avl_node*) * short_way->data->level + 1);
			ft_memset(ways[i], 0, sizeof(avl_node*) * short_way->data->level + 1);
			tmp_an = root->end;
			ways[i][y++] = tmp_an;
			while (short_way->data != root->start)
			{
				short_way->incld_in_way = 1;
				tmp_an = short_way->data;
				short_way = tmp_an->link_room;
				while (short_way && (short_way->data->level >= tmp_an->level || short_way->data->level == 0 || short_way->incld_in_way == 1))
					short_way = short_way->next;
				if (!short_way)
				{
					free(ways[i]);
					ways[i] = NULL;
					i--;
					break;
				}
				ways[i][y++] = tmp_an;
			}
			i++;
		}
		else
			return (ways);
		size--;
	}
	return (ways);
}
