void  hook(void *param)
{
  mlx_t *mlx;

  mlx = param;
  if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
    mlx_close_window(param);
  if (mlx_is_key_down(param, MLX_KEY_UP))
    g_img->instances[0].
