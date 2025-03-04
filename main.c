/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:56 by seerel            #+#    #+#             */
/*   Updated: 2025/03/04 17:44:14 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void render_map(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            // Öncelikle floor görselini yerleştiriyoruz
            mlx_put_image_to_window(game->mlx, game->win, game->floor_img,x * 64, y * 64);

            // Eğer bu karede bir coin varsa, coin görselini yerleştiriyoruz
            if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x * 64, y * 64);

            // Diğer öğeler yerleştirildi, sıra karakterin görseline geldi
            // Karakterin konumunu burada kontrol ediyoruz
            if (game->character_x == x && game->character_y == y)
                mlx_put_image_to_window(game->mlx, game->win, game->character_img, x * 64, y * 64);

            x++;
        }
        y++;
    }
}
int main()
{
    t_game game;
    int img_width, img_height;

    game.mlx = mlx_init();
    if (!game.mlx)
    {
        printf("MLX başlatılamadı!\n");
        return (1);
    }

    game.win = mlx_new_window(game.mlx, 6*64,6*64,"so_long");
    if (!game.win)
    {
        printf("Pencere açılamadı!\n");
        return (1);
    }

    // Görsellerin yüklenmesi
    game.floor_img = mlx_xpm_file_to_image(game.mlx, "floor.xpm", &img_width, &img_height);
    game.coin_img = mlx_xpm_file_to_image(game.mlx, "coin.xpm", &img_width, &img_height);  // Coin görseli
    game.character_img = mlx_xpm_file_to_image(game.mlx, "player.xpm", &img_width, &img_height); // Karakter görseli
    if (!game.floor_img || !game.coin_img || !game.character_img)
    {
        printf("Görseller yüklenemedi!\n");
        return (1);
    }

    // Harita ve karakterin başlangıç konumu
    char *map_data[] = {
        "111111",
        "1C0011",
        "10C011",
        "100011",
        "100C11"
        "111111"
    };
    game.map = map_data;
    game.map_width = 5;
    game.map_height = 5;
    game.character_x = 1;  // Başlangıçta karakterin X koordinatı
    game.character_y = 1;  // Başlangıçta karakterin Y koordinatı

    render_map(&game);  // Haritayı render et

    mlx_loop(game.mlx);  // MLX döngüsü

    return (0);
}
