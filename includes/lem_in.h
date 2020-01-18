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
# define LEM_IN_H
# include "../lib/includes/ft_printf.h"
# include "./flag_msg.h"
# include <limits.h>

typedef struct			s_avl_node
{
	struct s_avl_node	*link[2];
	short int			bal;
	char				**name_room;
	struct s_list_link	*link_room;
	size_t				level;
	int					locked;
	int					x_y[3];
}						t_avl_node;

typedef struct			s_avl_tree
{
	t_avl_node			*root;
	int					count;
	int					ant;
	t_avl_node			*start;
	t_avl_node			*end;
	int					out;
	struct s_ways		*short_way;
	int					day;
	struct s_turn		*queue;
	struct s_lstr		*line;
	int					flag[3];
}						t_avl_tree;

typedef struct			s_link
{
	t_avl_node			*link_arr[2];
	int					incld_in_way;
	size_t				status;
}						t_link;

typedef struct			s_list_link
{
	struct s_link		*data;
	struct s_list_link	*next;
}						t_list_link;

typedef struct			s_ways
{
	t_list_link			*head;
	int					steps;
	int					status;
}						t_ways;

typedef struct			s_ant
{
	t_list_link			*head;
	int					ant_name;
	int					day;
}						t_ant;

typedef struct			s_turn
{
	t_avl_node			**turn;
	t_avl_node			*start;
	t_avl_node			*end;
	size_t				next;
	size_t				last;
	size_t				lvl_rm;
	size_t				lvl_lnk;
}						t_turn;

typedef struct			s_lstr
{
	char				*str;
	t_avl_node			*tree;
	t_link				*link;
	struct s_lstr		*next;
}						t_lstr;

int						read_map(t_avl_tree *root);
int						ft_check_room(t_lstr **prev, t_avl_tree *root);
int						ft_check_link(t_lstr *prev, t_avl_tree *root);
int						ft_check_sharp_str(char *str);
int						ft_add_list(t_avl_node *room, t_link *data);
t_avl_node				*ft_find_room(char *str, t_avl_node *root);
int						avl_insert(t_avl_tree *tree, t_avl_node *new_node);
void					ft_left_rotation(t_avl_node ***tmp);
void					ft_right_rotation(t_avl_node ***tmp);
void					ft_delete_list(t_list_link *head);
t_list_link				*ft_create_list(t_link *data);
int						bfs(t_turn *queue);
t_list_link				*pave_the_way(t_turn *queue);
t_list_link				*pave_the_way_finish(t_turn *queue);
t_ways					**ft_find_ways(t_avl_tree *root);
int						ft_init_queue(t_avl_tree *root);
void					ft_off_include_way(t_ways *ways);
void					ft_delete_incld_way(t_ways *ways);
void					ft_init_structure(t_avl_tree **root);
t_ant					*ft_init_ant(t_avl_tree *root);
t_ways					**ft_malloc_ways(size_t out, t_ways **ways, size_t s);
t_avl_node				*ft_malloc_avl_node(void);
t_link					*ft_malloc_t_link(void);
int						ft_choose_way(t_avl_tree *root, t_ways **ways);
t_ant					*ft_ants_on_the_way(t_avl_tree *root);
void					ft_print_all(t_avl_tree *root, t_ant *ant);
void					ft_free_all(t_avl_tree **root, t_ways ***ways,
							t_ant **ant);
void					ft_free_arr_str(char ***str);
int						ft_atoi_max(const char *nptr);
int						ft_is_number(char *num);
void					ft_find_out(t_avl_tree *root);
void					ft_close_error(void);
t_lstr					*ft_create_add_lstr(t_lstr *prev);
void					ft_parse_flag(char **av, t_avl_tree *root);

#endif
