/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:49:50 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/03 03:04:49 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putnbr_base(long long int n, int base, char *formato, int *count);
void	ft_putnbr_base_unsigned(unsigned long long int n, int base,
			char *formato, int *count);
int		ft_strlen(const char *s);
int		ft_printf(char const *format, ...);
#endif
