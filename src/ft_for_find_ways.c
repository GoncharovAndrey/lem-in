/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_find_ways.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:52:44 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 17:52:46 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			ft_find_out(t_avl_tree *root)
{
	t_list_link	*tmp;
	int			i;

	i = 0;
	tmp = root->end->link_room;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	root->out = i + 2;
}

void			ft_delete_incld_way(t_ways *ways)
{
	int			i;
	t_list_link	*tmp;
	t_list_link	*del;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		ways[i].head = NULL;
		while (tmp)
		{
			del = tmp;
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp = tmp->next;
			if (del)
				free(del);
		}
		i++;
	}
}

void			ft_off_include_way(t_ways *ways)
{
	int			i;
	t_list_link	*tmp;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		while (tmp)
		{
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp->data->link_arr[0]->locked = 0;
			tmp = tmp->next;
		}
		i++;
	}
}
