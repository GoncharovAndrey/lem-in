/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:12:14 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/14 10:12:16 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				ft_is_number(char *num)
{
	int			i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int				ft_atoi_max(const char *nptr)
{
	size_t		i;
	long int	res;
	int			z;

	res = 0;
	i = 0;
	z = 1;
	if (!nptr)
		ft_close_error();
	if (!ft_is_number((char *)nptr))
		ft_close_error();
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	z = nptr[i] == '-' ? -1 : 1;
	i = nptr[i] == '-' || nptr[i] == '+' ? i + 1 : i + 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((z * res) > INT_MAX || (z * res) < INT_MIN)
			ft_close_error();
		i++;
	}
	return (res * z);
}


int			ft_check_start_end(t_lstr **prev, avl_tree *root)
{
	if (ft_strncmp("##", (*prev)->str, 2) == 0)
	{
		if (ft_strcmp("##start", (*prev)->str) == 0)
		{
			if (root->start)
				ft_close_error();
			(*prev) = ft_create_add_lstr((*prev));
			(*prev)->tree = ft_malloc_avl_node();
			while (get_next_line(STDIN_FILENO, &(*prev)->str) > 0)
			{
//				printf("%s  - str  %d fun \n", (*prev)->str, ft_check_sharp_str((*prev)->str));
				if (ft_check_sharp_str((*prev)->str) == 1)
				{
					(*prev) = ft_create_add_lstr((*prev));
					(*prev)->tree = ft_malloc_avl_node();
					continue;
//					get_next_line(STDIN_FILENO, &(*prev)->str);
//					printf("%s\n", (*prev)->str);
				}
				break;
			}
			root->start = (*prev)->tree;
			return (1);
		}
		else if (ft_strcmp("##end", (*prev)->str) == 0)
		{
			if (root->end)
				ft_close_error();
			(*prev) = ft_create_add_lstr((*prev));
			(*prev)->tree = ft_malloc_avl_node();
			while (get_next_line(STDIN_FILENO, &(*prev)->str) > 0)
			{
//				printf("%s  - str  %d fun \n", (*prev)->str, ft_check_sharp_str((*prev)->str));
				if (ft_check_sharp_str((*prev)->str) == 1)
				{
					(*prev) = ft_create_add_lstr((*prev));
					(*prev)->tree = ft_malloc_avl_node();
					continue;
//					get_next_line(STDIN_FILENO, &(*prev)->str);
//					printf("%s\n", (*prev)->str);
				}
				break;
			}
			root->end = (*prev)->tree;
			return (1);
		}
		else
			ft_close_error();
	}
	return (0);
}

int			ft_check_room(t_lstr **prev, avl_tree *root)
{
	char	**tmp;

	if (!(*prev)->str || !*((*prev)->str))
		ft_close_error();
	if (ft_strncmp("L", (*prev)->str, 1) == 0)
		ft_close_error();
	if (ft_strncmp("#", (*prev)->str, 1) == 0)
		if (ft_check_start_end(prev, root) == 0)
			return (1);
	if (!(tmp = ft_strsplit((*prev)->str, 32)))
		ft_close_error();
	if (!tmp[1])
	{
		ft_free_arr_str(&tmp);
		return (2);
	}
	ft_atoi_max(tmp[1]);
	ft_atoi_max(tmp[2]);
	if (tmp[3])
		ft_close_error();
	(*prev)->tree->name_room = tmp;
	return (0);
}

//int			ft_check_room(avl_node *tree, avl_tree *root)
//{
//	int		flag;
//
//	flag = 1;
//	if (!tree->str || !*(tree->str))
//		ft_close_error();
//	if (ft_strncmp("L", tree->str, 1) == 0)
//		ft_close_error();
//	if (ft_strncmp("#", tree->str, 1) == 0)
//		return (ft_check_start_end(tree, root));
//	tree->name_room = ft_strsplit(tree->str, 32);
//	if (!tree->name_room[1])
//		return (2);
//	ft_atoi_max(tree->name_room[1]);
//	ft_atoi_max(tree->name_room[2]);
//	if (tree->name_room[3])
//		ft_close_error();
//	return (7);
//}

int			ft_check_sharp_str(char *str)
{
	if (ft_strncmp("#", str, 1) == 0)
	{
		if (ft_strncmp("##", str, 2) == 0)
			ft_close_error();
//			return (0);
		else
			return (1);
	}
	return (7);
}

int		ft_check_link(t_lstr *prev, avl_tree *root)
{
	char	**tmp_link;

	if (!prev->str || !*(prev->str))
		ft_close_error();
	if (ft_check_sharp_str(prev->str) == 1)
		return (1);
	if (!(tmp_link = ft_strsplit(prev->str, '-')))
		ft_close_error();
	if (!tmp_link[0] || !tmp_link[1] || tmp_link[2])
		ft_close_error();
	prev->link->link_arr[0] = ft_find_room(tmp_link[0], root->root);
	prev->link->link_arr[1] = ft_find_room(tmp_link[1], root->root);
	if (!prev->link->link_arr[0] || !prev->link->link_arr[1])
		ft_close_error();
	ft_add_list(prev->link->link_arr[0], prev->link);
	ft_add_list(prev->link->link_arr[1], prev->link);
	ft_free_arr_str(&tmp_link);
	return (1);
}
