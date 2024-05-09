/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:42:34 by zernest           #+#    #+#             */
/*   Updated: 2024/05/09 17:35:42 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int a;

    a = 0;
    while ((a < n) && (s1[a] != '\0') && (s2[a] != '\0') && (s1[a] == s2[a]))
    {
        a++;
    }
    if (a == n)
        return (0);
    else
        return (s1[a] - s2[a]);    
}
