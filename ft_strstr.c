/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:17:38 by srapin            #+#    #+#             */
/*   Updated: 2022/11/17 18:18:40 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strstr(char *str, char *to_find, int len)
{
        int     i;

        i = -1;
        if (!*to_find)
                return (-1);
        while (str[++i])
                if (ft_strncmp(str + i, to_find, len) == 0)
                        return (i);
        return (-1);
}
