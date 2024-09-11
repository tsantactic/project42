/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:20 by sandriam          #+#    #+#             */
/*   Updated: 2024/06/03 16:11:57 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

int	ft_printf(const char *arg, ...);
int	ft_printf_dec(int nbr);
int	ft_printf_str(const char *c);
int	ft_printf_hex(unsigned int num, const char format);
int	ft_printf_unsigned(unsigned int nbr);
int	ft_printf_percent(void);
int	ft_printf_ptr(unsigned long long ptr);

#endif
