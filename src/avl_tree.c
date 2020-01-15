/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:15:24 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/24 17:15:26 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

avl_node		***ft_init_tmp(avl_tree *root, avl_node *new_node)
{
	avl_node	***tmp;

	if (!(tmp = (avl_node ***)malloc(sizeof(avl_node**) * 2)))
		return (NULL);
	if (!(tmp[0] = (avl_node**)malloc(sizeof(avl_node*) * 5)))
	{
		free(tmp);
		return (NULL);
	}
	tmp[0][1] = root->root;
	tmp[0][3] = tmp[0][1];
	tmp[0][4] = new_node;
	tmp[1] = &root->root;
	return (tmp);
}

int				ft_search_insert_pos_avl(avl_node ***tmp, avl_tree *root)
{
	int			dir;

	while (tmp[0][3])
	{
		if (!(dir = ft_strcmp(tmp[0][4]->name_room[0],
				tmp[0][3]->name_room[0])))
			return (0);
		dir = (dir > 0);
		tmp[0][2] = tmp[0][3]->link[dir];
		if (tmp[0][2] == NULL)
		{
			tmp[0][3]->link[dir] = tmp[0][4];
			tmp[0][2] = tmp[0][4];
			root->count++;
			break ;
		}
		if (tmp[0][2]->bal != 0)
		{
			tmp[1] = &tmp[0][3]->link[dir];
			tmp[0][1] = tmp[0][2];
		}
		tmp[0][3] = tmp[0][2];
	}
	return (1);
}

void			ft_balans_avl(avl_node ***tmp)
{
	int			dir;

	dir = (ft_strcmp(tmp[0][4]->name_room[0], tmp[0][1]->name_room[0]) > 0);
	tmp[0][0] = tmp[0][1]->link[dir];
	tmp[0][3] = tmp[0][0];
	while (tmp[0][3] != tmp[0][2])
		if (ft_strcmp(tmp[0][4]->name_room[0], tmp[0][3]->name_room[0]) < 0)
		{
			tmp[0][3]->bal = -1;
			tmp[0][3] = tmp[0][3]->link[0];
		}
		else
		{
			tmp[0][3]->bal = 1;
			tmp[0][3] = tmp[0][3]->link[1];
		}
}

void			ft_free_tmp(avl_node ****tmp)
{
	free(*tmp[0]);
	free(*tmp);
}

int				avl_insert(avl_tree *root, avl_node *new_node)
{
	avl_node	***tmp;

	if (!new_node)
		return (0);
	if (!(tmp = ft_init_tmp(root, new_node)))
		return (0);
	if (tmp[0][1] == NULL)
	{
		root->root = new_node;
		root->count++;
		ft_free_tmp(&tmp);
		return (1);
	}
	if (!ft_search_insert_pos_avl(tmp, root))
	{
		ft_free_tmp(&tmp);
		return (0);
	}
	ft_balans_avl(tmp);
	if (ft_strcmp(tmp[0][4]->name_room[0], tmp[0][1]->name_room[0]) < 0)
		ft_left_rotation(tmp);
	else
		ft_right_rotation(tmp);
	ft_free_tmp(&tmp);
	return (1);
}
