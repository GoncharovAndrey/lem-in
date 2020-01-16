/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:32:14 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 18:32:17 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_free_arr_str(char ***str)
{
	char	**tmp;

	if (!str || !*str)
		return ;
	tmp = *str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*str);
}

void		ft_free_ways(t_ways ***ways)
{
	t_ways	**tmp_ways;
	t_ways	*tmp_ow;

	if (!ways || !*ways)
		return ;
	tmp_ways = *ways;
	while (tmp_ways && *tmp_ways)
	{
		tmp_ow = *tmp_ways;
		while (tmp_ow && tmp_ow->head)
		{
			ft_delete_list(tmp_ow->head);
			tmp_ow++;
		}
		free(*tmp_ways);
		tmp_ways++;
	}
	free(*ways);
}

void		ft_free_lstr(t_lstr *line)
{
	t_lstr	*del;

	while (line)
	{
		ft_strdel(&line->str);
		if (line->tree)
		{
			ft_free_arr_str(&line->tree->name_room);
			ft_delete_list(line->tree->link_room);
			free(line->tree);
		}
		if (line->link)
			free(line->link);
		del = line;
		line = line->next;
		free(del);
	}
}

void		ft_free_all(t_avl_tree **root, t_ways ***ways, t_ant **ant)
{
	ft_free_lstr((*root)->line);
	free((*root)->queue->turn);
	free((*root)->queue);
	free(root[0]);
	ft_free_ways(ways);
	free(*ant);
}
