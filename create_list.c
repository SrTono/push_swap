/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:13:30 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/14 12:54:52 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_order	*create_new_block(t_order *list_a, int out, int position)
{
	t_order	*tmp;

	tmp = ft_calloc(1, sizeof(t_order));
	tmp->number = out;
	tmp->position = position;
	list_a->next = tmp;
	return (tmp);
}

static t_order	*praimal_list(int out)
{
	t_order	*tmp;

	tmp = ft_calloc(1, sizeof(t_order));
	tmp->number = out;
	tmp->position = 0;
	return (tmp);
}

static int	check_number(char *number)
{
	int len;
	int i;

	len = ft_strlen(number);
	i = -1;
	while (len > ++i)
	{
		if ('0' > number[i] || number[i] > '9')
		{
			ft_printf("Error:\n list not a number");
			exit(0);
		}
	}
	return (ft_atoi(number));
}

static void	*str_to_list(char *str, int position, t_order *list_a)
{
	char		**number;
	int			col;
	int			out;
	int			i;
	t_header	header;

	col = -1;
	i = 0;
	number = ft_split(str, ' ');
	while (number[++col] != '\0')
	{
		out = check_number(number[col]);
		if (position == 0)
		{
			list_a = praimal_list(out);
			header.first = list_a;
		}
		else
			list_a = to_next(list_a, out, position);
		if (position++ != 0 && i == 0)
			header.first = list_a;
	}
	free_map(number);
	list_a->next = NULL;
	return (header.first);
}

t_order	*create_list(char **raw, t_order *list_a)
{
	int			out;
	int			position;
	int			i;
	t_header	header;

	position = 0;
	i = 0;
	while (raw[++i] != NULL)
	{
		if (ft_strchr(raw[i], ' '))
		{
			list_a = str_to_list(raw[i], position, list_a);
			if (position == 0)
				header.first = list_a;
			i++;
			list_a = find_end_list(list_a);
			position = list_a->position + 1;
		}
		out = check_number(raw[i]);
		if (position == 0)
		{
			list_a = praimal_list(out);
			header.first = list_a;
		}
		else
			list_a = to_next(list_a, out, position);
		position++;
	}
	list_a->next = NULL;
	return (header.first);
}
