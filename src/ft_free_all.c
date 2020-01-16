#include "../includes/lem_in.h"

void		ft_free_arr_str(char ***str)
{
	char **tmp;

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

void			ft_free_tree(avl_node **tree)
{
//	avl_node	*tmp;
//
//	if (!tree || !*tree)
//		return ;
//	tmp = *tree;
//	while (tmp && tmp->str)
//	{
//		ft_delete_list(tmp->link_room);
//		ft_free_arr_str(&(tmp->name_room));
//		free(tmp->str);
//		tmp++;
//	}
	free(*tree);
}

void			ft_free_link(t_link **link)
{
//	t_link		*tmp;
//
//	if (!link || !*link)
//		return ;
//	tmp = *link;
//	while (tmp && tmp->str)
//	{
//		free(tmp->str);
//		tmp++;
//	}
	free(*link);
}

	void		ft_free_all(avl_tree **root, avl_node **tree, t_link **link, t_ways ***ways, t_ant **ant)
	{
		ft_free_ways(ways);
		ft_free_tree(tree);
		ft_free_link(link);
		/* проверить на существованеи */
		free((*root)->queue->turn);
		free((*root)->queue);
		free(root[0]);
		/* !!!!!! */
		if(ant && *ant)
			free(*ant);
	}
