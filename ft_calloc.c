/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:13:00 by srapin            #+#    #+#             */
/*   Updated: 2022/11/12 23:33:58 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*cal;

	total_size = nmemb * size;
	if (nmemb > total_size || size > total_size)
		return (NULL);
	cal = malloc(total_size);
	if (!cal)
		return (NULL);
	ft_bzero(cal, total_size);
	return (cal);
}
