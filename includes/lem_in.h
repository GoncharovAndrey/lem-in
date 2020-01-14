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
# include <limits.h>
#include <stdio.h>

# define MAX_ROOM  10000
# define MAX_LINK  10000
//# define SUPERPOSITION

typedef struct			s_avl_node
{
	struct s_avl_node	*link[2];
	short int			bal;
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
	int					out;
	struct s_ways		*short_way;
	int					day;
	struct s_turn		*queue;
//	int					st;
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
	struct s_list_link	*next;
}						list_link;

typedef struct			s_ways
{
	list_link			*head;
	int					steps;
	int					status;
}						t_ways;

typedef struct			s_ant
{
	list_link			*head;
//	char				*ant_name;
	int					ant_name;
	int					day;
}						t_ant;

typedef struct			s_turn
{
	avl_node			**turn;
	avl_node			*start;
	avl_node			*end;
	size_t				next;
	size_t				last;
	size_t				lvl_rm;
	size_t				lvl_lnk;
}						t_turn;

int				read_map(avl_node *tree, avl_tree *root, t_link *link);
int				avl_insert(avl_tree *tree, avl_node *new_node);
void			ft_left_rotation(avl_node ***tmp);
void			ft_right_rotation(avl_node ***tmp);
int				ft_add_list(avl_node *room, t_link *data);
void			ft_delete_list(list_link *head);
int				bfs(t_turn *queue);
//int				bfs(avl_tree *root);
list_link		*ft_create_list(t_link *data);
list_link		*pave_the_way(t_turn *queue);
list_link		*pave_the_way_finish(t_turn *queue);
void			ft_print_res(t_ant *ant, avl_tree *root);
int				ft_init_structure(avl_tree **root, avl_node **tree, t_link **link);
t_ant			*ft_init_ant(avl_tree *root);
t_ways			*ft_init_one_way(avl_tree *root);
void			ft_off_include_way(t_ways *ways);
void			ft_delete_incld_way(t_ways *ways);
void			ft_locked_room(t_ways *ways);
t_ways			**ft_find_ways(avl_tree *root);
int				ft_choose_way(avl_tree *root, t_ways **ways);
t_ant			*ft_ants_on_the_way(avl_tree *root);
void			ft_print_all(avl_tree *root, avl_node *tree, t_link *link, t_ant *ant);
void			ft_free_all(avl_tree **root, avl_node **tree, t_link **link, t_ways ***ways, t_ant **ant);
int				ft_init_queue(avl_tree *root);
int				ft_check_room(avl_node *tree, avl_tree *root);
void			ft_free_arr_str(char ***str);
avl_node		*ft_find_room(char *str, avl_node *root);
int				ft_check_link(t_link *link, avl_tree *root);

#endif
