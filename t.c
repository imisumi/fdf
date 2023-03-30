#include <mlx.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct    s_vec3 {
    float    x;
    float    y;
    float    z;
}                t_vec3;

void draw_line(void mlx, voidwin, t_vec3 p1, t_vec3 p2)
{
    mlx_pixel_put(mlx, win, p1.x, p1.y, 0xFFFFFF);
    mlx_pixel_put(mlx, win, p2.x, p2.y, 0xFFFFFF);
}

void draw_cube(void mlx, voidwin)
{
    t_vec3 vertices[8] = {
        {-1, -1, -1}, {1, -1, -1}, {-1, 1, -1}, {1, 1, -1},
        {-1, -1, 1}, {1, -1, 1}, {-1, 1, 1}, {1, 1, 1}
    };
    int edges[12][2] = {
        {0, 1}, {0, 2}, {0, 4}, {1, 3}, {1, 5}, {2, 3},
        {2, 6}, {3, 7}, {4, 5}, {4, 6}, {5, 7}, {6, 7}
    };
    int i;
    for (i = 0; i < 12; i++) {
        int v1 = edges[i][0];
        int v2 = edges[i][1];
        t_vec3 p1 = vertices[v1];
        t_vec3 p2 = vertices[v2];
        draw_line(mlx, win, p1, p2);
    }
}

int main(void)
{
    void mlx;
    voidwin;
    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Cube");
    draw_cube(mlx, win);
    mlx_loop(mlx);
    return 0;
}