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

int				ft_atoi_max(const char *nptr, int *flag)
{
	size_t		i;
	long int	res;
	int			z;

	res = 0;
	i = 0;
	z = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	z = nptr[i] == '-' ? -1 : 1;
	i = nptr[i] == '-' || nptr[i] == '+' ? i + 1 : i + 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((z * res) > INT_MAX || (z * res) < INT_MIN)
		{
			*flag = 0;
			return (-1);
		}
		i++;
	}
	return (res * z);
}

int			ft_check_start_end(avl_node *tree, avl_tree *root)
{
	if (ft_strncmp("##", tree->str, 2) == 0)
	{
		if (ft_strcmp("##start", tree->str) == 0)
		{
			if (root->start)
				return (0);
			root->start = tree + 1;
			return (1);
		}
		else if (ft_strcmp("##end", tree->str) == 0)
		{
			if (root->end)
				return (0);
			root->end = tree + 1;
			return (1);
		}
		else
			return (0);
	}
//	++*tree;
	return (1);
}

int			ft_check_room(avl_node *tree, avl_tree *root)
{
	int		flag;

	flag = 1;
	if (!tree->str || !*(tree->str))
		return (0);
	if (ft_strncmp("L", tree->str, 1) == 0)
		return (0);
//	printf("%s \n", tree->str);
	if (ft_strncmp("#", tree->str, 1) == 0)
		return (ft_check_start_end(tree, root));
	tree->name_room = ft_strsplit(tree->str, 32);
	if (!tree->name_room[1])
		return (2);
	ft_atoi_max(tree->name_room[1], &flag);
	if (!tree->name_room[2])
		return (0);
	ft_atoi_max(tree->name_room[2], &flag);
	if (!flag)
		return (0);
	if (tree->name_room[3])
		return (0);
	return (7);
}

int		ft_check_link(t_link *link, avl_tree *root)
{
	char	**tmp_link;

	if (!link->str || !*(link->str))
		return (0);
	if (!(tmp_link = ft_strsplit(link->str, '-')))
		return (0);
	if (!tmp_link[0] || !tmp_link[1] || tmp_link[2])
	{
		ft_free_arr_str(&tmp_link);
		return (0);
	}
	link->link_arr[0] = ft_find_room(tmp_link[0], root->root);
	link->link_arr[1] = ft_find_room(tmp_link[1], root->root);
	if (!link->link_arr[0] || !link->link_arr[1])
	{
		ft_free_arr_str(&tmp_link);
		return (0);
	}
	ft_add_list(link->link_arr[0], link);
	ft_add_list(link->link_arr[1], link);
	ft_free_arr_str(&tmp_link);
	return (1);
}
