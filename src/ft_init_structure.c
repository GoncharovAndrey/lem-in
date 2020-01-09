#include "../includes/lem_in.h"

t_ways		*ft_init_one_way(avl_tree *root)
{
	t_ways	*ways;
	int		i;

	i = 0;
	if (!(ways = (t_ways*)malloc(sizeof(t_ways) * root->out)))
		return (NULL);
	while (i < root->out)
	{
		ways->head = NULL;
		ways->status = 0;
		ways->steps = 0;
		i++;
	}
	return (ways);
}

int			ft_init_structure(avl_tree **root, avl_node **tree, t_link **link)
{
	if (!(*tree = (avl_node*)malloc(sizeof(avl_node) * MAX_ROOM)))
		return (0);
	if (!(*link = (t_link*)malloc(sizeof(t_link) * MAX_LINK)))
		return (0);
	if (!(*root = (avl_tree*)malloc(sizeof(avl_tree) * 1)))
		return (0);
	(*root)->short_way = NULL;
	(*root)->root = NULL;
	(*root)->count = 0;
	(*root)->st = 0;
	return (1);
}

t_ant			*ft_init_ant(avl_tree *root)
{
	t_ant		*ant;
	int			i;

	i = 0;
	if (!(ant = (t_ant*)malloc(sizeof(t_ant) * (root->ant + 2))))
		return (NULL);
	while (i <= root->ant)
	{
		ant[i].day = 0;
		ant[i].head = NULL;
		ant[i].ant_name = i;
		i++;
	}
	return (ant);
}