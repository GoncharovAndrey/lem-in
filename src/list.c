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

list_link		*ft_create_list(t_link *data)
{
	list_link	*node;

	if (!(node = (list_link*)malloc(sizeof(list_link))))
		return (NULL);
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

int				ft_add_list(avl_node *room, t_link *data)
{
	list_link	*node;

	if (!(node = ft_create_list(data)))
		ft_close_error();
	node->next = room->link_room;
	room->link_room = node;
	return (1);
}

avl_node 		*ft_malloc_avl_node(void)
{
	avl_node	*tmp;

	if (!(tmp = (void*)malloc(sizeof(avl_node))))
		ft_close_error();
	memset(tmp, 0, sizeof(avl_node));
//	tmp->name_room = str;
	return (tmp);
}

t_link		*ft_malloc_t_link(void)
{
	t_link	*tmp;

	if (!(tmp = (void*)malloc(sizeof(t_link))))
		ft_close_error();
	memset(tmp, 0, sizeof(t_link));
	return (tmp);
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










