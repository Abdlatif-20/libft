/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:44:36 by aben-nei          #+#    #+#             */
/*   Updated: 2022/11/04 17:00:50 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	hexa_len(unsigned int nb)
{
	int len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return(len);
}

void    ft_convert_hexa(int nb, const char format, int *i, int *j)
{
	if (nb >= 16)
	{
		ft_convert_hexa(nb / 16, format, i, j);
		ft_convert_hexa(nb % 16, format, i, j);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar_fd(nb + '0', 1);
			(*j)++;
			(*i)++;
		}
		else
		{
			if (format == 'x')
			{
				ft_putchar_fd((nb - 10 + 'a'), 1);
				(*j)++;
				(*i)++;
			}

			if (format == 'X')
			{
				ft_putchar_fd((nb - 10 + 'A'), 1);
				(*j)++;
				(*i)++;	
			}
		}
	}	
}

void	ft_print_hexa(int nb, const char format, int *i, int *j)
{
	if (nb == 0)
		ft_putchar_fd('0', 1);
	else
		ft_convert_hexa(nb, format, i, j);
}
