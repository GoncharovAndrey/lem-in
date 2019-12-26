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

int				read_map(avl_node *tree, avl_tree *root, char **link)
{
	char		*str;
	int			opr;
	char		**link_room;
	avl_node	*tmp[2];

	get_next_line(STDIN_FILENO, &str);
	root->ant = ft_atoi(str);
	free(str);
	while (get_next_line(STDIN_FILENO, &tree->str))
	{
		tree->name_room = ft_strsplit(tree->str, 32);
		if (!(opr = ft_check_map(&tree, root)))
			continue;
		else if (opr == 2)
			break;
		tree->link[0] = NULL;
		tree->link[1] = NULL;
		tree->bal = 0;
		tree->level = 0;
		tree->link_room = NULL;
		avl_insert(root, tree);
		tree++;
	}
	*link = tree->str;
	tree->str = NULL;
	link_room = ft_strsplit(*link, '-');
	tmp[0] = ft_find_room(link_room[0], root->root);
	tmp[1] = ft_find_room(link_room[1], root->root);
	ft_add_list(tmp[1], tmp[0]);
	ft_add_list(tmp[0], tmp[1]);
	link++;
	while (get_next_line(STDIN_FILENO, link))
	{
		link_room = ft_strsplit(*link, '-');
		tmp[0] = ft_find_room(link_room[0], root->root);
		tmp[1] = ft_find_room(link_room[1], root->root);
		ft_add_list(tmp[1], tmp[0]);
		ft_add_list(tmp[0], tmp[1]);
		/*надо будет вришить  link_room!!!!*/
		free(link_room[0]);
		free(link_room[1]);
		free(link_room);
		/* !!!!!!!!!!!!!!!!!!! */
		link++;
	}
	link = NULL;
	return 1;
}
