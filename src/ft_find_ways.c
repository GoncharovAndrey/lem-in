/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:27:04 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 18:27:09 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ways		*ft_quike_search(t_avl_tree *root, t_ways *ways)
{
	t_list_link		*tmp;
	int				i;
	int				s;

	i = 0;
	while (bfs(root->queue))
	{
		s = 0;
		ways[i].head = pave_the_way_finish(root->queue);
		tmp = ways[i].head;
		while (tmp)
		{
			tmp->data->incld_in_way = 1;
			tmp = tmp->next;
			s++;
		}
		ways[i].steps = s;
		i++;
	}
	ways[i].head = NULL;
	return (NULL);
}

static int			ft_for_suurballe(t_ways *ways)
{
	t_list_link		*tmp;

	tmp = ways->head;
	while (tmp)
	{
		if (tmp->data->incld_in_way != -1)
			tmp->data->incld_in_way = 1;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_ways		**ft_suurballe(t_avl_tree *root, t_ways **ways)
{
	int				s;
	int				l;

	s = 1;
	l = 0;
	while (bfs(root->queue))
	{
		ways[s][l].head = pave_the_way(root->queue);
		if (!(ft_for_suurballe(&ways[s][l])))
		{
			ft_delete_incld_way(ways[s]);
			ft_quike_search(root, ways[s]);
			ft_off_include_way(ways[s]);
			s++;
			ways = ft_malloc_ways(root->out, ways, s + 2);
			l = -1;
		}
		l++;
	}
	ft_delete_incld_way(ways[s]);
	free(ways[s]);
	ways[s] = NULL;
	return (ways);
}

t_ways				**ft_find_ways(t_avl_tree *root)
{
	t_ways			**ways;

	ft_find_out(root);
	ways = ft_malloc_ways(root->out, NULL, 2);
	ft_quike_search(root, ways[0]);
	if (root->flag[0] == 0)
	{
		ft_off_include_way(ways[0]);
		ways = ft_suurballe(root, ways);
	}
	else
	{
		free(ways[1]);
		ways[1] = NULL;
	}
	return (ways);
}
