/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:05:14 by cjosue            #+#    #+#             */
/*   Updated: 2020/01/06 18:05:16 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_print_res(t_ant *ant, avl_tree *root)
{
	int		i;
	int		y;

	i = 1;
	while(i < root->day[0])
	{
		y = 1;
		printf("\n%d - day\n", i);
		while (y <= root->ant)
		{
//			printf("%d - y  %i\n", y,i);
			if (ant[y].day == i)
			{
				write(1, "L", 1);
				ft_putnbr(ant[y].ant_name);
				write(1, "-", 1);
				ft_putstr(ant[y].head->data->link_arr[0]->name_room[0]);
				write(1, " ", 1);
				ant[y].day++;
				ant[y].head = ant[y].head->next;
				if (ant[y].head == NULL)
					ant[y].day = 0;
			}
			y++;
		}
		write(1, "\n", 1);
		i++;
	}
}
