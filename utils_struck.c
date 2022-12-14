/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:29:05 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/14 12:48:08 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_order	*to_next(t_order *list_a, int out, int position) //pruebas
{
	list_a->next = create_new_block(list_a, out, position);
	list_a = list_a->next;
	return (list_a);
}

t_order	*find_end_list(t_order *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	ft_struclen(t_order *list)
{
	int count;

	count = 0;
	while (list->next != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

