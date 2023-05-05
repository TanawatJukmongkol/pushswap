/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:36:01 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 23:38:01 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	(void)(argc);
	init_stack(&stack, argv);
	if (stack.len > 50)
		radix_sort(&stack);
	else
		small_sort(&stack);
	while (stack.s1)
		shift_a(&stack);
	return (0);
}
