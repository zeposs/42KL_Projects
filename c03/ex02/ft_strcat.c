/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:42:19 by zernest           #+#    #+#             */
/*   Updated: 2024/05/09 18:58:15 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }

    while (src[j] != '\0')
    {
        dest[i] = src [j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

/* int main(void)
{
    char    dest[] = "hello";
    char    src[] =  "world";

    ft_strcat(dest, src);
    write (1, dest, 50);
} */
