/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:15:51 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/09 21:31:14 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch += 32;
	return (ch);
}
// #include<stdio.h>
// int main()
// {
//     char c;

//     c = 'A';
//     for(; c <= 'Z'; c++)
//         printf("%c = %c\n", c, ft_tolower(c));
// }