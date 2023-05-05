/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:01:16 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 23:09:24 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_out(void)
{
	write(2, "Error\n", 6);
	exit(255);
}

int	atoi_check(int **stack, char *str)
{
	long	tmp;

	tmp = atol(str);
	if (tmp < -2147483648 || tmp > 2147483647)
	{
		free(*stack);
		error_out();
	}
	return (tmp);
}

void	check_double(int *args, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 1)
		return ;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (args[i] == args[j])
			{
				free(args);
				error_out();
			}
			j++;
		}
		i++;
	}
}

int	check_inorder(int *args, size_t len)
{
	size_t	i;
	int		max;

	if (len == 0)
		return (0);
	i = 0;
	max = -2147483648;
	while (i < len)
	{
		if (args[i] >= max)
			max = args[i];
		else
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *s)
{
	t_slst	*tmp;

	ft_putstr_fd("stack1 | ", 1);
	tmp = s->s1;
	while (1)
	{
		if (tmp == NULL)
			break ;
		ft_putnbr_fd(tmp->nbr, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("stack2 | ", 1);
	tmp = s->s2;
	while (1)
	{
		if (tmp == NULL)
			break ;
		ft_putnbr_fd(tmp->nbr, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n\n", 1);
}
