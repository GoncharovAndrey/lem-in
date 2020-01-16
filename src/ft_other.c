/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:58:40 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/16 16:58:43 by cjosue           ###   ########.fr       */
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

t_avl_node		*ft_find_room(char *str, t_avl_node *root)
{
	t_avl_node	*tmp;
	int			side;

	tmp = root;
	while (tmp)
	{
		if (!(side = ft_strcmp(str, tmp->name_room[0])))
			return (tmp);
		side = (side > 0);
		tmp = tmp->link[side];
	}
	return (NULL);
}

void			ft_close_error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}
