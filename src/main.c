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
#include <stdio.h>

void			ft_delete_incld_way(t_ways *ways)
{
	int			i;
	list_link	*tmp;
	list_link	*del;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		ways[i].head = NULL;
		while (tmp)
		{
			del = tmp;
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp = tmp->next;
			if (del)
				free(del);
		}
		i++;
	}
}

void			ft_off_include_way(t_ways *ways)
{
	int			i;
	list_link	*tmp;

	i = 0;
	while (ways[i].head)
	{
		tmp = ways[i].head;
		while (tmp)
		{
			if (tmp->data->incld_in_way != -1)
				tmp->data->incld_in_way = 0;
			tmp->data->link_arr[0]->locked = 0;
			tmp = tmp->next;
		}
		i++;
	}
}


//void		ft_locked_room(t_ways *ways)
//{
//	int			i;
//	list_link	*tmp;
//
//	i = 0;
//	while (ways[i].head)
//	{
//		tmp = ways[i].head;
//		while (tmp)
//		{
//			tmp->data->link_arr[0]->locked = 0;
//			tmp = tmp->next;
//		}
//		i++;
//	}
//}

void	ft_close_error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

int		main()
{
	avl_node	*tree;
	avl_tree	*root;
	t_link		*link;
	t_ways		**ways;
	t_ant		*ant;

	ft_init_structure(&root,&tree,&link);
	if (!(read_map(tree, root, link)))
	{
		ft_close_error();
//		ft_putendl("ERROR");
//		ft_free_all(&root, &tree, &link, &ways, &ant);
//		return 0;
	}
	//		ft_close_error();
	ft_init_queue(root);
	ways = ft_find_ways(root);
	ft_choose_way(root, ways);
	ant = ft_ants_on_the_way(root);
	ft_print_all(root, tree, link, ant);
	ft_free_all(&root, &tree, &link, &ways, &ant);
	return 0;
}
