#include "wolf3d.h"


/*
**	SPRINT (SHIFT) key move
*/

void 	key_sprint(t_e *e)
{
	e->rotSpeed = 0.06;
	e->moveSpeed = 0.06;
}


/*
**	DOUBLE SPRINT (2 SHIFT keys striked)
*/

void 	key_sprint_double(t_e *e)
{
	e->rotSpeed = 0.12;
	e->moveSpeed = 0.12;
}

/*
**	Strike : when a key is pushed, status of the key is 1.
*/


int 	strike(int keycode, t_e *e)
{
	ft_putstr("hit");
	if (keycode == 65307) // Echap
		exit(0);
	if (keycode == 122)
		e->tap_up = 1;
	if (keycode == 115)
		e->tap_down = 1;
	if (keycode == 113)
		e->tap_left = 1;
	if (keycode == 100)
		e->tap_right = 1;
	if (keycode == 65505) // shift
		e->tap_sprint = 1;
	if (keycode == 105) // i
		e->tap_reinit = 1;
	if (keycode == 65506) // shift 2
		e->tap_sprint_double = 1;
	//printf("keycode : %d", keycode);
	return (0);
}

/*
**	Release : when a key is released, status of the key is 0.
*/

int 	release(int keycode, t_e *e)
{
	//ft_putstr("release");
	if (keycode == 122)
		e->tap_up = 0;
	if (keycode == 115)
		e->tap_down = 0;
	if (keycode == 113)
		e->tap_left = 0;
	if (keycode == 100)
		e->tap_right = 0;
	if (keycode == 65505) // shift
		e->tap_sprint = 0;
	if (keycode == 105) 
		e->tap_reinit = 0;
	if (keycode == 65506) // shift 2
		e->tap_sprint_double = 0;
	return (0);
}
