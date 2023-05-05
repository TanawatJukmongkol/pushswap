/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:33:17 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/05 23:19:13 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_nullarg(char *param, void *aloc)
{
	if (param[0] == '\0')
	{
		if (aloc != NULL)
			free(aloc);
		error_out();
	}
}

char	*join_params(char **param)
{
	size_t	indx;
	char	*tmp;
	char	*join;

	if (param[1] == NULL)
		exit(0);
	check_nullarg(param[1], NULL);
	indx = 1;
	join = NULL;
	tmp = ft_strdup("");
	while (param[indx])
	{
		if (join)
		{
			check_nullarg(param[indx], tmp);
			tmp = ft_strdup(join);
			free(join);
		}
		join = ft_strjoin(tmp, param[indx++]);
		free(tmp);
		tmp = ft_strjoin(join, " ");
		free(join);
		join = tmp;
	}
	return (join);
}

void	contain_invalid_str(char *str)
{
	size_t	indx;

	indx = 0;
	while (str[indx])
	{
		if (
			!ft_isdigit(str[indx])
			&& (str[indx] != '-' || !ft_isdigit(str[indx + 1]))
			&& (str[indx] != '+' || !ft_isdigit(str[indx + 1]))
			&& str[indx] != ' '
		)
		{
			free(str);
			error_out();
		}
		indx++;
	}
}

size_t	parse_param(int **stack, char **param)
{
	size_t	indx;
	char	*joined;
	char	**split;

	joined = join_params(param);
	contain_invalid_str(joined);
	split = ft_split(joined, ' ');
	free(joined);
	indx = 0;
	while (split[indx] != NULL)
		indx++;
	*stack = malloc(sizeof(int) * indx);
	indx = 0;
	while (split[indx] != NULL)
	{
		(*stack)[indx] = atoi_check(stack, split[indx]);
		free(split[indx]);
		indx++;
	}
	free(split);
	return (indx);
}
