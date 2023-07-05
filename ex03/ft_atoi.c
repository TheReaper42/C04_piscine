/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzolotuk <dzolotuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:29:31 by dzolotuk          #+#    #+#             */
/*   Updated: 2023/07/05 14:56:42 by dzolotuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char str)
{
	int		result;
	int		i;

	result = 0;
	if ((str >= 'A' && str <= 'Z') && (str >= 'a' && str <= 'z'))
	{
		result = 1;
	}
	return (result);
}

int	ft_str_is_numeric(char str)
{
	int		result;

	result = 0;
	if (str >= '0' && str <= '9')
	{
		result = 1;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	multiplier;
	int final;
	int result;
	int	i;
	int	minus;
	int	temp;

	multiplier = 1;
	minus = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			minus++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_numeric(str[i]))
			multiplier = multiplier * 10;
		else if (ft_str_is_alpha(str[i]))
			break ;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_numeric(str[i]))
		{
			temp = str[i] - '0';
			result = result + (multiplier * temp);
		}
		else if (ft_str_is_alpha(str[i]))
			break ;
		i++;
	}

	if (minus % 2 == 0)
	{
		result = result * -1;
	}

	return (result);
}

int	main(void)
{
	char str[] = "---123";
	int val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);
}