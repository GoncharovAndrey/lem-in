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


typedef struct			s_avl_node
{
	struct s_avl_node	*link[2];
	short int			bal;
	char				*str;
	char				**name_room;
	struct s_list_link	*link_room;
//	str					*x;
//	str					*y;
}						avl_node;

typedef struct			s_avl_tree
{
	avl_node			*root;
	int					count;
	int					ant;
	avl_node			*start;
	avl_node			*end;
}						avl_tree;

typedef struct			s_list_link
{
	avl_node			*data;
	struct s_list_link	*next;
}						list_link;

int				read_map(avl_node *tree, avl_tree *root, char **link);
int				avl_insert(avl_tree *tree, avl_node *new_node);
int				ft_add_list(avl_node *data, avl_node *room);
void			ft_delete_list(list_link *head);

#endif
