/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:05:14 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/06 18:05:16 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "stdio.h"

static	void		ft_for_print_res(t_ant *tmp, int *y)
{
	if (*y != 0)
		write(1, " ", 1);
	write(1, "L", 1);
	ft_putnbr(tmp->ant_name);
	write(1, "-", 1);
	ft_putstr(tmp->head->data->link_arr[0]->name_room[0]);
	tmp->day++;
	tmp->head = (*tmp).head->next;
	if (tmp->head == NULL)
		tmp->day = 0;
	(*y)++;
}

static void			ft_swap_ways(t_avl_tree *root)
{
	t_avl_node		*tmp_room;
	t_list_link		*tmp_link;
	t_ways			*tmp_ways;

	tmp_ways = root->short_way;
	while (tmp_ways->head)
	{
		tmp_room = root->start;
		tmp_link = tmp_ways->head;
		while (tmp_link)
		{
			if (tmp_link->data->link_arr[0] == tmp_room)
			{
				tmp_link->data->link_arr[0] = tmp_link->data->link_arr[1];
				tmp_link->data->link_arr[1] = tmp_room;
			}
			tmp_room = tmp_link->data->link_arr[0];
			tmp_link = tmp_link->next;
		}
		tmp_ways++;
	}
}

static void			ft_print_res(t_ant *ant, t_avl_tree *root)
{
	int				i;
	int				y;
	t_ant			*tmp;

	i = 1;
	while (i <= root->day)
	{
		y = 0;
		tmp = ant + 1;
		if (root->flag[1] == 1)
			ft_printf("Day - %d\n", i);
		while (tmp->ant_name)
		{
			if (tmp->day == i)
				ft_for_print_res(tmp, &y);
			tmp++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void				ft_print_all(t_avl_tree *root, t_ant *ant)
{
	t_lstr			*tmp;

	tmp = root->line;
	while (tmp && tmp->str)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	ft_swap_ways(root);
	ft_print_res(ant, root);
}
