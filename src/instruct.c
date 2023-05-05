/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:22:13 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/29 19:37:27 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s, enum e_opcode op_code)
{
	if (op_code == ra || (op_code == rr && s->s1 != NULL))
	{
		push_a(s, s->s1->nbr);
		shift_a(s);
	}
	if (op_code == rb || (op_code == rr && s->s2 != NULL))
	{
		push_b(s, s->s2->nbr);
		shift_b(s);
	}
	if (op_code == rra || (op_code == rrr && s->s1 != NULL))
	{
		unshift_a(s, s->s1_last->nbr);
		pop_a(s);
	}
	if (op_code == rrb || (op_code == rrr && s->s2 != NULL))
	{
		unshift_b(s, s->s2_last->nbr);
		pop_b(s);
	}
}

void	push(t_stack *s, enum e_opcode op_code)
{
	if (op_code == pa && s->s2)
	{
		unshift_a(s, s->s2->nbr);
		shift_b(s);
	}
	else if (op_code == pb && s->s1)
	{
		unshift_b(s, s->s1->nbr);
		shift_a(s);
	}
	if (op_code == pa)
		ft_putendl_fd("pa", 1);
	else if (op_code == pb)
		ft_putendl_fd("pb", 1);
}

void	swap(t_stack *s, enum e_opcode op_code)
{
	int	tmp;

	if ((op_code == sa || op_code == ss)
		&& s->s1 != NULL && s->s1->next != NULL)
	{
		tmp = s->s1->nbr;
		s->s1->nbr = s->s1->next->nbr;
		s->s1->next->nbr = tmp;
	}
	if ((op_code == sb || op_code == ss)
		&& s->s2 != NULL && s->s2->next != NULL)
	{
		tmp = s->s2->nbr;
		s->s2->nbr = s->s2->next->nbr;
		s->s2->next->nbr = tmp;
	}
	if (op_code == sa)
		ft_putendl_fd("sa", 1);
	else if (op_code == sb)
		ft_putendl_fd("sb", 1);
	else if (op_code == ss)
		ft_putendl_fd("ss", 1);
}

#if DEBUG_MODE == 1

void	exec(t_stack *s, enum e_opcode op_code)
{
	rotate(s, op_code);
	if (op_code == ra)
		ft_putendl_fd("ra", 1);
	else if (op_code == rb)
		ft_putendl_fd("rb", 1);
	else if (op_code == rr)
		ft_putendl_fd("rr", 1);
	if (op_code == rra)
		ft_putendl_fd("rra", 1);
	else if (op_code == rrb)
		ft_putendl_fd("rrb", 1);
	else if (op_code == rrr)
		ft_putendl_fd("rrr", 1);
	push(s, op_code);
	swap(s, op_code);
	print_stack(s);
}
#else

void	exec(t_stack *s, enum e_opcode op_code)
{
	rotate(s, op_code);
	if (op_code == ra)
		ft_putendl_fd("ra", 1);
	else if (op_code == rb)
		ft_putendl_fd("rb", 1);
	else if (op_code == rr)
		ft_putendl_fd("rr", 1);
	if (op_code == rra)
		ft_putendl_fd("rra", 1);
	else if (op_code == rrb)
		ft_putendl_fd("rrb", 1);
	else if (op_code == rrr)
		ft_putendl_fd("rrr", 1);
	push(s, op_code);
	swap(s, op_code);
}
#endif
