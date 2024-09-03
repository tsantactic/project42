/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:45 by sandriam          #+#    #+#             */
/*   Updated: 2024/03/09 13:14:31 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	if (nmemb && size && (nmemb > (2147483648 / size)))
		return (0);
	dst = malloc(size * nmemb);
	if (!dst)
		return (0);
	ft_bzero(dst, size * nmemb);
	return (dst);
}
