#include "fractol.h"
#include <stdio.h>

int handle_keypress(int keycode)
{
    // キーボード入力を処理
    printf("Key pressed: %d\n", keycode);
    return 0;
}

int handle_buttonpress(int button, int x, int y)
{
    // マウスボタン入力を処理
    printf("Button %d pressed at (%d,%d)\n", button, x, y);
    return 0;
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Event Handling Example");

    // キーとマウスボタンのイベントを設定
    mlx_hook(win_ptr, 2, 1L<<0, handle_keypress, NULL);  // キープレスイベント
    mlx_hook(win_ptr, 4, 1L<<2, handle_buttonpress, NULL); // ボタンプレスイベント

    mlx_loop(mlx_ptr);
    return 0;
}
