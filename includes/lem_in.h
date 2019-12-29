/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:03:22 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/24 17:03:24 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

# include "../lib/includes/ft_printf.h"
#include <stdio.h>

typedef struct			s_avl_node
{
	/*  если что проверить вынести дерево отдельно , и хранить в дата указатель на комнату*/
	struct s_avl_node	*link[2];
	short int			bal;
	/*        еще проверить сначало все считать потом формитровать дерево                 */
	char				*str;
	char				**name_room;
	struct s_list_link	*link_room;
	int					level;
	int					locked;
}						avl_node;

typedef struct			s_avl_tree
{
	avl_node			*root;
	int					count;
	int					ant;
	avl_node			*start;
	avl_node			*end;
}						avl_tree;

typedef struct			s_link
{
	char				*str;
	avl_node			*link_arr[2];
	int					incld_in_way;
	int					status;
}						t_link;

typedef struct			s_list_link
{
	struct s_link		*data;
//	int					side;
	struct s_list_link	*next;
}						list_link;

int				read_map(avl_node *tree, avl_tree *root, t_link *link);
int				avl_insert(avl_tree *tree, avl_node *new_node);
int				ft_add_list(avl_node *room, t_link *data);
void			ft_delete_list(list_link *head);
void			bfs(avl_tree *root);
//avl_node		***pave_the_way(avl_tree *root);

#endif
