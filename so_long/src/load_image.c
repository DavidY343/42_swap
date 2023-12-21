/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:10:25 by david             #+#    #+#             */
/*   Updated: 2023/12/21 12:28:27 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

static void	init_image_black(t_game *game)
{
	game->img->bfloor = mlx_xpm_file_to_image(game->mlx,
			"media/Bfloor.xpm", &game->img->width, &game->img->height);
	game->img->bwall = mlx_xpm_file_to_image(game->mlx,
			"media/Bwall.xpm", &game->img->width, &game->img->height);
	game->img->bpfront = mlx_xpm_file_to_image(game->mlx,
			"media/BPfront.xpm", &game->img->width, &game->img->height);
	game->img->bpback = mlx_xpm_file_to_image(game->mlx,
			"media/BPback.xpm", &game->img->width, &game->img->height);
	game->img->bpleft = mlx_xpm_file_to_image(game->mlx,
			"media/BPleft.xpm", &game->img->width, &game->img->height);
	game->img->bpright = mlx_xpm_file_to_image(game->mlx,
			"media/BPright.xpm", &game->img->width, &game->img->height);
	game->img->boexit = mlx_xpm_file_to_image(game->mlx,
		"media/BOexit.xpm", &game->img->width, &game->img->height);
	game->img->bpstart = mlx_xpm_file_to_image(game->mlx,
		"media/BPfront.xpm", &game->img->width, &game->img->height);
}

static void	init_image_coin(t_game *game)
{
	game->img->coin = mlx_xpm_file_to_image(game->mlx,
			"media/coin1.xpm", &game->img->width, &game->img->height);
	game->img->coin1 = mlx_xpm_file_to_image(game->mlx,
			"media/coin1.xpm", &game->img->width, &game->img->height);
	game->img->coin2 = mlx_xpm_file_to_image(game->mlx,
			"media/coin2.xpm", &game->img->width, &game->img->height);
	game->img->coin3 = mlx_xpm_file_to_image(game->mlx,
			"media/coin3.xpm", &game->img->width, &game->img->height);
	game->img->coin4 = mlx_xpm_file_to_image(game->mlx,
			"media/coin4.xpm", &game->img->width, &game->img->height);
	game->img->coin5 = mlx_xpm_file_to_image(game->mlx,
			"media/coin5.xpm", &game->img->width, &game->img->height);
	game->img->coin6 = mlx_xpm_file_to_image(game->mlx,
			"media/coin6.xpm", &game->img->width, &game->img->height);
	game->img->coin7 = mlx_xpm_file_to_image(game->mlx,
			"media/coin7.xpm", &game->img->width, &game->img->height);
	game->img->coin8 = mlx_xpm_file_to_image(game->mlx,
			"media/coin8.xpm", &game->img->width, &game->img->height);
}
void	init_image(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	game->img->wfloor = mlx_xpm_file_to_image(game->mlx,
			"media/Wfloor.xpm", &game->img->width, &game->img->height);
	game->img->wwall = mlx_xpm_file_to_image(game->mlx,
			"media/Wwall.xpm", &game->img->width, &game->img->height);
	game->img->pfront = mlx_xpm_file_to_image(game->mlx,
			"media/Pfront.xpm", &game->img->width, &game->img->height);
	game->img->pback = mlx_xpm_file_to_image(game->mlx,
			"media/Pback.xpm", &game->img->width, &game->img->height);
	game->img->pleft = mlx_xpm_file_to_image(game->mlx,
			"media/Pleft.xpm", &game->img->width, &game->img->height);
	game->img->pright = mlx_xpm_file_to_image(game->mlx,
			"media/Pright.xpm", &game->img->width, &game->img->height);
	game->img->cexit = mlx_xpm_file_to_image(game->mlx,
			"media/Cexit.xpm", &game->img->width, &game->img->height);
	game->img->oexit = mlx_xpm_file_to_image(game->mlx,
			"media/Oexit.xpm", &game->img->width, &game->img->height);
	game->img->pstart = mlx_xpm_file_to_image(game->mlx,
			"media/Pfront.xpm", &game->img->width, &game->img->height);
	init_image_black(game);
	init_image_coin(game);
}

