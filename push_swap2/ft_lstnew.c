/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:24:52 by aben-nei          #+#    #+#             */
/*   Updated: 2023/01/14 00:58:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long long content)
{
	t_list	*p;
	static int	i = 0;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->data = content;
	p->index = -1;
	p->place = -1;
	p->next = NULL;
	return (p);
}
