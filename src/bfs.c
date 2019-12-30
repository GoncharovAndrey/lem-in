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

int			bfs(avl_tree *root)
{
	avl_node	**turn;
	size_t		next;
	size_t		end;
	int			level;
//	int			up_level;
	int			stts;
	int			i;
	list_link	*tmp;

	turn = (avl_node**)malloc(sizeof(avl_node*) * root->count +  1);
	ft_memset(turn, 0, sizeof(avl_node*) * root->count + 1);
	turn[0] = root->start;
	root->st++;
	stts = root->st;
	root->start->level++;
	next = 0;
	end = 0;
	level = root->start->level;
//	up_level = 1;
	while(turn[next])
	{
		if ((tmp = turn[next]->link_room))
		{
			while (tmp)
			{
				if (tmp->data->incld_in_way > -1)
				{
					if (tmp->data->link_arr[0] == turn[next] && tmp->data->status < stts &&
						tmp->data->incld_in_way == 0)
					{
						tmp->data->link_arr[0] = tmp->data->link_arr[1];
						tmp->data->link_arr[1] = turn[next];
					}
					i = tmp->data->incld_in_way;
					if (tmp->data->link_arr[i] != root->end)
					{
						if (tmp->data->link_arr[i]->level < turn[next]->level)
						{
							tmp->data->link_arr[i]->level = level;
							turn[++end] = tmp->data->link_arr[i];
							tmp->data->status = stts;
						}
					}
					else
					{
						tmp->data->status = stts;
						free(turn);
						return (1);
					}
//				if (tmp->data->link_arr[0]->level > tmp->data->link_arr[1]->level)
//					tmp->data->status = 0;
				}
				tmp = tmp->next;
			}
		}
		next++;
//		if (up_level == next)
//		{
//			up_level = end + 1;
//			level++;
//		}
	}
	free(turn);
	return (0);
}
