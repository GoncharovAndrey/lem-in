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

list_link		*pave_the_way(avl_tree *root)
{
	list_link	*tmp;
	avl_node	*tmp_room;
	list_link	*ret;
	list_link	*tmp_list;

	tmp_room = root->end;
	ret = NULL;
	while (tmp_room != root->start)
	{
		tmp = tmp_room->link_room;
		while (tmp->data->status != root->st || \
			tmp->data->link_arr[1 - tmp->data->incld_in_way] == tmp_room || \
				tmp->data->incld_in_way  < 0)
			tmp = tmp->next;
		tmp_list = ft_create_list(tmp->data);
		tmp_list->next = ret;
		ret = tmp_list;
		tmp_room = tmp->data->link_arr[1 - tmp->data->incld_in_way];
		if (tmp->data->incld_in_way == 1)
			tmp->data->incld_in_way = -1;
	}
	return (ret);
}

list_link		*pave_the_way_finish(avl_tree *root)
{
	list_link	*tmp;
	avl_node	*tmp_room;
	list_link	*ret;
	list_link	*tmp_list;

	tmp_room = root->end;
	ret = NULL;
	while (tmp_room != root->start)
	{
		tmp = tmp_room->link_room;
		while (tmp->data->status != root->st || \
			tmp->data->link_arr[1 - tmp->data->incld_in_way] == tmp_room || \
				tmp->data->incld_in_way  < 0 || tmp->data->link_arr[1]->locked == 1)
			tmp = tmp->next;
		tmp_list = ft_create_list(tmp->data);
		tmp_list->next = ret;
		ret = tmp_list;
		tmp_room = tmp->data->link_arr[1 - tmp->data->incld_in_way];
		if (tmp_room != root->start)
			tmp_room->locked = 1;
	}
	return (ret);
}
