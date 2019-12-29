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

#include "../includes/lem_in.h"
#include <stdio.h>

int		main()
{
	avl_node	*tree;
	avl_tree	root;
	t_link		*link;
	int			i;
	avl_node	***ways;

	i = 0;
	tree = (avl_node*)malloc(sizeof(avl_node) * 40000);
	link = (t_link*)malloc(sizeof(t_link) * 40000);
	root.root = NULL;
	root.count = 0;
	read_map(tree, &root, link);
	bfs(&root);
//	ways = pave_the_way(&root);
////	while (get_next_line(STDIN_FILENO, &tree[i].str))
////	{
////		tree[i].name_room = ft_strsplit(tree[i].str, 32);
////		tree[i].link[0] = NULL;
////		tree[i].link[1] = NULL;
////		tree[i].bal = 0;
////		avl_insert(&root, &tree[i]);
////		i++;
////	}
////	i = 0;
////	avl_node *left;
////	avl_node *right;
////	while (i < 99)
////	{
////		printf ("%s - ", tree[i].name_room);
////		left = tree[i].link[0];
////		right = tree[i].link[1];
////		if (left != NULL)
////			printf("l - {%s} ;", left->name_room);
////		if (right != NULL)
////			printf("r - {%s} ;", right->name_room);
////		printf("\n");
////		i++;
////	}
//	i = 0;
//	avl_node *tmp;
//	tmp = root.root;
//
//
//	/*  pechyat karty  */
////	i = 0;
////	while (tree[i].str)
////		ft_putendl(tree[i++].str);
////	i = 0;
////	while (link[i])
////		ft_putendl(link[i++]);
////	printf("%d   start - %s , end - %s \n", root.ant, root.start->name_room[0], root.end->name_room[0]);
////	printf("count - %d\n", root.count);
///*                        */
//
//
//
//
//
///*   prosmotr svyazey   */
	list_link	*tmp2;

	tmp2 = tree[3].link_room;
	printf("%s - ", tree[3].name_room[0]);
	while (tmp2)
	{
		printf("  {%s - %s }  ", tmp2->data->link_arr[0]->name_room[0], tmp2->data->link_arr[1]->name_room[0]);
		if (tmp2->data->status == 0)
			printf("\nstatus 0  level %d \n" , tmp2->data->link_arr[1]->level);
		tmp2 = tmp2->next;
	}
	printf("\n");
///*                                 */
//
//	int x = 0;
//	int y = 0;
//	while(ways[x])
//	{
//		y = 0;
//		printf("%p\n", ways[x]);
//		while (ways[x] && ways[x][y])
//		{
//			printf("%s   ", ways[x][y]->name_room[0]);
//			y++;
//		}
//		printf("\n");
//		x++;
//	}
//
//
//
////	list_link *ltmp;
////	ltmp = tree[4].link_room;
////	printf("%s   ", tree[4].name_room[0]);
////	while (ltmp)
////	{
////		printf("%d  ", ltmp->incld_in_way);
////		ltmp = ltmp->next;
////	}
//

/*      фришим всю память */
	i = 0;
	while(i < root.count + 2)
	{
		free(tree[i].name_room);
		ft_delete_list(tree[i].link_room);
		i++;
	}
	i = 0;
	while(link[i].str)
	{
		free(link[i].str);
		i++;
	}
	free(tree);
	free(link);
/*          !!!!!!!!!!!!!             */
	return 0;
}
