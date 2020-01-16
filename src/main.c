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

int				main(void)
{
	t_avl_tree	*root;
	t_ways		**ways;
	t_ant		*ant;

	ft_init_structure(&root);
	read_map(root);
	ft_init_queue(root);
	ways = ft_find_ways(root);
	ft_choose_way(root, ways);
	ant = ft_ants_on_the_way(root);
	ft_print_all(root, ant);
	ft_free_all(&root, &ways, &ant);
	return (0);
}
