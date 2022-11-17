/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:36:40 by srapin            #+#    #+#             */
/*   Updated: 2022/11/17 23:43:27 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_count_nbr_len(unsigned long ui, int base_size)
{
	int count;
	
	count = 0;
	while(count / base_size)
	{
		count/=base_size;
		count++;
	}
	return count;
}

void write_and_count(char *str, t_print *to_print)
{
	to_print->counter += write(1, str, to_print->arg_len);
}

void ft_print_mod(t_print *to_print)
{
	to_print->arg_len = 1;
	write_and_count("%", to_print);
}

void ft_print_char(t_print *to_print, char c)
{
	to_print->arg_len = 1;
	write_and_count(&c, to_print);
}

void ft_print_str(t_print *to_print, char *str)
{
	to_print->arg_len= ft_strlen(str);
	write_and_count(str, to_print);
}

void ft_print_int(t_print *to_print, int i)
{
	if (i < 0)
	{
		write_and_count("-", to_print);
		ft_putnbr_base(-i, "0123456789", to_print);
	}
	else
		ft_putnbr_base(i, "0123456789", to_print);
	to_print->arg_len = ft_count_nbr_len(i, 10);
}

void ft_print_hex(t_print *to_print, unsigned int ui, int maj)
{
	//to_print->arg_len= ft_count_int_len(i, 10);
	if (maj)
		ft_putnbr_base(ui, "0123456789ABCDEF", to_print);
	else 
		ft_putnbr_base(ui, "0123456789abcdef", to_print);
}

void ft_print_unsigned(t_print *to_print, unsigned int i)
{	
	//to_print->arg_len= ft_count_int_len(i, 10);
	ft_putnbr_base(i, "0123456789", to_print);
}

void ft_print_ptr(t_print *to_print, unsigned long i)
{	
	to_print->arg_len= 2;
	write_and_count("0x", to_print);
	ft_putnbr_base(i, "0123456789abcdef", to_print);
}
/*
/*
t_elem	initialize_elem(enum e_type t, void *to_print)
{
	t_elem	e;
	int		i;

	e.type = t;
	e.to_print = to_print;
	i = 0;
	while (i++ < 6)
		e->option = -1;
	// if option ->setoption
	if (e->)
	return e;
}

int	print_elem(char *str, void *to_print)
{
	initalize_elem(ft_strstr(find_type, str[0]), to_print);
	return(1);
}
*/
void	ft_reset_struct(t_print *to_print)
{
	ft_bzero(to_print, sizeof(t_print) - sizeof(to_print->counter));
	to_print->arg_len = 1;
}

void	ft_print_arg(t_print *to_print, va_list args)  //to_adapt 
{

	if (to_print->type == '%')
		ft_print_mod(to_print);
	else if (to_print->type == 'c')
		ft_print_char(to_print, va_arg(args, int));
	else if (to_print->type == 's')
		ft_print_str(to_print, va_arg(args, char *));
	else if (to_print->type == 'd' || to_print->type == 'i')
		ft_print_int(to_print, va_arg(args,int));
	else if (to_print->type == 'x')
		ft_print_hex(to_print, va_arg(args, unsigned int), 0);
	else if (to_print->type == 'X')
		ft_print_hex(to_print, va_arg(args, unsigned int), 1);
	else if (to_print->type == 'u')
		ft_print_unsigned(to_print, va_arg(args, unsigned int));
	else if (to_print->type == 'p')
		ft_print_ptr(to_print, (unsigned long)va_arg(args, void *));
	ft_reset_struct(to_print);
}

char	*set_option(t_print *to_print,char * format)
{
	int next;

	next = ft_strstr(format_symbol, format, 1);
	while(next >= 0)
	{
		if (next < 9)
			break;
			
		next = ft_strstr(format_symbol, format, 1);
	}
	return format
}

/*
void ft_printf(const char *str, ...)
{
	s_elem		*next_arg;
	int			i = 0;
	int			lenght = 0;

	while(str[i])
	{
		lenght = 0;
		while (str[i] != %)
			lenght++;
		write(1, (char*) str + i,lenght);
		i += print_elem((char *)str + i + 1, va_arg(arg_ptr, void *));
	}
	va_end(str);
}
*/

char *parse_format(char *format, t_print *to_print, va_list test)
{
	int		next_char;
	
	format++;
	next_char = ft_strstr(format_symbol, format, 1);
	if (next_char < 0)
		return format;
	format = set_option(to_print, format);
	
	next_char = ft_strstr(format_symbol, format, 1);
	if (next_char < 9)
	{
		to_print->type = types_symbol[next_char];
		//check_option(to_print);
		ft_print_arg(to_print, test);
	}
	return format;
}

int ft_printf ( const char * format, ... )
{
	t_print		to_print;
	int			size;
	char *str = (char *)format; //trv une meilleur man.iere
	va_list args;

	if (!str || str[0] == '\0')
		return 0;
	va_start(args, format);
	ft_reset_struct(&to_print);
    while (str && *str)
    {
        if (str[0] == '%')
			str = parse_format(str, &to_print, args);
		else if (str && *str)
			write_and_count(str, &to_print);
		str++;
    }
	write_and_count(str, &to_print);
	va_end(args);
    return to_print.counter;
}

int main()
{
    char *c = "\ntest c: ,%c,\ntest i: ,%i,\ntest s: ,%s,\ntest X: ,%x,\ntest u: ,%u,\ntest p: ,%p,\n\n";
	char *c2 = "youhou";
	int j= -50987;
	int k = 16;
	int l = 10;
    int i = ft_printf(c, 'U', j, c2, k, l, &j);
	printf(c, 'U', j, c2, k, l, &j, j);
    printf("res = %d", i);
}
