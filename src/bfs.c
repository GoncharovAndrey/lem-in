/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:11:45 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/26 16:11:49 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			bfs(avl_tree *root)
{
	avl_node	**turn;
	size_t		next;
	size_t		end;
	int			level;
	int			up_level;
	list_link	*tmp;

	turn = (avl_node**)malloc(sizeof(avl_node*) * root->count +  1);
	ft_memset(turn, 0, sizeof(avl_node*) * root->count + 1);
	turn[0] = root->start;
	root->start->level = 1;
	next = 0;
	end = 0;
	level = 2;
	up_level = 1;
	while(turn[next])
	{
		if ((tmp = turn[next]->link_room))
		{
			while (tmp)
			{
				if (tmp->data->link_arr[0] == turn[next] && tmp->data->status == -1)
				{
					tmp->data->link_arr[0] = tmp->data->link_arr[1];
					tmp->data->link_arr[1] = turn[next];
				}
				if (tmp->data->link_arr[0] != root->end)
				{
					if (!tmp->data->link_arr[0]->level)
					{
						tmp->data->link_arr[0]->level = level;
						turn[++end] = tmp->data->link_arr[0];
					}
				}
				else
				{
					tmp->data->status = 0;
					free(turn);
					return;
				}
				if (tmp->data->link_arr[0]->level > tmp->data->link_arr[1]->level)
					tmp->data->status = 0;
				tmp = tmp->next;
			}
		}
		next++;
		if (up_level == next)
		{
			up_level = end + 1;
			level++;
		}
	}
	free(turn);
}
