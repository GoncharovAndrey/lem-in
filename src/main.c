/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:59:49 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/23 16:59:51 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/lem_in.h>
#include <stdio.h>

int		main()
{
	avl_node	*tree;
	avl_tree	root;
	int			i;

	i = 0;
	tree = (avl_node*)malloc(sizeof(avl_node) * 40000);
	root.root = NULL;
	root.count = 0;
	while (i < 40000)
	{
		tree[i].name_room = ft_itoa(i + 1);
		tree[i].link[0] = NULL;
		tree[i].link[1] = NULL;
		tree[i].bal = 0;
		avl_insert(&root, &tree[i]);
		i++;
	}
	i = 0;
	avl_node *left;
	avl_node *right;
//	while (i < 99)
//	{
//		printf ("%s - ", tree[i].name_room);
//		left = tree[i].link[0];
//		right = tree[i].link[1];
//		if (left != NULL)
//			printf("l - {%s} ;", left->name_room);
//		if (right != NULL)
//			printf("r - {%s} ;", right->name_room);
//		printf("\n");
//		i++;
//	}
	printf("%s , %d\n", root.root->name_room, root.count);
	i = 0;
	avl_node *tmp;
	tmp = root.root;
	int side;
	int level;
	while (i < 40000)
	{
		tmp = root.root;
		level = 0;
		while (tmp)
		{
			if (!(side = ft_strcmp(tree[i].name_room, tmp->name_room)))
		{
//			printf("%s  {%d level}\n", tmp->name_room, level);
			break;
		}
			side = (side > 0);
			tmp = tmp->link[side];
			level++;
		}
		i++;
	}
	i = 0;
	while(i < 40000)
	{
		free(tree[i].name_room);
		i++;
	}
	free(tree);
	return 0;
}
