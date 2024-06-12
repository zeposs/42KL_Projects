/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:39:16 by zernest           #+#    #+#             */
/*   Updated: 2024/06/10 18:11:21 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

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

/* #include <stdio.h>
int main()
{
    char *s1 = "232";
    char *s2 = "221";
    int res;
    res = ft_strncmp(s1, s2, 20);
    printf("%d", res);
} */