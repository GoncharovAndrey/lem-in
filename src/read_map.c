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
	return 1;
}


int				read_map(avl_node *tree, avl_tree *root)
{
	char		*str;
	get_next_line(STDIN_FILENO, &str);
	root->ant = ft_atoi(str);
	free(str);
	while (get_next_line(STDIN_FILENO, &tree->str))
	{
		tree->name_room = ft_strsplit(tree->str, 32);
		if (!ft_check_map(&tree, root))
			continue;
		tree->link[0] = NULL;
		tree->link[1] = NULL;
		tree->bal = 0;

		avl_insert(root, tree);
		tree++;
	}
	tree->str = NULL;
	return 1;
}
