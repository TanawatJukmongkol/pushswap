/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:53:36 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 23:51:17 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEBUG_MODE 0

# include <stdlib.h>
# include "../lib/libft/libft.h"

# if DEBUG_MODE == 1
#  include <stdio.h>
# endif

typedef struct s_slst
{
	int				nbr;
	struct s_slst	*next;
	struct s_slst	*prev;
}				t_slst;

typedef struct s_stack
{
	t_slst	*s1;
	t_slst	*s2;
	t_slst	*s1_last;
	t_slst	*s2_last;
	size_t	len;
}				t_stack;

enum	e_opcode
{
	sa	= 0x0,
	sb	= 0x1,
	ss	= 0x2,
	pa	= 0x3,
	pb	= 0x4,
	ra	= 0x5,
	rb	= 0x6,
	rr	= 0x7,
	rra	= 0x8,
	rrb	= 0x9,
	rrr	= 0xa
};

// Utils
int		atoi_check(int **stack, char *str);
void	check_double(int *args, size_t len);
int		check_inorder(int *args, size_t len);
int		get_min(t_slst *s, int *indx);
// int		get_max(t_slst *s, int *indx);
void	push_min(t_stack *s);
void	print_stack(t_stack *s);

// Parser
void	error_out(void);
char	*join_params(char **param);
void	contain_invalid_str(char *str);
size_t	parse_param(int **stack, char **param);

// Stack
void	init_stack(t_stack *s, char **argv);
void	push_a(t_stack *s, int nbr);
void	push_b(t_stack *s, int nbr);
void	shift_a(t_stack *s);
void	shift_b(t_stack *s);
void	unshift_a(t_stack *s, int nbr);
void	unshift_b(t_stack *s, int nbr);
void	pop_a(t_stack *s);
void	pop_b(t_stack *s);
int		stackx_to_arr(t_stack *s, char x, int **arr);

// Instruction
void	exec(t_stack *s, enum e_opcode op_code);

// Algorithms
void	radix_sort(t_stack *s);
void	small_sort(t_stack *s);

#endif