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

void		ft_for_print_res(t_ant *tmp, int *y)
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

void		ft_print_res(t_ant *ant, avl_tree *root)
{
	int		i;
	int		y;
	t_ant	*tmp;

	i = 1;
	while(i <= root->day)
	{
		y = 0;
		tmp = ant + 1;
		printf("\n%d - day\n", i);
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

void	ft_print_all(avl_tree *root, avl_node *tree, t_link *link, t_ant *ant)
{
//	ft_putnbr(root->ant);
//	write(1, "\n", 1);

	while (tree->str)
	{
		ft_putendl(tree->str);
		tree++;
	}
	while (link->str)
	{
		ft_putendl(link->str);
		link++;
	}
	write(1, "\n", 1);
	ft_print_res(ant, root);
}