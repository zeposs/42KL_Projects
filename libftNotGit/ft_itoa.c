/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:13:49 by zernest           #+#    #+#             */
/*   Updated: 2024/06/12 23:26:35 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	alloc_len(long nbr);
static char	*space_for_result(int len);

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;
	int		alloc;
	char	*result;

	nbr = n;
	alloc = alloc_len(nbr);
	result = space_for_result(alloc);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = nbr * -1;
	i = alloc - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + '0');
        nbr = nbr / 10;
        i--;
	}
	if (n < 0)
		result[0] = '-';
	result[alloc] = 0;
	return (result);
}

static int	alloc_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -1 * nbr;
	}
    if (nbr == 0)
        count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char	*space_for_result(int len)
{
	char	*mem;

	mem = malloc((len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	mem[0] = '0';
	return (mem);
}

/* #include <stdio.h>
int	main(void)
{
	char *ret;
	ret = ft_itoa(-3152);
	printf("%s", ret);
} */