/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:57:25 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/13 19:57:28 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			ft_for_left_rotation(t_avl_node ***tmp)
{
	*tmp[1] = tmp[0][0]->link[1];
	tmp[0][3] = *tmp[1];
	tmp[0][0]->link[1] = tmp[0][3]->link[0];
	tmp[0][3]->link[0] = tmp[0][0];
	tmp[0][1]->link[0] = tmp[0][3]->link[1];
	tmp[0][3]->link[1] = tmp[0][1];
	if (tmp[0][3]->bal == -1)
	{
		tmp[0][1]->bal = 1;
		tmp[0][0]->bal = 0;
	}
	else if (tmp[0][3]->bal == 0)
	{
		tmp[0][0]->bal = 0;
		tmp[0][1]->bal = 0;
	}
	else
	{
		tmp[0][1]->bal = 0;
		tmp[0][0]->bal = -1;
	}
	tmp[0][3]->bal = 0;
}

void				ft_left_rotation(t_avl_node ***tmp)
{
	if (tmp[0][1]->bal != -1)
		tmp[0][1]->bal--;
	else if (tmp[0][0]->bal == -1)
	{
		*tmp[1] = tmp[0][0];
		tmp[0][1]->link[0] = tmp[0][0]->link[1];
		tmp[0][0]->link[1] = tmp[0][1];
		tmp[0][1]->bal = 0;
		tmp[0][0]->bal = 0;
	}
	else
		ft_for_left_rotation(tmp);
}

static void			ft_for_right_rotation(t_avl_node ***tmp)
{
	*tmp[1] = tmp[0][0]->link[0];
	tmp[0][3] = *tmp[1];
	tmp[0][0]->link[0] = tmp[0][3]->link[1];
	tmp[0][3]->link[1] = tmp[0][0];
	tmp[0][1]->link[1] = tmp[0][3]->link[0];
	tmp[0][3]->link[0] = tmp[0][1];
	if (tmp[0][3]->bal == 1)
	{
		tmp[0][1]->bal = -1;
		tmp[0][0]->bal = 0;
	}
	else if (tmp[0][3]->bal == 0)
	{
		tmp[0][1]->bal = 0;
		tmp[0][0]->bal = 0;
	}
	else
	{
		tmp[0][1]->bal = 0;
		tmp[0][0]->bal = 1;
	}
	tmp[0][3]->bal = 0;
}

void				ft_right_rotation(t_avl_node ***tmp)
{
	if (tmp[0][1]->bal != 1)
		tmp[0][1]->bal++;
	else if (tmp[0][0]->bal == 1)
	{
		*tmp[1] = tmp[0][0];
		tmp[0][1]->link[1] = tmp[0][0]->link[0];
		tmp[0][0]->link[0] = tmp[0][1];
		tmp[0][1]->bal = 0;
		tmp[0][0]->bal = 0;
	}
	else
		ft_for_right_rotation(tmp);
}
