/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:22:06 by zernest           #+#    #+#             */
/*   Updated: 2024/05/14 19:38:34 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_sqrt(int nb)
{
    int i;
    int x;

    i = 1;

    while (i < nb)
    {
        x = i * i;
        if (x == nb)
        {
            return (i);
        }
        else
            i++;
    }
    return (0);
}

#include <stdio.h>
int main(void)
{
    int a;
    a = ft_sqrt(81);
    printf("%d\n", a);
}