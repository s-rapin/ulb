/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:10:45 by srapin            #+#    #+#             */
/*   Updated: 2022/11/17 14:22:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	print_c(void *elem)
{
	//add option
	write(1, (char *) elem, get_lenght_c(elem));
}

void	print_s(void *elem)
{
	//add ption
	write(1, (char *) elem, get_lenght_c(elem));
}

void	print_p(void *elem)
{
	ft_putnbrbase(elem, "0123456789abcdef");
}

void	print_d();
void	print_i();
void	print_u();
void	print_xmin();
void	print_xmaj();
void	print_m();



int		get_lenght_c(void *elem)
{
	return (1);
}

int		get_lenght_s();
int		get_lenght_p();
int		get_lenght_d();
int		get_lenght_i();
int		get_lenght_u();
int		get_lenght_xmin();
int		get_lenght_xmaj();
int		get_lenght_m();