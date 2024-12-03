/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderChar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:16 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:40:17 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_data *data, int c)
{
	int	width;

	width = data->flags.width;
	if (width > 1)
	{
		if (data->flags.left_justified)
		{
			putchar_buff_n((char)c, 1, data);
			putchar_buff_n(' ', width - 1, data);
		}
		else
		{
			putchar_buff_n(' ', width - 1, data);
			putchar_buff_n((char)c, 1, data);
		}
	}
	else
		putchar_buff_n((char)c, 1, data);
}
