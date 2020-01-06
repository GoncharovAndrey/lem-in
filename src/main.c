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

t_ant			*ft_init_ant(avl_tree *root)
{
	t_ant		*ant;
	int			i;

	i = 0;
	ant = (t_ant*)malloc(sizeof(t_ant) * (root->ant + 2));
	while (i < root->ant)
	{
		ant[i].day = 0;
		ant[i].head = NULL;
		ant[i].ant_name = i;
		i++;
	}
	return (ant);
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
	t_ant		*ant;
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
	printf("%d  %d\n", ind, ways[ind].steps);
	i = 0;
	kol = 0;
	while (i <= ind)
	{
		ways[i].status = ways[ind].steps - ways[i].steps + 1;
		kol += ways[i].status;
		i++;
	}
	printf("%d\n", kol);
	while (kol < root.ant)
	{
		if (i > ind)
			i = 0;
		ways[i].status++;
		i++;
		kol++;
	}
	printf("%d   %d\n", ways[0].status, ways[ind].status);
	kol = 1;
	i = 0;
	int	d;
	d = 1;
	ant = ft_init_ant(&root);
	while (kol <= root.ant)
	{
		if (ways[i].status == 0)
		{
			i = 0;
			d++;
		}
		ant[kol].head = ways[i].head;
		ways[i].status--;
		ant[kol].day = d;
		kol++;
		i++;
	}
	printf("%d  %d\n", ant[13].day,ant[15].day);









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
