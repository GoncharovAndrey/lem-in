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
	list_link	*del;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		ways[i].head = NULL;
		while (tmp)
		{
			del = tmp;
			if (tmp->data == NULL)
				printf("Error 2\n");
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp = tmp->next;
			if (del)
				free(del);
		}
		i++;
	}
}

void			ft_off_include_way(t_ways *ways)
{
	int			i;
	list_link	*tmp;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		while (tmp)
		{
//			printf("%p  tmp->data error\n", tmp->data);
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

t_ways			**ft_init_ways(avl_tree *root)
{
	t_ways		**ways;
	int			i;
	int			y;
	int			r;
	list_link	*tmp;

	i = 0;
	y = 0;
	r = 0;
	tmp = root->end->link_room;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
//	printf("%d -i\n", i);
	ways = (t_ways**)malloc(sizeof(t_ways*) * 100);
	while (r < 100)
	{
		ways[r] = (t_ways *) malloc(sizeof(t_ways) * (i + 2));
		y = 0;
		while (y < i)
		{
			ways[r][y].status = 0;
			ways[r][y].steps = 0;
			ways[r][y].head = NULL;
			y++;
		}
		r++;
	}
	return (ways);
}

void		ft_locked_room(t_ways *ways)
{
	int			i;
	list_link	*tmp;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		while (tmp)
		{
			tmp->data->link_arr[0]->locked = 0;
			tmp = tmp->next;
		}
		i++;
	}
}


int		main()
{
	avl_node	*tree;
	avl_tree	*root;
	t_link		*link;
	int			i;
	int			l;
	int			s;
	t_ways		**ways;
	t_ant		*ant;
	list_link	*tmpw;

	i = 0;
	l = 0;
	s = 0;
	ft_init_structure(&root,&tree,&link);
	read_map(tree, root, link);
	ways = ft_find_ways(root);
//	while (bfs(root))
//	{
//		ways[s][l].head = pave_the_way(root);
//		tmpw = ways[s][l].head;
//		while (tmpw)
//		{
//			if (tmpw->data->incld_in_way != -1)
//				tmpw->data->incld_in_way = 1;
//			else
//			{
//				ft_delete_incld_way(ways[s]);
//				l = 0;
//				while (bfs(root))
//				{
//					ways[s][l].head = pave_the_way_finish(root);
//					tmpw = ways[s][l].head;
//					while (tmpw)
//					{
//						tmpw->data->incld_in_way = 1;
//						tmpw = tmpw->next;
//					}
//					l++;
//				}
////				printf("%d - l\n", l);
//				ft_locked_room(ways[s]);
//				ft_delete_incld_way(ways[s]);
//				s++;
//				l = -1;
//				break;
//			}
//			tmpw = tmpw->next;
//		}
//		l++;
//	}

//	l = 0;
//	while (ways[l].head)
//	{
//		tmpw = ways[l].head;
////		printf("     begin ----  %d\n", l);
//		i = 0;
//		while (tmpw)
//		{
////			printf("%s {ways[%d]}\n", tmpw->data->str, s);
//			tmpw = tmpw->next;
//			i++;
//		}
//		ways[l].steps = i;
//		printf(" ---- steps %d   ---\n\n", ways[l].steps);
//		l++;
//	}
//	printf("do\n");
//	ft_delete_incld_way(ways[s]);


	l = 0;
	s = 0;
	int	q;

	q = 0;
//	printf("%d - s\n", s);
//	while (q <= s)
//	{
//		l = 0;
////		printf("tut\n");
//		while (ways[q][l].head)
//		{
//			tmpw = ways[q][l].head;
////		printf("     begin ----  %d\n", l);
//			i = 0;
//			while (tmpw)
//			{
////			printf("%s {ways[%d]}\n", tmpw->data->str, s);
//				tmpw = tmpw->next;
//				i++;
//			}
//			ways[q][l].steps = i;
////		printf(" ---- steps %d   ---\n\n", ways[q][l].steps);
//			l++;
//		}
//		q++;
//	}
//	int a,d = 0;
//
//
//	while(ways[a])
//	{
//		d = 0;
//		printf("%d  --- group\n", a);
//		while (ways[a][d].head)
//		{
//			printf("%d - steps  %d - satatus  %p  -- head %d - way\n", ways[a][d].steps, ways[a][d].status,ways[a][d].head, d);
//			d++;
//		}
//		a++;
//	}


//	list_link *tmpe;
//
//	tmpe = ways[0][0].head;
//	printf("ways\n");
//	while (tmpe)
//	{
//		printf("%s  - \n", tmpe->data->link_arr[0]->name_room[0]);
//		tmpe = tmpe->next;
//	}
//	printf("end\n");


	int		kol;
	int		ind;

	s = 0;
	while (ways[s])
	{
		kol = 0;
		l = 0;
		ways[s][0].status = 1;
		ind = 0;
		while (ways[s][ind].head && kol < root->ant)
		{
			kol = 0;
			l = 0;
			while (ways[s][l].head && ways[s][l].status == 1)
				kol += ways[s][ind].steps - ways[s][l++].steps + 1;
			if (kol == root->ant || !ways[s][ind + 1].head)
				break;
			if (ways[s][ind].head && kol < root->ant)
				ways[s][++ind].status = 1;
			else
				ways[s][--ind].status = 0;
		}
		ways[s][ind + 1].status = 0;
		i = 0;
		kol = 0;
		while (i <= ind) {
			ways[s][i].status = ways[s][ind].steps - ways[s][i].steps + 1;
			kol += ways[s][i].status;
			i++;
		}
		while (kol < root->ant)
		{
			if (i > ind)
				i = 0;
			ways[s][i].status++;
			i++;
			kol++;
		}
		root->day[s] = ways[s][0].status + ways[s][0].steps - 1;
		printf("%d \n", root->day[s]);
		s++;
	}

//	kol = 1;
//	i = 0;
//	int	d;
//	d = 1;
//	ant = ft_init_ant(&root);
//	while (kol <= root.ant)
//	{
//		if (ways[s][i].status == 0)
//		{
//			i = 0;
//			d++;
//		}
//		ant[kol].head = ways[s][i].head;
//		ways[s][i].status--;
//		ant[kol].day = d;
//		kol++;
//		i++;
//	}
//	printf("%d-day   %d-status %d-steps \n",root.day , ways[0].status, ways[0].steps);
//		i = 0;
//		while (tree[i].str)
//			ft_putendl(tree[i++].str);
//		i = 0;
//		while (link[i].str)
//			ft_putendl(link[i++].str);
//		write(1, "\n", 1);
//		ft_print_res(ant, &root);


//	printf("%d  %d\n", ant[1].day,ant[427].day);




//		printf("%d locked\n", ways[1].head->data->link_arr[0]->locked);

//		printf("%s -tree", (*tree).str);


/*      фришим всю память */
	i = 0;
	while(tree[i].str)
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
