/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:59:49 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/23 16:59:51 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/lem_in.h>
#include <stdio.h>

int		main()
{
	avl_node	tree[15];
	avl_tree	root;
	int			i;

	i = 0;
	root.root = NULL;
	root.count = 0;
	while (i < 15)
	{
		tree[i].name_room = ft_itoa(i + 1);
		tree[i].link[0] = NULL;
		tree[i].link[1] = NULL;
		avl_insert(&root, &tree[i]);
		printf("%s\n", tree[i].name_room);
		i++;
	}
	printf("%s  %s   %s\n", tree[7].link[0]->name_room, tree[7].name_room, tree[7].link[1]->name_room);
}
