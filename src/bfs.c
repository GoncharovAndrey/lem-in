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

static void			ft_prev_bfs(t_turn *queue)
{
	queue->next = 0;
	queue->last = 0;
	queue->lvl_rm++;
	queue->lvl_lnk++;
	queue->turn[0] = queue->start;
	queue->turn[1] = NULL;
	queue->start->level = queue->lvl_rm;
}

static void			ft_swap_link_arr(t_turn *queue, t_link *data)
{
	data->link_arr[0] = data->link_arr[1];
	data->link_arr[1] = queue->turn[queue->next];
}

static int			ft_check_link_bfs(t_turn *queue, t_list_link *tmp)
{
	int				i;

	if (tmp->data->link_arr[0] == queue->turn[queue->next] &&
			tmp->data->status < queue->lvl_rm && tmp->data->incld_in_way == 0)
		ft_swap_link_arr(queue, tmp->data);
	i = tmp->data->incld_in_way;
	if (tmp->data->link_arr[i] != queue->end)
	{
		if (tmp->data->link_arr[i]->level < queue->lvl_rm &&
				tmp->data->link_arr[i]->locked != 1)
		{
			tmp->data->link_arr[i]->level = queue->lvl_rm;
			queue->last++;
			queue->turn[queue->last] = tmp->data->link_arr[i];
			queue->turn[queue->last + 1] = NULL;
			tmp->data->status = queue->lvl_lnk;
		}
	}
	else
	{
		tmp->data->status = queue->lvl_lnk;
		return (1);
	}
	return (0);
}

int					bfs(t_turn *queue)
{
	t_list_link		*tmp;

	ft_prev_bfs(queue);
	while (queue->turn[queue->next])
	{
		if ((tmp = queue->turn[queue->next]->link_room))
		{
			while (tmp)
			{
				if (tmp->data->incld_in_way > -1)
				{
					if (ft_check_link_bfs(queue, tmp))
						return (1);
				}
				tmp = tmp->next;
			}
		}
		queue->next++;
	}
	return (0);
}
