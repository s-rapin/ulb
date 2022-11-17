/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:58:27 by srapin            #+#    #+#             */
/*   Updated: 2022/11/17 22:52:05 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putnbr_base(unsigned long nbr, char *base, t_print *to_print)
{
        int		base_size;

        base_size = ft_strlen(base);
		to_print->arg_len = 1;
        if (nbr >= base_size)
            ft_putnbr_base(nbr / base_size, base, to_print);
		write_and_count(&base[nbr%base_size], to_print);
}