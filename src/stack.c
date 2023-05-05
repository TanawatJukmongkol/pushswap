/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:48:28 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/25 01:48:52 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, char **argv)
{
	int		*s1;
	size_t	indx;

	indx = 0;
	s->len = parse_param(&s1, argv);
	if (check_inorder(s1, s->len))
	{
		free(s1);
		exit(0);
	}
	check_double(s1, s->len);
	s->s1 = NULL;
	while (indx < s->len)
	{
		push_a(s, s1[indx]);
		indx++;
	}
	free(s1);
	s->s2 = NULL;
}

void	push_a(t_stack *s, int nbr)
{
	if (!s->s1)
	{
		s->s1 = malloc(sizeof(t_slst));
		s->s1->prev = NULL;
		s->s1_last = s->s1;
	}
	else
	{
		s->s1_last->next = malloc(sizeof(t_slst));
		s->s1_last->next->prev = s->s1_last;
		s->s1_last = s->s1_last->next;
	}
	s->s1_last->nbr = nbr;
	s->s1_last->next = NULL;
}

void	push_b(t_stack *s, int nbr)
{
	if (!s->s2)
	{
		s->s2 = malloc(sizeof(t_slst));
		s->s2->prev = NULL;
		s->s2_last = s->s2;
	}
	else
	{
		s->s2_last->next = malloc(sizeof(t_slst));
		s->s2_last->next->prev = s->s2_last;
		s->s2_last = s->s2_last->next;
	}
	s->s2_last->nbr = nbr;
	s->s2_last->next = NULL;
}

void	shift_a(t_stack *s)
{
	t_slst	*tmp;

	if (s->s1 == NULL)
		return ;
	tmp = s->s1;
	if (s->s1->next == NULL)
	{
		s->s1_last = NULL;
		free(tmp);
		s->s1 = NULL;
		return ;
	}
	s->s1 = s->s1->next;
	s->s1->prev = NULL;
	free(tmp);
}

void	shift_b(t_stack *s)
{
	t_slst	*tmp;

	if (s->s2 == NULL)
		return ;
	tmp = s->s2;
	if (s->s2->next == NULL)
	{
		s->s2_last = NULL;
		free(tmp);
		s->s2 = NULL;
		return ;
	}
	s->s2 = s->s2->next;
	s->s2->prev = NULL;
	free(tmp);
}
