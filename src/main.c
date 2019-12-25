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
	char		**link;
	int			i;

	i = 0;
	tree = (avl_node*)malloc(sizeof(avl_node) * 40000);
	link = (char**)malloc(sizeof(char*) * 40000);
	root.root = NULL;
	root.count = 0;
	read_map(tree, &root, link);
//	while (get_next_line(STDIN_FILENO, &tree[i].str))
//	{
//		tree[i].name_room = ft_strsplit(tree[i].str, 32);
//		tree[i].link[0] = NULL;
//		tree[i].link[1] = NULL;
//		tree[i].bal = 0;
//		avl_insert(&root, &tree[i]);
//		i++;
//	}
//	i = 0;
//	avl_node *left;
//	avl_node *right;
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
	i = 0;
	avl_node *tmp;
	tmp = root.root;
	int side;
	int level;
	while (i < root.count)
	{
		tmp = root.root;
		level = 0;
		while (tmp)
		{
			if (!(side = ft_strcmp(tree[i].name_room[0], tmp->name_room[0])))
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
	while (tree[i].str)
		ft_putendl(tree[i++].str);
	i = 0;
	while (link[i])
		ft_putendl(link[i++]);
	printf("%d   start - %s , end - %s \n", root.ant, root.start->name_room[0], root.end->name_room[0]);
	printf("count - %d\n", root.count);


	list_link	*tmp2;

	tmp2 = tree[1378].link_room;
	printf("%s - ", tree[1378].name_room[0]);
	while (tmp2)
	{
		printf("  {%s}  ", tmp2->data->name_room[0]);
		tmp2 = tmp2->next;
	}
	printf("\n");

	i = 0;
	while(i < root.count + 2)
	{
		free(tree[i].name_room);
		ft_delete_list(tree[i].link_room);
		i++;
	}
	i = 0;
	while(i < root.count + 2)
	{
		free(link[i]);
		i++;
	}
	free(tree);
	free(link);
	return 0;
}
