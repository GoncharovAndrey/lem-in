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
		{
			return (tmp);
		}
		side = (side > 0);
		tmp = tmp->link[side];
	}
	return (NULL);
}

int				ft_check_map(avl_node **tree, avl_tree *root)
{
	if (ft_strcmp("##start", (*tree)->name_room[0]) == 0)
	{
		root->start = ++*tree;
		return 0;
	}
	if (ft_strcmp("##end", (*tree)->name_room[0]) == 0)
	{
		root->end = ++*tree;
		return 0;
	}
	if (!(*tree)->name_room[1])
		return 2;
	return 1;
}

int				read_map(avl_node *tree, avl_tree *root, t_link *link)
{
	int			opr;
//	char		**link_room;
//	avl_node	*tmp[2];
	char		*str;
	get_next_line(STDIN_FILENO, &str);
	if ((root->ant = ft_atoi(str)) <= 0)
		return (0);
	free(str);
	//	tree++;
	while (get_next_line(STDIN_FILENO, &tree->str))
	{
		if (!(opr = ft_check_room(tree, root)))
			return (0);
		if (opr == 1)
		{
			tree++;
			continue;
		}
		else if (opr == 2)
			break;
		if (avl_insert(root, tree) == 0)
			return (0);
		tree++;
	}
	if (!root->start || !root->end || root->start == tree || root->end == tree)
		return (0);

	ft_free_arr_str(&tree->name_room);
	link->str = tree->str;
	tree->str = NULL;
	ft_check_link(link, root);
	link++;
//	return (0);
	while (get_next_line(STDIN_FILENO, &link->str))
	{
		ft_check_link(link, root);
		link++;
	}
	link->str = NULL;
	if (!root->start || !root->end)
		return (0);
//	exit(0);
	return 1;
}
