/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:25:53 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/18 18:25:56 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int					ft_check_sharp_str(char *str)
{
	if (ft_strncmp("#", str, 1) == 0)
	{
		if (ft_strncmp("##", str, 2) == 0)
			ft_close_error();
		else
			return (1);
	}
	return (7);
}

void				ft_for_check_link(t_link *lk, char **tmp_l, t_avl_node *rt)
{
	t_list_link		*tmp_list;

	if (ft_strcmp(tmp_l[0], tmp_l[1]) < 0)
	{
		lk->link_arr[0] = ft_find_room(tmp_l[0], rt);
		lk->link_arr[1] = ft_find_room(tmp_l[1], rt);
	}
	else
	{
		lk->link_arr[0] = ft_find_room(tmp_l[1], rt);
		lk->link_arr[1] = ft_find_room(tmp_l[0], rt);
	}
	if (lk->link_arr[0] == lk->link_arr[1] ||
			!lk->link_arr[0] || !lk->link_arr[1])
		ft_close_error();
	tmp_list = lk->link_arr[0]->link_room;
	while (tmp_list)
	{
		if (tmp_list->data->link_arr[1] == lk->link_arr[1])
			ft_close_error();
		tmp_list = tmp_list->next;
	}
	ft_add_list(lk->link_arr[0], lk);
	ft_add_list(lk->link_arr[1], lk);
}

int					ft_check_link(t_lstr *prev, t_avl_tree *root)
{
	char			**tmp_link;

	if (!prev->str || !*(prev->str))
		ft_close_error();
	if (ft_check_sharp_str(prev->str) == 1)
		return (1);
	if (!(tmp_link = ft_strsplit(prev->str, '-')))
		ft_close_error();
	if (!tmp_link[0] || !tmp_link[1] || tmp_link[2])
		ft_close_error();
	ft_for_check_link(prev->link, tmp_link, root->root);
	ft_free_arr_str(&tmp_link);
	return (1);
}
