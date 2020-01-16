/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 13:27:06 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/25 13:27:08 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

avl_node		*ft_find_room(char *str, avl_node *root)
{
	avl_node	*tmp;
	int			side;

	tmp = root;
	while (tmp)
	{
		if (!(side = ft_strcmp(str, tmp->name_room[0])))
			return (tmp);
		side = (side > 0);
		tmp = tmp->link[side];
	}
	return (NULL);
}

int				ft_read_ant(char *str)
{
	int			res;

	if (!str)
		ft_close_error();
	res = ft_atoi_max(str);
	if (res < 0)
		ft_close_error();
	return (res);
}

int				read_map(avl_tree *root)
{
	int			opr;
	t_lstr		*prev;

	prev = root->line;
	while (get_next_line(STDIN_FILENO, &prev->str) > 0)
	{
		if (ft_check_sharp_str(prev->str) != 1)
		{
			root->ant = ft_read_ant(prev->str);
			prev = ft_create_add_lstr(prev);
			break;
		}
		prev = ft_create_add_lstr(prev);
	}
	while (get_next_line(STDIN_FILENO, &prev->str) > 0)
	{
//		printf("%s\n", prev->str);
		opr = ft_check_room(&prev, root);
		if (opr == 1)
		{
			prev = ft_create_add_lstr(prev);
			prev->tree = ft_malloc_avl_node();
			continue;
		}
		else if (opr == 2)
			break;
		if (avl_insert(root, prev->tree) == 0)
			ft_close_error();
		prev = ft_create_add_lstr(prev);
		prev->tree = ft_malloc_avl_node();
	}
//	if (!root->start || !root->end || root->start == prev->tree || root->end == prev->tree)
//		ft_close_error();
	prev->link = ft_malloc_t_link();
	ft_check_link(prev, root);
	prev = ft_create_add_lstr(prev);
	prev->link = ft_malloc_t_link();
	while (get_next_line(STDIN_FILENO, &prev->str))
	{
//		printf("%s\n", prev->str);
		ft_check_link(prev, root);
		prev = ft_create_add_lstr(prev);
		prev->link = ft_malloc_t_link();
	}
	return (1);
}

//int				read_map(avl_node *tree, avl_tree *root, t_link *link)
//{
//	int			opr;
//
//	while (get_next_line(STDIN_FILENO, &tree->str) > 0)
//	{
//		if (ft_check_sharp_str(tree->str) != 1)
//		{
//			root->ant = ft_read_ant(tree->str);
//			tree++;
//			break;
//		}
//		tree++;
//	}
//	while (get_next_line(STDIN_FILENO, &tree->str) > 0)
//	{
//		opr = ft_check_room(tree, root);
//		if (opr == 1)
//		{
//			tree++;
//			continue;
//		}
//		else if (opr == 2)
//			break;
//		if (avl_insert(root, tree) == 0)
//			ft_close_error();
//		tree++;
//	}
//	if (!root->start || !root->end || root->start == tree || root->end == tree)
//		ft_close_error();
//	link->str = tree->str;
//	ft_check_link(link, root);
//	link++;
//	while (get_next_line(STDIN_FILENO, &link->str))
//	{
//		ft_check_link(link, root);
//		link++;
//	}
//	link->str = NULL;
//	return (1);
//}