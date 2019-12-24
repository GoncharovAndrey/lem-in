/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:15:24 by cjosue            #+#    #+#             */
/*   Updated: 2019/12/24 17:15:26 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				avl_insert(avl_tree *tree, avl_node *new_node)
{
	avl_node	**v, *w, *x, *y, *z;
	int			side;

/* если в дереве еще нет узлов */
	v = &tree->root;
	x = z = tree->root;
	if(x == NULL)
	{
//		ft_printf("tut\n");
		tree->root = new_node;
		return (1);
//		return tree->root != NULL;
	}
/* фрагмент №1 */
/* поиск подходящей позиции и последующая вставка элемента */
	while(z)
	{
		/* такой элемент уже есть в дереве – функцию можно завершить */
		if(!(side = ft_strcmp(z->name_room, new_node->name_room)))
			return 2;
		side = (side < 0);
		y = z->link[side];
		if(y == NULL)
		{
			y = z->link[side] = new_node;
			tree->count++;
//			if(y == NULL)
//				return 0;
			break;
		}
		if(y->bal != 0)
		{
			v = &z->link[side];
			x = y;
		}
		z = y;
	}
/* фрагмент №2 */
/* пересчет коэффициентов сбалансированности для узлов, затронутых вставкой */
	w = z = x->link[ft_strcmp(x->name_room, new_node->name_room) < 0];
	while(z != y)
	{
		if(ft_strcmp(z->name_room, new_node->name_room) > 0)
		{
			z->bal = -1;
			z = z->link[0];
		}
		else
		{
			z->bal = 1;
			z = z->link[1];
		}
	}
/* фрагмент № 3 */
/* балансировка при добавлении нового узла в левое поддерево */
	if(ft_strcmp(x->name_room, new_node->name_room) > 0)
	{
		if (x->bal != -1)
			x->bal--;
		else if(w->bal == -1)
		{
			*v=w;
			x->link[0] = w->link[1];
			w->link[1] = x;
			x->bal = w->bal = 0;
		}
		else
		{
			*v = z = w->link[1];
			w->link[1] = z->link[0];
			z->link[0] = w;
			x->link[0] = z->link[1];
			z->link[1] = x;
			if(z->bal == -1)
			{
				x->bal = 1;
				w->bal = 0;
			}
			else if(z->bal == 0)
				x->bal = w->bal = 0;
			else
			{
				x->bal = 0;
				w->bal = -1;
			}
			z->bal=0;
		}
	}
/* фрагмент № 4 */
/* балансировка при добавлении нового узла в правое поддерево */
	else
	{
		if( x->bal != +1)
			x->bal++;
		else if(w->bal == +1)
		{
			*v = w;
			x->link[1] = w->link[0];
			w->link[0] = x;
			x->bal = w->bal = 0;
		}
		else
		{
			*v = z = w->link[0];
			w->link[0] = z->link[1];
			z->link[1] = w;
			x->link[1] = z->link[0];
			z->link[0] = x;
			if(z->bal == +1)
			{
				x->bal = -1;
				w->bal = 0;
			}
			else if(z->bal == 0)
				x->bal = w->bal = 0;
			else
			{
				x->bal = 0;
				w->bal = 1;
			}
			z->bal = 0;
		}
	}
	return 1;
}
