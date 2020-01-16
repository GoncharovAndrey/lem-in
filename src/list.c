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

t_list_link		*ft_create_list(t_link *data)
{
	t_list_link	*node;

	if (!(node = (t_list_link*)malloc(sizeof(t_list_link))))
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void			ft_delete_list(t_list_link *head)
{
	t_list_link	*tmp;

	tmp = head;
	while (tmp)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}

int				ft_add_list(t_avl_node *room, t_link *data)
{
	t_list_link	*node;

	if (!(node = ft_create_list(data)))
		ft_close_error();
	node->next = room->link_room;
	room->link_room = node;
	return (1);
}

t_lstr			*ft_create_add_lstr(t_lstr *prev)
{
	t_lstr		*new;

	if (!(new = (t_lstr*)malloc(sizeof(t_lstr))))
		ft_close_error();
	memset(new, 0, sizeof(t_lstr));
	if (!prev)
		return (new);
	prev->next = new;
	return (new);
}
