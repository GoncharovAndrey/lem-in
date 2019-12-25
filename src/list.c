/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:47:09 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/25 17:47:11 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

list_link		*ft_create_list(avl_node *data)
{
	list_link	*node;

	node = (list_link*)malloc(sizeof(list_link));
	node->data = data;
	node->next = NULL;
	return node;
}

void			ft_delete_list(list_link *head)
{
	list_link	*tmp;

	tmp = head;
	while (tmp)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}

int				ft_add_list(avl_node *data, avl_node *room)
{
	list_link	*node;

	node =ft_create_list(data);
	node->next = room->link_room;
	room->link_room = node;
	return 1;
}
