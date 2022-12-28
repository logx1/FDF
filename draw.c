#include "test.h"

float maxx(float x, float y)
{
    if (x > y)
    {
        return (x);
    }
    return (y);
}
float abss(float x)
{
    if (x >= 0)
    {
        return (x);
    }
    return (-x);
}
void draw(void *mlx_ptr, void *win_ptr, float x0,float y0,float x1,float y1, int color)
{
    float x_styp;
    float y_styp;

    x_styp = x1 - x0;
    y_styp = y1 - y0;

    x_styp /= maxx(abss(x_styp),abss(y_styp));
    y_styp /= maxx(abss(x_styp),abss(y_styp));
    while ((int)(x0 - x1) || (int)(y0 - y1))
    {
        mlx_pixel_put(mlx_ptr, win_ptr,x0,y0, color);
        x0 += x_styp;
        y0 += y_styp;
    }
    
}


// int main(void)
// {
//     void *mlx_ptr;
//     void *win_ptr;
   
    
//     mlx_ptr =mlx_init();
//      win_ptr = mlx_new_window(mlx_ptr, 500, 500 , "test");

//    draw0(mlx_ptr,win_ptr,50,50,40,400);
        
    
    
//      mlx_loop(mlx_ptr);
//     return (0);
       
// }
