/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:40:46 by srapin            #+#    #+#             */
/*   Updated: 2022/11/17 23:32:43 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define	FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lift/libft.h"
# define types_symbol "cspdiuxX%"
# define options_symbol "-0.# +123456789"
# define format_symbol "cspdiuxX%-0.# +123456789"
# define hexa_base "0123456789abcdef", "0123456789ABCDEF"
enum	e_option
{
	minus,
	zero,
	point,
	hashtag,
	space,
	plus,
	width,
	precision
};



typedef struct	s_print
{
	char		type;
	int			option[8];
	int			arg_len;
	int			counter;
}	t_print;

void write_and_count(char *, t_print *);
void    ft_putnbr_base(unsigned long nbr, char *base, t_print *to_print);
#endif