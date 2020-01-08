#include "../includes/lem_in.h"

void			ft_find_out(avl_tree *root)
{
	list_link	*tmp;

	tmp = root->end->link_room;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	root->out = i + 2;
}

t_ways			*ft_quike_search(avl_tree *root)
{
	t_ways		*ways;
	list_link	*tmp;
	int			i;
	int			s;

	i = 0;
	if (!(ways = ft_init_one_way(root)))
		return (NULL);
	while (bfs(root))
	{
		s = 0;
		ways[i].head = pave_the_way_finish(root);
		tmp = ways[i].head;
		while(tmp)
		{
			tmp->data->incld_in_way = 1;
			tmp = tmp->next;
			s++;
		}
		ways->steps = s;
		i++;
	}
	return (ways);
}

int			ft_suurballe()

int			ft_find_ways(avl_tree *root, t_ways **ways)
{
	ft_find_out(root);
	if (!(ways[0] = ft_quike_search(root)))
		return (0);
	ft_off_include_way(ways[0]);
	ft_locked_room((ways[0]))
//#ifdef SUPERPOSITION
	while (bfs(root))
	{
		ways[s][l].head = pave_the_way(root);
		tmpw = ways[s][l].head;
		while (tmpw)
		{
			if (tmpw->data->incld_in_way != -1)
				tmpw->data->incld_in_way = 1;
			else
			{
				ft_delete_incld_way(ways[s]);
				l = 0;
				while (bfs(root))
				{
					ways[s][l].head = pave_the_way_finish(root);
					tmpw = ways[s][l].head;
					while (tmpw)
					{
						tmpw->data->incld_in_way = 1;
						tmpw = tmpw->next;
					}
					l++;
				}
				ft_locked_room(ways[s]);
				ft_off_incld_way(ways[s]);
				s++;
				l = -1;
				break;
			}
			tmpw = tmpw->next;
		}
		l++;
	}
//#endif
}