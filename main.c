#include "so_long.h"

int main()
{
    void *mlx;
    void *win;
    void *img;
    int img_width, img_height;

    // MLX başlat
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Pencere oluştur
    win = mlx_new_window(mlx, 1800, 1600, "selam");
   

    // Görüntüyü yükle (Örneğin "image.xpm" adlı bir dosyan varsa)
    img = mlx_xpm_file_to_image(mlx, "imagine.xpm", &img_width, &img_height);
    if (!img)
        return (1);

    // Görüntüyü pencereye koy
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    sleep(300);
    // MLX döngüsünü başlat
    mlx_loop(mlx);

    return (0);
}
