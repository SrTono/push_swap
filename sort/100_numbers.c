/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:34:36 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/29 19:52:38 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.-Pasar x% a b y ir Pseudoornenado los datos
2.-Ordenar ultimos numeros
3.-Pasar los nummeros ordenados de mañor a menor
*/
//https://gitlab.com/42cursus-wetieven/23-push-swap

//https://www.ugr.es/~jsalinas/Aleatorios.htm
#include "../push_swap.h"

static int	max_index(t_order *list)
{
	int	len;
	int	max;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	max = list->index;
	list = list->next;
	while (len > i++)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	//ft_printf("x%dx", min);
	return (max);

}
t_order	*hundred_number(t_order *list_a)
{
	t_order *list_b;
	int	max;
	int	min;
	int	top;
	int	i;
	int	interval;

	created_index(list_a);
	top = max_index(list_a);
	interval = (top / 5) + 1;
	min = 0;
	max = min + interval;
	//min = (max - interval) + 1;
	//ft_printf("/FIN/max = %d, min = %d, intelval= %d, max-min = %d\n", max, min, interval, (max - min));
	i = 0;
	(void)list_b;
	list_a = find_first_list(list_a);
	list_b = ft_calloc(1, sizeof(t_order));
	while (5 > i++)
	{
		//ft_printf("/principio/max = %d, min = %d, intelval= %d, max-min = %d\n", max, min, interval, (max - min));
		list_a = move_block_b(list_a, list_b, min, max);
		min = max + 1;
		max = min + interval;
		if (top - 5 <= max)
			max = top - 5;
		list_b = find_first_list(list_b);
			//print_cosas(list_b);
		//ft_printf("-%d-", list_b->number);
		//ft_printf("/FIN/max = %d, min = %d, intelval= %d, max-min = %d\n", max, min, interval, (max - min));
	}
	//min_to_top(list_a, -1);
	//print_cosas(list_b);
	list_a = five_number(list_a);
	total_return(list_b, list_a, top - 5);
	//ft_printf("-----------FIN------\n");
	list_a = find_first_list(list_a);
	//print_cosas(list_a);

	//print_cosas(list_b);
	return (list_a);
}

