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
		ways[i].head = NULL;
		ways[i].status = 0;
		ways[i].steps = 0;
		i++;
	}
	return (ways);
}

int			ft_init_queue(avl_tree *root)
{
	t_turn	*tmp;

	if (!(tmp = (t_turn*)malloc(sizeof(t_turn) * 1)))
		return (0);
	if (!(tmp->turn = (avl_node**)malloc(sizeof(avl_node*) * (root->count + 1))))
	{
		free(tmp);
		return (0);
	}
	root->queue = tmp;
	root->queue->next = 0;
	root->queue->last = 0;
	root->queue->lvl_rm = 0;
	root->queue->lvl_lnk = 0;
	root->queue->start = root->start;
	root->queue->end = root->end;
//	printf ("%s   %s\n", tmp->start->name_room[0], tmp->end->name_room[0]);
	return (1);
}

int			ft_init_structure(avl_tree **root, avl_node **tree, t_link **link)
{
	if (!(*tree = (avl_node*)malloc(sizeof(avl_node) * MAX_ROOM)))
		return (0);
	ft_memset(*tree, 0, sizeof(avl_node) * MAX_ROOM);
	if (!(*link = (t_link*)malloc(sizeof(t_link) * MAX_LINK)))
		return (0);
	ft_memset(*link, 0, sizeof(t_link) * MAX_LINK);
	if (!(*root = (avl_tree*)malloc(sizeof(avl_tree) * 1)))
		return (0);
	(*root)->short_way = NULL;
	(*root)->root = NULL;
	(*root)->queue = NULL;
	(*root)->day = 0;
	(*root)->count = 0;
	(*root)->start = NULL;
	(*root)->end = NULL;
//	(*root)->st = 0;
	return (1);
}

t_ant			*ft_init_ant(avl_tree *root)
{
	t_ant		*ant;
	int			i;

	i = 0;
	if (!(ant = (t_ant*)malloc(sizeof(t_ant) * (root->ant + 2))))
		return (NULL);
	ft_memset(ant, 0, sizeof(t_ant) * (root->ant + 2));
	while (i <= root->ant)
	{
		ant[i].ant_name = i;
		i++;
	}
	return (ant);
}