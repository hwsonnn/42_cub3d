/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:24:18 by sonheewon         #+#    #+#             */
/*   Updated: 2021/01/09 21:03:10 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# pragma pack(push, 1)

typedef struct		s_bmp_file_h
{
	unsigned char	magic1;
	unsigned char	magic2;
	unsigned int	size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	offset;
}					t_bmp_file_h;

typedef struct		s_bmp_info_h
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	plane;
	unsigned short	bit_per_pixel;
	unsigned int	compression;
	unsigned int	size_image;
	unsigned int	resolution_x;
	unsigned int	resolution_y;
	unsigned int	color_used;
	unsigned int	color_important;
}					t_bmp_info_h;

typedef struct		s_bmp_h
{
	t_bmp_file_h	file_h;
	t_bmp_info_h	info_h;
}					t_bmp_h;

# pragma pack(pop)

#endif
