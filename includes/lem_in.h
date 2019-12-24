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
	char				*name_room;
//	str					*x;
//	str					*y;
}						avl_node;

typedef struct			s_avl_tree
{
	avl_node			*root;
	int					count;
}						avl_tree;


int				avl_insert(avl_tree *tree, avl_node *new_node);

#endif
