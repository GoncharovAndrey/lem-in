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

void			ft_delete_incld_way(list_link **ways)
{
	int			i;
	list_link	*tmp;

	i = 0;
	while (ways[i])
	{
		tmp = ways[i];
		while (tmp)
		{
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

int		main()
{
	avl_node	*tree;
	avl_tree	root;
	t_link		*link;
	int			i;
	int			l;
	int			s;
	list_link	*ways[100][100] = {NULL};
	list_link	*tmpw;

	i = 0;
	l = 0;
	s = 0;
	tree = (avl_node*)malloc(sizeof(avl_node) * 40000);
	link = (t_link*)malloc(sizeof(t_link) * 40000);
	root.root = NULL;
	root.count = 0;
	root.st = 0;
	read_map(tree, &root, link);
//	bfs(&root);
//	ways = pave_the_way(&root);
//	ways = pave_the_way(&root);
	while (bfs(&root))
	{
		i = 0;
//		while (link[i].str)
//		{
//			printf("[%d] %s   {%s -  %s}\n", link[i].status, link[i].str, link[i].link_arr[0]->name_room[0], link[i].link_arr[1]->name_room[0]);
//			i++;
//		}
		ways[s][l] = pave_the_way(&root);
		tmpw = ways[s][l];
		while (tmpw)
		{
			if (tmpw->data->incld_in_way != -1)
				tmpw->data->incld_in_way = 1;
			else
			{
				ft_delete_incld_way(ways[s]);
				s++;
				l = -1;
				break;
			}
//			printf("%d %s {ways[%d]}\n", tmpw->data->incld_in_way, tmpw->data->str, s);
			tmpw = tmpw->next;
		}
		l++;
//		printf("krug\n");
	}
	l = 0;
	while (ways[s][l])
	{
		tmpw = ways[s][l];
//		printf("%d\n", l);
		i = 0;
		while (tmpw)
		{
//			printf("%s {ways[%d]}\n", tmpw->data->str, s);
			tmpw = tmpw->next;
			i++;
		}
		printf("%d\n", i);
		l++;
	}
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
//	list_link	*tmp2;
//
//	tmp2 = tree[3].link_room;
//	printf("%s - ", tree[3].name_room[0]);
//	while (tmp2)
//	{
//		printf("  {%s - %s }  ", tmp2->data->link_arr[0]->name_room[0], tmp2->data->link_arr[1]->name_room[0]);
//		if (tmp2->data->status == root.st)
//			printf("\nstatus 0  level %d \n" , tmp2->data->link_arr[1]->level);
//		tmp2 = tmp2->next;
//	}
//	printf("\n");
///*                                 */

//	i = 0;
//	while (link[i].str)
//	{
//		printf("[%d] %s   {%s -  %s}\n", link[i].status, link[i].str, link[i].link_arr[0]->name_room[0], link[i].link_arr[1]->name_room[0]);
//		i++;
//	}

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
