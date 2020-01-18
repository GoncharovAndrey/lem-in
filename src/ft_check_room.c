/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:22:12 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/18 18:22:14 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			ft_for_start_end(t_lstr **prev)
{
	(*prev) = ft_create_add_lstr((*prev));
	(*prev)->tree = ft_malloc_avl_node();
	while (get_next_line(STDIN_FILENO, &(*prev)->str) > 0)
	{
		if (ft_check_sharp_str((*prev)->str) == 1)
		{
			(*prev) = ft_create_add_lstr((*prev));
			(*prev)->tree = ft_malloc_avl_node();
			continue ;
		}
		break ;
	}
}

static int			ft_check_start_end(t_lstr **prev, t_avl_tree *root)
{
	if (ft_strncmp("##", (*prev)->str, 2) == 0)
	{
		if (ft_strcmp("##start", (*prev)->str) == 0)
		{
			if (root->start)
				ft_close_error();
			ft_for_start_end(prev);
			root->start = (*prev)->tree;
			return (1);
		}
		else if (ft_strcmp("##end", (*prev)->str) == 0)
		{
			if (root->end)
				ft_close_error();
			ft_for_start_end(prev);
			root->end = (*prev)->tree;
			return (1);
		}
		else
			ft_close_error();
	}
	return (0);
}

static void			ft_for_check_room(char **tmp, t_lstr *head, t_avl_node *tr)
{
	int				x;
	int				y;

	x = ft_atoi_max(tmp[1]);
	y = ft_atoi_max(tmp[2]);
	while (head)
	{
		if (head->tree)
			if (head->tree->x_y[0])
				if (head->tree->x_y[1] == x)
					if (head->tree->x_y[2] == y)
						ft_close_error();
		head = head->next;
	}
	tr->x_y[0] = 1;
	tr->x_y[1] = x;
	tr->x_y[2] = y;
}

int					ft_check_room(t_lstr **prev, t_avl_tree *root)
{
	char			**tmp;

	if (!(*prev)->str || !*((*prev)->str))
		ft_close_error();
	if (ft_strncmp("L", (*prev)->str, 1) == 0)
		ft_close_error();
	if (ft_strncmp("#", (*prev)->str, 1) == 0)
		if (ft_check_start_end(prev, root) == 0)
			return (1);
	if (!(tmp = ft_strsplit((*prev)->str, 32)))
		ft_close_error();
	if (!tmp[1])
	{
		ft_free_arr_str(&tmp);
		return (2);
	}
	if (tmp[3])
		ft_close_error();
	ft_for_check_room(tmp, root->line, (*prev)->tree);
	(*prev)->tree->name_room = tmp;
	return (0);
}
