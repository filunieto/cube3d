/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:44:14 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 12:31:40 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# define INITIAL_WIDTH 1920
# define INITIAL_HEIGHT 1080
//# include "../memory-leaks/include/memory_leaks.h"
# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "shapes/Shapes.h"
# include "player/Player.h"
# include "game/Game.h"
# include "map/Map.h"

/******************** FElipe *******************/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>


# include "error/Error.h"
# include "parse/Parse.h"
# include "gnl/get_next_line.h"



int	init_window(void);

#endif
