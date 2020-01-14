#include "../includes/lem_in.h"

void			ft_find_out(avl_tree *root)
{
	list_link	*tmp;
	int			i;

	i = 0;
	tmp = root->end->link_room;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	root->out = i + 2;
}

t_ways			*ft_quike_search(avl_tree *root, t_ways *ways)
{
//	t_ways		*ways;
	list_link	*tmp;
	int			i;
	int			s;

	i = 0;
//	if (!(ways = ft_init_one_way(root)))
//		return (NULL);
	while (bfs(root->queue))
	{
		s = 0;
		ways[i].head = pave_the_way_finish(root->queue);
		tmp = ways[i].head;
		while(tmp)
		{
			tmp->data->incld_in_way = 1;
			tmp = tmp->next;
			s++;
		}
		ways[i].steps = s;
		i++;
	}
	ways[i].head = NULL;
	return (NULL);
}

int				ft_for_suurballe(t_ways *ways)
{
	list_link	*tmp;

	tmp = ways->head;
	while (tmp)
	{
		if (tmp->data->incld_in_way != -1)
			tmp->data->incld_in_way = 1;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_ways			**ft_delete_ways(t_ways ***ways)
{
	list_link	*tmp;
	list_link	*del;
	t_ways		*tmpw;
	t_ways		**tmpww;

	tmpww = *ways;
	while (tmpww)
	{
		tmpw = **ways;
		while (tmpw)
		{
			tmp = tmpw->head;
			while (tmp)
			{
				tmp = tmp->next;
				free(del);
			}
			tmpw++;
		}
		free(**ways);
		tmpww++;
	}
	free(*ways);
	return (NULL);
}

t_ways			**ft_malloc_ways(avl_tree *root, t_ways **ways, size_t s)
{
	int			i;
	t_ways		**tmp;

	i = -1;
	if (!ways)
	{
		if (!(tmp = (t_ways**)malloc(sizeof(t_ways*) * (s + 1))))
			return (NULL);
		while (++i < s)
			tmp[i] = ft_init_one_way(root);
		tmp[i] = NULL;
	}
	else
	{
		if (!(tmp = (t_ways**)malloc(sizeof(t_ways*) * (s + 1))))
			return (ft_delete_ways(&ways));
		while (++i < s - 1)
		{
			if (ways[i])
				tmp[i] = ways[i];
			else
				tmp[i] = ft_init_one_way(root);
		}
		tmp[i] = NULL;
		free(ways);
	}
	return (tmp);
}

t_ways			**ft_suurballe(avl_tree *root, t_ways **ways)
{
	int			s;
	int			l;

	s = 1;
	l = 0;
	while (bfs(root->queue))
	{
		ways[s][l].head = pave_the_way(root->queue);
		if (!(ft_for_suurballe(&ways[s][l])))
		{
			ft_delete_incld_way(ways[s]);
			ft_quike_search(root, ways[s]);
//			ft_locked_room(ways[s]);
			ft_off_include_way(ways[s]);
			s++;
			ways = ft_malloc_ways(root, ways, s + 2);
			l = -1;
		}
		l++;
	}
	ft_delete_incld_way(ways[s]);
	free(ways[s]);
	ways[s] = NULL;
	return (ways);
}

t_ways			**ft_find_ways(avl_tree *root)
{
	t_ways	**ways;

	ft_find_out(root);
	if (!(ways = ft_malloc_ways(root, NULL, 2)))
		return (NULL);
	ft_quike_search(root, ways[0]);
//#ifdef SUPERPOSITION
	ft_off_include_way(ways[0]);
//	ft_locked_room(ways[0]);
	ways = ft_suurballe(root, ways);
//#else
//	free(ways[1]);
//	ways[1] = NULL;
//#endif
	return (ways);
}
