/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:30:31 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 18:30:33 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				ft_init_queue(t_avl_tree *root)
{
	t_turn		*tmp;

	if (!(tmp = (t_turn*)malloc(sizeof(t_turn) * 1)))
		return (0);
	ft_memset(tmp, 0, sizeof(t_turn));
	if (!(tmp->turn = (t_avl_node**)malloc(sizeof(t_avl_node*) *
			(root->count + 1))))
	{
		free(tmp);
		return (0);
	}
	root->queue = tmp;
	root->queue->start = root->start;
	root->queue->end = root->end;
	return (1);
}

void			ft_init_structure(t_avl_tree **root)
{
	if (!(*root = (t_avl_tree*)malloc(sizeof(t_avl_tree) * 1)))
		ft_close_error();
	ft_memset((*root), 0, sizeof(t_avl_tree));
	if (!((*root)->line = ft_create_add_lstr(NULL)))
		ft_close_error();
}

t_ant			*ft_init_ant(t_avl_tree *root)
{
	t_ant		*ant;
	int			i;

	i = 0;
	if (!(ant = (t_ant*)malloc(sizeof(t_ant) * (root->ant + 2))))
		return (NULL);
	ft_memset(ant, 0, sizeof(t_ant) * (root->ant + 2));
	while (i <= root->ant)
	{
		ant[i].ant_name = i;
		i++;
	}
	return (ant);
}
