/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:24:43 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 22:25:59 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix(t_stack *s, int *args, int len, int d)
{
	int	i;

	if (check_inorder(args, len))
	{
		free(args);
		return (1);
	}
	i = 0;
	while (i < len)
	{
		if (args[i] & (1 << d))
			exec(s, ra);
		else
			exec(s, pb);
		i++;
	}
	return (0);
}

void	radix_sort(t_stack *s)
{
	int	*args;
	int	len;
	int	d;
	int	min;
	int	in_order;

	d = 0;
	min = get_min(s->s1, NULL);
	while (1)
	{
		len = stackx_to_arr(s, 'a', &args);
		if (radix(s, args, len, d) || d++ > 32)
			break ;
		free(args);
		len = stackx_to_arr(s, 'a', &args);
		in_order = (check_inorder(args, len) && s->s1->nbr == min);
		while (s->s2 != NULL)
			exec(s, pa);
		if (in_order)
			while (s->s1->nbr != min)
				exec(s, rra);
		free(args);
	}
}
