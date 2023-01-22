/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:12:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/01/22 02:00:43 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "./get_next_line/get_next_line.h"

void statement(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!strcmp(str, "ra\n"))
		ft_ra_rb(stack_a, "");
	else if (!strcmp(str, "rb\n"))
		ft_ra_rb(stack_b, "");
	else if (!strcmp(str, "sa\n"))
		ft_sa_sb(stack_a, "");
	else if (!strcmp(str, "sb\n"))
		ft_sa_sb(stack_b, "");
	else if (!strcmp(str, "pb\n"))
		ft_pa_pb(stack_a, stack_b, "");
	else if (!strcmp(str, "pa\n"))
		ft_pa_pb(stack_b, stack_a, "");
}
int main(int ac, char **av)
{
	char *str;
	t_list	**head_a;
	t_list	**head_b;
	
	filed_arr(av, ac, head_a);
	get_index(*head_a);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break;
		statement (head_a, head_b, str);
	}
}