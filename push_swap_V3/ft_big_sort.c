/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:26:38 by aben-nei          #+#    #+#             */
/*   Updated: 2023/01/22 22:42:08 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two(t_list **stack_a, t_list **stack_b)
{
	int pos_prev_max;
	int size;
	
	pos_prev_max = position(*stack_b, get_index_of_prev_max(*stack_b));
	size = ft_lstsize(*stack_b); 
	if (pos_prev_max > size / 2)
		while (position(*stack_b, get_index_of_prev_max(*stack_b)) > 0)
			ft_rra_rrb(stack_b, "rrb\n");
	else
		while (position(*stack_b, get_index_of_prev_max(*stack_b)) > 0)
			ft_ra_rb(stack_b, "rb\n");		
	if (!position(*stack_b, get_index_of_prev_max(*stack_b)))
		ft_pa_pb(stack_b, stack_a, "pa\n");
	while (position(*stack_b, get_index_of_max(*stack_b)) > 0
			&& position(*stack_b, get_index_of_max(*stack_b)) < size / 2)
		ft_ra_rb(stack_b, "rb\n");
	while (position(*stack_b, get_index_of_max(*stack_b)) > 0
			&& position(*stack_b, get_index_of_max(*stack_b)) >= size / 2)
		ft_rra_rrb(stack_b, "rrb\n");
	ft_pa_pb(stack_b, stack_a, "pa\n");
	if ((*stack_a)->next && (*stack_a)->index > (*stack_a)->next->index)
		ft_sa_sb(stack_a, "sa\n");
}

static void finaly_sort_500(t_list **stack_a, t_list **stack_b)
{
	int	instr1;
	int	instr2;
	int	size;
	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		instr1 = num_of_instrection(size, position(*stack_b, get_index_of_max(*stack_b)));
		instr2 = num_of_instrection(size, position(*stack_b, get_index_of_prev_max(*stack_b)));
		if (instr1 > instr2)
			push_two(stack_a, stack_b);
		else
		{
			if (position(*stack_b, get_index_of_max(*stack_b)) > size / 2)
				while (position(*stack_b, get_index_of_max(*stack_b)) > 0)
					ft_rra_rrb(stack_b, "rrb\n");
			else
				while (position(*stack_b, get_index_of_max(*stack_b)) > 0)
					ft_ra_rb(stack_b, "rb\n");
			if (!position(*stack_b, get_index_of_max(*stack_b)))
				ft_pa_pb(stack_b, stack_a, "pa\n");
		}
	}
}

void ft_big_sort_500(t_list **stack_a, t_list **stack_b, int chunk)
{
	int i;
	
	i = -1;
	while (*stack_a)
	{
		while (++i < chunk && *stack_a)
		{
			while (check_position((*stack_a), chunk) < ft_lstsize(*stack_a) / 2 && (*stack_a)->index > chunk)
				ft_ra_rb(stack_a, "ra\n");
			while (check_position((*stack_a), chunk) >= ft_lstsize(*stack_a) / 2 && (*stack_a)->index > chunk)
				ft_rra_rrb(stack_a, "rra\n");
			if ((*stack_a)->index > chunk - 27)
			{
				ft_pa_pb(stack_a, stack_b, "pb\n");
				if ((*stack_a)->index < ft_lstsize(*stack_a) / 2 && (*stack_a)->index > chunk)
					ft_rr(stack_a, stack_b, "rr\n");
				else
				ft_ra_rb(stack_b, "rb\n");
			}
			else
				ft_pa_pb(stack_a, stack_b, "pb\n");
		}
			chunk += 55;
	}
	finaly_sort_500(stack_a, stack_b);
}
