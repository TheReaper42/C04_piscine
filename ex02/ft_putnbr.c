/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzolotuk <dzolotuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:54:09 by dzolotuk          #+#    #+#             */
/*   Updated: 2023/07/04 14:54:11 by dzolotuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		divisor;
	int		temp;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	divisor = 1;
	temp = nb;
	while (temp / 10 != 0)
	{
		divisor *= 10;
		temp /= 10;
	}
	while (divisor != 0)
	{
		ft_putchar('0' + nb / divisor);
		nb %= divisor;
		divisor /= 10;
	}
}