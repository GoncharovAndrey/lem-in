#include "../includes/lem_in.h"

void		ft_free_all(avl_tree **root, avl_node **tree, t_link **link, t_ways ***ways, t_ant **ant)
{
	int		i;
	int		q;

	i = 0;
	q = 0;
	while ((*ways)[i])
	{
		q = 0;
		while ((*ways)[i][q].head)
			ft_delete_list((*ways)[i][q++].head);
		free((*ways)[i]);
		i++;
	}
	free(*ways);
	i = 0;
	while((*tree)[i].str)
	{
		free((*tree)[i].name_room[0]);
		free((*tree)[i].name_room[1]);
		free((*tree)[i].name_room[2]);
		free((*tree)[i].name_room);
		free((*tree)[i].str);
		ft_delete_list((*tree)[i].link_room);
		i++;
	}
	i = 0;
	while((*link)[i].str)
	{
		free((*link)[i].str);
		i++;
	}
	free(*tree);
	free(*link);
	free(*root);
	free(*ant);
}