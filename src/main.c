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

void			ft_delete_incld_way(t_ways *ways)
{
	int			i;
	list_link	*tmp;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		ways[i].head = NULL;
		while (tmp)
		{
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

t_ways			*ft_init_ways(avl_tree *root)
{
	t_ways		*ways;
	int			i;
	int			y;
	list_link	*tmp;

	i = 0;
	y = 0;
	tmp = root->end->link_room;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	ways = (t_ways*)malloc(sizeof(t_ways) * (++i));
	while (y < i)
	{
		ways[y].status = 0;
		ways[y].steps = 0;
		ways[y].head =NULL;
		y++;
	}
	return (ways);
}

int		main()
{
	avl_node	*tree;
	avl_tree	root;
	t_link		*link;
	int			i;
	int			l;
	int			s;
	t_ways		*ways;
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
	ways = ft_init_ways(&root);
	while (bfs(&root))
	{
//		while (link[i].str)
//		{
//			printf("[%d] %s   {%s -  %s}\n", link[i].status, link[i].str, link[i].link_arr[0]->name_room[0], link[i].link_arr[1]->name_room[0]);
//			i++;
//		}
		ways[l].head = pave_the_way(&root);
		tmpw = ways[l].head;
		while (tmpw)
		{
			if (tmpw->data->incld_in_way != -1)
				tmpw->data->incld_in_way = 1;
			else
			{
				ft_delete_incld_way(ways);
				l = -1;
				break;
			}
//			printf("%d %s {ways[%d]}\n", tmpw->data->incld_in_way, tmpw->data->str, s);
			tmpw = tmpw->next;
		}
		l++;
//		printf("krug\n");
	}
	ft_delete_incld_way(ways);
	l = 0;
	while (bfs(&root))
	{
		ways[l].head = pave_the_way_finish(&root);
		tmpw = ways[l].head;
		while (tmpw)
		{
			tmpw->data->incld_in_way = 1;
			tmpw = tmpw->next;
		}
		l++;
	}


	l = 0;
	while (ways[l].head)
	{
		tmpw = ways[l].head;
//		printf("     begin ----  %d\n", l);
		i = 0;
		while (tmpw)
		{
//			printf("%s {ways[%d]}\n", tmpw->data->str, s);
			tmpw = tmpw->next;
			i++;
		}
		ways[l].steps = i;
//		printf(" ---- steps %d   ---\n\n", ways[l].steps);
		l++;
	}

	int		kol;
	int		ind;

	kol = 0;
	l = 0;
	ways[0].status = 1;
	ind = 0;
	while (ways[ind].head && kol < root.ant)
	{
		kol = 0;
		l = 0;
		while (ways[l].head && ways[l].status == 1)
			kol += ways[ind].steps - ways[l++].steps + 1;
		if (kol == root.ant || !ways[ind + 1].head)
			break;
		if (ways[ind].head && kol < root.ant )
			ways[++ind].status = 1;
		else
			ways[--ind].status = 0;
	}
	printf("%d\n", ind);
	l = 0;
	kol = 0;
	while (ways[l].status > 0)


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
