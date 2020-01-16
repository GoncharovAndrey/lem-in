/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:33:41 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 18:33:43 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_avl_node		*ft_malloc_avl_node(void)
{
	t_avl_node	*tmp;

	if (!(tmp = (void*)malloc(sizeof(t_avl_node))))
		ft_close_error();
	memset(tmp, 0, sizeof(t_avl_node));
	return (tmp);
}

t_link			*ft_malloc_t_link(void)
{
	t_link		*tmp;

	if (!(tmp = (void*)malloc(sizeof(t_link))))
		ft_close_error();
	memset(tmp, 0, sizeof(t_link));
	return (tmp);
}

static t_ways	*ft_init_one_way(size_t size)
{
	t_ways		*ways;
	int			i;

	i = 0;
	if (!(ways = (t_ways*)malloc(sizeof(t_ways) * size)))
		ft_close_error();
	ft_memset(ways, 0, sizeof(t_ways) * size);
	return (ways);
}

static t_ways	**ft_init_arr_ways(size_t s)
{
	t_ways		**tmp;

	if (!(tmp = (t_ways**)malloc(sizeof(t_ways*) * (s + 1))))
		ft_close_error();
	ft_memset(tmp, 0, sizeof(t_ways*) * (s + 1));
	return (tmp);
}

t_ways			**ft_malloc_ways(size_t out, t_ways **ways, size_t s)
{
	int			i;
	t_ways		**tmp;

	i = -1;
	if (!ways)
	{
		tmp = ft_init_arr_ways(s);
		while (++i < s)
			tmp[i] = ft_init_one_way(out);
	}
	else
	{
		tmp = ft_init_arr_ways(s);
		while (++i < s - 1)
		{
			if (ways[i])
				tmp[i] = ways[i];
			else
				tmp[i] = ft_init_one_way(out);
		}
		tmp[i] = NULL;
		free(ways);
	}
	return (tmp);
}
