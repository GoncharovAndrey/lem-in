/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:31:26 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 17:31:29 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant			*ft_ants_on_the_way(t_avl_tree *root)
{
	t_ant		*ant;
	int			i;
	int			sum;
	int			d;

	sum = 1;
	i = 0;
	d = 1;
	if (!(ant = ft_init_ant(root)))
		ft_close_error();
	if (root->day == 1)
		return (ant);
	while (sum <= root->ant)
	{
		if (root->short_way[i].status == 0)
		{
			i = 0;
			d++;
		}
		ant[sum].head = root->short_way[i].head;
		root->short_way[i].status--;
		ant[sum++].day = d;
		i++;
	}
	return (ant);
}

static int		ft_enable_activ(t_avl_tree *root, t_ways *ways)
{
	int			sum;
	int			l;
	int			ind;

	sum = 0;
	l = 0;
	ind = 0;
	ways[0].status = 1;
	while (ways[ind].head && sum < root->ant)
	{
		sum = 0;
		l = 0;
		while (ways[l].head && ways[l].status == 1)
			sum += ways[ind].steps - ways[l++].steps + 1;
		if (sum == root->ant || !ways[ind + 1].head)
			break ;
		if (ways[ind].head && sum < root->ant)
			ways[++ind].status = 1;
		else
			ways[--ind].status = 0;
	}
	ways[ind + 1].status = 0;
	return (ind);
}

static void		ft_distribution_of_ants(t_avl_tree *root, t_ways *ways, int ind)
{
	int			i;
	int			kol;

	i = 0;
	kol = 0;
	while (i <= ind)
	{
		ways[i].status = ways[ind].steps - ways[i].steps + 1;
		kol += ways[i].status;
		i++;
	}
	while (kol < root->ant)
	{
		if (i > ind)
			i = 0;
		ways[i].status++;
		i++;
		kol++;
	}
	kol = ways[0].status + ways[0].steps - 1;
	if (root->day == 0 || root->day > kol)
	{
		root->day = kol;
		root->short_way = ways;
	}
}

int				ft_choose_way(t_avl_tree *root, t_ways **ways)
{
	int			i;
	int			ind;

	i = 0;
	ind = 0;
	if (!(**ways).head)
		ft_close_error();
	if (ways[0][0].steps == 1)
	{
		root->short_way = ways[0];
		root->day = 1;
		return (1);
	}
	while (ways[i])
	{
		ind = ft_enable_activ(root, ways[i]);
		ft_distribution_of_ants(root, ways[i], ind);
		i++;
	}
	return (1);
}
