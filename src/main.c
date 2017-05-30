#include "wolf3d.h"

int 	key_pressed(int keycode, t_env env)
{
	if (keycode == 53) // quit
		exit(0);
	if (keycode == 126) // up
	{
		printf("Zoom In");
		env.zoom = env.zoom * 1.5;
	}
	if (keycode == 125) // down
	{
		printf("Zoom Out");
		env.zoom = env.zoom * 0.75;
	}
	// mlx_clear_window(env.mlx, env.win);
	// draw(env);
	return (0);
}

void 	ft_map(t_env env)
{
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1000, 1000, "Fractol");
	mlx_key_hook(env.win, key_pressed, NULL);
	mlx_loop(env.mlx);
}

t_env	init_map(t_env env)
{
	env.x1 = -2.1;
	env.x2 = 2.6;
	env.y1 = -1.2;
	env.y2 = 1.2;
	env.itmax = 50;
	env.zoom = 100;
	env.img_x = (env.x2 - env.x1) * env.zoom;
	env.img_y = (env.y2 - env.y1) * env.zoom;
	return (env);
}

int 	main ()
{
	t_env env;

	init_map(&env);
	ft_map(env);
	return (0);
}