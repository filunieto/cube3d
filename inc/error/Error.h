/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:08 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/24 00:07:10 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "../Screen.h"

/* Error messages */
#define ERR_MS "Error\n"

#define ERRNBINP_MES	"wrong number of inputs\n"
#define ERR_TEXT_INP_MES	"more than 2 arguments in texture line\n"
#define ERR_COLOR_INP_MES	"more than 2 arguments in colour line\n"
#define ERR_COLOR_INP2_MES	"more than 3 values for RGB definition \n"
#define ERR_COLOR_INP3_MES	"RGB values not integers or not in range [0-255] \n"
#define ERR_COLOR_INP4_MES	"RGB values are equal for colours of heaven and ground \n"
#define ERR_TEXT_PATH_MES	"impossible to open the path to texture\n"
#define ERR_REPET_NO	"cardinal North repited\n"
#define ERR_REPET_SO	"cardinal South repited\n"
#define ERR_REPET_EA	"cardinal East repited\n"
#define ERR_REPET_WE	"cardinal West repited\n"
#define ERR_REPET_F		"heaven argument repited\n"
#define ERR_REPET_G		"ground argument repited\n"

#define ERR_MAP0_MES	"map with less than 3 lines. there is no possibility to place the player\n"
#define ERR_MAP1_MES	"chars in map differents from 0,1, W, S, E, N\n"
#define ERR_MAP2_MES	"map not closed by 1\n"
#define ERR_MAP3_MES	"upper line from map not closed\n"
#define ERR_MAP4_MES	"bottom line from map not closed\n"
#define ERR_MAP5_MES	"left line from map not closed\n"
#define ERR_MAP6_MES	"right line from map not closed\n"
#define ERR_MAP8_MES	"no player\n"
#define ERR_MAP9_MES	"more than 1 player\n"
#define ERR_MAP10_MES	"map not at the end\n"
#define ERR_MALLO_MES	"error malloc\n"
#define ERR_EXT_MES		"file extension not .cub\n"

#define ERR_OPEN_FILE		"Problem opening file 1\n"
#define ERR_OPEN_FILE2		"Problem opening file 2\n"
#define ERR_INP_MAP_MES		"repetdio punto cardinal o falta o el mapa no tiene simbolos correctos\n"



#define USAGE	"Please provide correct format \
<./cube3d> <file>'\n"

#define ERR_MAP_INPT_MES	"The input map , has a problem \
as above message indicates'\n"

/* Error codes return values */

enum	code_error //podemos usarlo?
{
	ERRNBINP = 10,
	ERR_MAP_INPT,
	ERR_TEXT_INP,
	ERR_INP_MAP,
	ERR_TEXT_PATH,
	ERR_COLOR_INP,
	ERR_COLOR_INP2,
	ERR_COLOR_INP3,
	ERR_COLOR_INP4,
	ERR_MAP0,
	ERR_MAP1,
	ERR_MAP2,
	ERR_MAP3,
	ERR_MAP4,
	ERR_MAP5,
	ERR_MAP6,
	ERR_MAP7,
	ERR_MAP8,
	ERR_MAP9,
	ERR_MAP10,
	ERR_MALLO,
	ERR_OPEN_FD,
	ERR_EXT,
	DRAFT,

};




#endif