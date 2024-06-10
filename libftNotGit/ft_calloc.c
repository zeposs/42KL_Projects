/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:26:45 by zernest           #+#    #+#             */
/*   Updated: 2024/06/10 17:45:12 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	size_product;
	void	*ptr;

	if (nmemb <= 0 || size <= 0)
		return (NULL);
	size_product = nmemb * size;
	ptr = malloc(size_product);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size_product);
	return (ptr);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	int		*int_ptr;
	int		i;

	int_ptr = (int *)ft_calloc(5, sizeof(int));
	if (int_ptr == NULL)
	{
		printf("Allocation failed for 5 integers.\n");
	}
	else
	{
		i = 0;
		while (i < 5)
		{
			if (int_ptr[i] != 0)
			{
				printf("Memory not properly initialized at index %d.\n", i);
				break ;
			}
			i++;
		}
		printf("Memory allocated and initialized successfully for 5 integers.\n");
	return (0);
    }
} */
