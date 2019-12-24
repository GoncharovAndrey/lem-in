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
	avl_node ** v, *w, *x, *y, *z;

/* если в дереве еще нет узлов */
	v = &tree->root;
	x = z = tree->root;
	if(x == NULL)
	{
		tree->root = new_node;
		tree->count++;
		return 1;
//		return tree->root != NULL;
	}

/* фрагмент №1 */
/* поиск подходящей позиции и последующая вставка элемента */
	for(;;)
	{
		int dir;
		/* такой элемент уже есть в дереве – функцию можно завершить */
		if(!(dir = ft_strcmp(new_node->name_room, z->name_room)) /* item == z->data*/)
			return 2;
		dir = (dir > 0 /*item > z->data*/) ;
		y = z->link[dir];
		if(y == NULL)
		{
			y = z->link[dir] = new_node;
			tree->count++;
			if(y == NULL)
				return 0;
			break;
		}
		if(y->bal != 0)
		{
			v = &z->link[dir];
			x = y;
		}
		z = y;
	}

/* фрагмент №2 */
/* пересчет коэффициентов сбалансированности для узлов, затронутых вставкой */
	w = z = x->link[ft_strcmp(new_node->name_room, x->name_room) > 0 /*item > x->data*/];
	while(z != y)
		if(ft_strcmp(new_node->name_room, z->name_room) < 0   /*item < z->data*/)
		{
			z->bal = -1;
			z = z->link[0];
		}
		else
		{
			z->bal   =   +1;
			z = z->link[1];
		}

/* фрагмент № 3 */
/* балансировка при добавлении нового узла в левое поддерево */
	if(ft_strcmp(new_node->name_room, x->name_room) < 0 /*item < x->data*/)
	{
		if (x->bal != -1)
			x->bal --;
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