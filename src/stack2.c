/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:11:17 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/29 19:35:21 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	unshift_a(t_stack *s, int nbr)
{
	t_slst	*tmp;

	if (s->s1 == NULL)
		return (push_a(s, nbr));
	tmp = malloc(sizeof(t_slst));
	tmp->nbr = nbr;
	tmp->next = s->s1;
	s->s1->prev = tmp;
	s->s1 = tmp;
}

void	unshift_b(t_stack *s, int nbr)
{
	t_slst	*tmp;

	if (s->s2 == NULL)
		return (push_b(s, nbr));
	tmp = malloc(sizeof(t_slst));
	tmp->nbr = nbr;
	tmp->next = s->s2;
	s->s2->prev = tmp;
	s->s2 = tmp;
}

void	pop_a(t_stack *s)
{
	t_slst	*tmp;

	if (s->s1_last == NULL)
		return ;
	tmp = s->s1_last->prev;
	free(s->s1_last);
	s->s1_last = tmp;
	if (tmp == NULL)
	{
		s->s1 = NULL;
		return ;
	}
	tmp->next = NULL;
}

void	pop_b(t_stack *s)
{
	t_slst	*tmp;

	if (s->s2_last == NULL)
		return ;
	tmp = s->s2_last->prev;
	free(s->s2_last);
	s->s2_last = tmp;
	if (tmp == NULL)
	{
		s->s2 = NULL;
		return ;
	}
	tmp->next = NULL;
}

int	stackx_to_arr(t_stack *s, char x, int **arr)
{
	t_slst	*tmp;
	int		i;

	*arr = malloc(s->len * sizeof(int));
	i = 0;
	if (x == 'a')
		tmp = s->s1;
	else if (x == 'b')
		tmp = s->s2;
	else
		return (0);
	while (tmp)
	{
		(*arr)[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (i);
}
