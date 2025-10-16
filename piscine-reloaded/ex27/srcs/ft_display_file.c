/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 03:16:48 by zernest           #+#    #+#             */
/*   Updated: 2025/10/17 03:38:15 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_err(char c);
void	ft_putstr_err(char *str);

int	main(int ac, char **av)
{
	int		fd;
	char	buf[100];
	int		ret;

	ret = 1;
	if (ac == 1)
		return (ft_putstr_err("File name missing.\n"), 1);
	else if (ac > 2)
		return (ft_putstr_err("Too many arguements.\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_err("Cannot read file.\n");
		return (1);
	}
	while (ret > 0)
	{
		ret = read(fd, buf, 100);
		if (ret > 0)
		{
			buf[ret] = '\0';
			write(1, buf, ret);
		}
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
