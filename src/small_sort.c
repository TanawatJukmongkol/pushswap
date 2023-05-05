/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:16:29 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 23:41:11 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s, char x)
{
	if (x == 'a')
	{
		if (s->s1->nbr > s->s1_last->nbr)
			exec(s, ra);
		if (s->len == 2)
			return ;
		if (s->s1->nbr > s->s1_last->nbr)
			exec(s, ra);
		if (s->s1->next->nbr > s->s1_last->nbr)
			exec(s, rra);
		if (s->s1->nbr > s->s1->next->nbr)
			exec(s, sa);
		return ;
	}
	if (s->s2->nbr > s->s2_last->nbr)
		exec(s, rb);
	if (s->len == 2)
		return ;
	if (s->s2->nbr > s->s2_last->nbr)
		exec(s, rb);
	if (s->s2->next->nbr > s->s2_last->nbr)
		exec(s, rrb);
	if (s->s2->nbr > s->s2->next->nbr)
		exec(s, sb);
}

void	sort_5(t_stack *s)
{
	push_min(s);
	push_min(s);
	sort_3(s, 'a');
	if (s->s2->nbr < s->s2->next->nbr)
		exec(s, sb);
	exec(s, pa);
	exec(s, pa);
}

void	sort_50(t_stack *s)
{
	int	n;

	n = s->len;
	while (n > 5)
	{
		push_min(s);
		n--;
	}
	sort_5(s);
	while (s->s2)
	{
		if (s->s2->next && s->s2->nbr < s->s2->next->nbr)
			exec(s, sb);
		exec(s, pa);
	}
}

void	small_sort(t_stack *s)
{
	if (s->len <= 3)
		sort_3(s, 'a');
	else if (s->len <= 5)
		sort_5(s);
	else if (s->len <= 50)
		sort_50(s);
}
