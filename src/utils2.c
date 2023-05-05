/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:09 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 23:42:23 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_slst *s, int *indx)
{
	t_slst	tmp;
	int		min;
	int		i;

	tmp = *s;
	min = 2147483647;
	i = 0;
	while (1)
	{
		if (tmp.nbr < min)
		{
			min = tmp.nbr;
			if (indx != NULL)
				*indx = i;
		}
		if (tmp.next == NULL)
			break ;
		tmp = *tmp.next;
		i++;
	}
	return (min);
}

// int	get_max(t_slst *s, int *indx)
// {
// 	t_slst	tmp;
// 	int		max;
// 	int		i;

// 	tmp = *s;
// 	max = -2147483648;
// 	i = 0;
// 	while (1)
// 	{
// 		if (tmp.nbr > max)
// 		{
// 			max = tmp.nbr;
// 			if (indx != NULL)
// 				*indx = i;
// 		}
// 		if (tmp.next == NULL)
// 			break ;
// 		tmp = *tmp.next;
// 		i++;
// 	}
// 	return (max);
// }

void	push_min(t_stack *s)
{
	int	min_indx;
	int	min;

	min_indx = 0;
	min = get_min(s->s1, &min_indx);
	if (min_indx <= 2)
		while (s->s1->nbr != min)
			exec(s, ra);
	else
		while (s->s1->nbr != min)
			exec(s, rra);
	exec(s, pb);
}
