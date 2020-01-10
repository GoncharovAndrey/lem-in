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
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp->data->link_arr[0]->locked = 0;
			tmp = tmp->next;
		}
		i++;
	}
}


//void		ft_locked_room(t_ways *ways)
//{
//	int			i;
//	list_link	*tmp;
//
//	i = 0;
//	while (ways[i].head)
//	{
//		tmp = ways[i].head;
//		while (tmp)
//		{
//			tmp->data->link_arr[0]->locked = 0;
//			tmp = tmp->next;
//		}
//		i++;
//	}
//}


int		main()
{
	avl_node	*tree;
	avl_tree	*root;
	t_link		*link;
	int			i;
	int			q;
//	int			s;
	t_ways		**ways;
	t_ant		*ant;
	list_link	*tmpw;

//	i = 0;
//	l = 0;
//	s = 0;
	ft_init_structure(&root,&tree,&link);
	read_map(tree, root, link);
	ways = ft_find_ways(root);
	ft_choose_way(root, ways);
	ant = ft_ants_on_the_way(root);
	ft_print_all(root, tree, link, ant);
	ft_free_all(&root, &tree, &link, &ways, &ant);


//	ft_choose_way(root, ways);

//	l = 0;
//	s = 0;
//	int	q;
//
//	q = 0;


/*fsfsfsfsfs*/
//	int		kol;
//	int		ind;
//
//	s = 0;
//	while (ways[s])
//	{
//		kol = 0;
//		l = 0;
//		ways[s][0].status = 1;
//		ind = 0;
//		while (ways[s][ind].head && kol < root->ant)
//		{
//			kol = 0;
//			l = 0;
//			while (ways[s][l].head && ways[s][l].status == 1)
//				kol += ways[s][ind].steps - ways[s][l++].steps + 1;
//			if (kol == root->ant || !ways[s][ind + 1].head)
//				break;
//			if (ways[s][ind].head && kol < root->ant)
//				ways[s][++ind].status = 1;
//			else
//				ways[s][--ind].status = 0;
//		}
//		ways[s][ind + 1].status = 0;
//		i = 0;
//		kol = 0;
//		while (i <= ind)
//		{
//			ways[s][i].status = ways[s][ind].steps - ways[s][i].steps + 1;
//			kol += ways[s][i].status;
//			i++;
//		}
//		while (kol < root->ant)
//		{
//			if (i > ind)
//				i = 0;
//			ways[s][i].status++;
//			i++;
//			kol++;
//		}
//		if (root->day == 0 || root->day > (ways[s][0].status + ways[s][0].steps - 1))
//		{
//			root->day = ways[s][0].status + ways[s][0].steps - 1;
//			root->short_way = ways[s];
//		}
//		s++;
//	}
//		printf("%d \n", root->day);

/*cxvxvx*/
//	kol = 1;
//	i = 0;
//	int	d;
//	d = 1;
//	ant = ft_init_ant(root);
//	while (kol <= root->ant)
//	{
//		if (root->short_way[i].status == 0)
//		{
//			i = 0;
//			d++;
//		}
//		ant[kol].head = root->short_way[i].head;
//		root->short_way[i].status--;
//		ant[kol].day = d;//	int		kol;
//
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
//		ft_print_res(ant, root);

//	printf("%d  %d\n", ant[1].day,ant[427].day);




//		printf("%d locked\n", ways[1].head->data->link_arr[0]->locked);

//		printf("%s -tree", (*tree).str);


/*      фришим всю память */
//	i = 0;
//	q = 0;
//	while (ways[i])
//	{
//		q = 0;
//		while (ways[i][q].head)
//			ft_delete_list(ways[i][q++].head);
//		free(ways[i]);
//		i++;
//	}
//	free(ways);
//	i = 0;
//	while(tree[i].str)
//	{
//		free(tree[i].name_room[0]);
//		free(tree[i].name_room[1]);
//		free(tree[i].name_room[2]);
//		free(tree[i].name_room);
//		free(tree[i].str);
//		ft_delete_list(tree[i].link_room);
//		i++;
//	}
//	i = 0;
//	while(link[i].str)
//	{
//		free(link[i].str);
//		i++;
//	}
//	free(tree);
//	free(link);
//	free(root);
//	free(ant);
/*          !!!!!!!!!!!!!             */
	return 0;
}
