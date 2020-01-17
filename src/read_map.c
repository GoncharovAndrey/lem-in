/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 13:27:06 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/25 13:27:08 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int			ft_for_read_ant(char *str)
{
	int			res;

	if (!str)
		ft_close_error();
	res = ft_atoi_max(str);
	if (res < 0)
		ft_close_error();
	return (res);
}

static void			ft_read_ant(t_avl_tree *root, t_lstr **prev)
{
	while (get_next_line(STDIN_FILENO, &(*prev)->str) > 0)
	{
		if (ft_check_sharp_str((*prev)->str) != 1)
		{
			root->ant = ft_for_read_ant((*prev)->str);
			(*prev) = ft_create_add_lstr(*prev);
			break ;
		}
		(*prev) = ft_create_add_lstr((*prev));
	}
	(*prev)->tree = ft_malloc_avl_node();
}

static void			ft_read_room(t_avl_tree *root, t_lstr **prev)
{
	int				opr;

	while (get_next_line(STDIN_FILENO, &(*prev)->str) > 0)
	{
		opr = ft_check_room(prev, root);
		if (opr == 1)
		{
			(*prev) = ft_create_add_lstr((*prev));
			(*prev)->tree = ft_malloc_avl_node();
			continue ;
		}
		else if (opr == 2)
			break ;
		if (avl_insert(root, (*prev)->tree) == 0)
			ft_close_error();
		(*prev) = ft_create_add_lstr((*prev));
		(*prev)->tree = ft_malloc_avl_node();
	}
}

static void			ft_read_link(t_avl_tree *root, t_lstr **prev)
{
	(*prev)->link = ft_malloc_t_link();
	ft_check_link(*prev, root);
	(*prev) = ft_create_add_lstr((*prev));
	(*prev)->link = ft_malloc_t_link();
	while (get_next_line(STDIN_FILENO, &(*prev)->str))
	{
		ft_check_link((*prev), root);
		(*prev) = ft_create_add_lstr((*prev));
		(*prev)->link = ft_malloc_t_link();
	}
}

int					read_map(t_avl_tree *root)
{
	t_lstr			*prev;

	prev = root->line;
	ft_read_ant(root, &prev);
	ft_read_room(root, &prev);
	if (!root->start || !root->end || root->end == prev->tree || root->start == prev->tree)
		ft_close_error();
	ft_read_link(root, &prev);
	return (1);
}
