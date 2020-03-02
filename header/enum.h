/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:58 by trifflet          #+#    #+#             */
/*   Updated: 2020/03/02 19:34:29 by trifflet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum		e_event_code
{
	MOUSE_PRESS_CODE = 4,
	MOUSE_MOVE_CODE = 6,
	KEY_PRESS_CODE = 2,
	KEY_RELEASE_CODE = 3,
	RED_BUTTON_CODE = 17,
}					t_event_code;
typedef enum		e_ft_mlx_hooks
{
	NO_EVENT_HOOK = 0,
	MOUSE_PRESS_HOOK = 1,
	MOUSE_MOVE_HOOK = 2,
	KEY_PRESS_HOOK = 4,
	RED_BUTTON_HOOK = 8,
}					t_ft_mlx_hooks;
typedef enum		e_key_code
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	ESCAPE = 53,
	ZOOM_IN = 69,
	ZOOM_OUT = 78,
	SPACE = 49,
	A = 0,
	S = 1,
	D = 2,
	Q = 12,
	W = 13,
	E = 14,
	SHIFT = 56,
	NUM_LOCK_9 = 92,
	NUM_LOCK_8 = 91,
	NUM_LOCK_7 = 89,
	NUM_LOCK_6 = 88,
	NUM_LOCK_5 = 87,
	NUM_LOCK_4 = 86,
	NUM_LOCK_3 = 85,
	NUM_LOCK_2 = 84,
	NUM_LOCK_1 = 83,
	NUM_LOCK_0 = 82,
	RIGHT_ARROW = 124,
	LEFT_ARROW = 123,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
}					t_key_code;

typedef enum		e_infos_mask
{
	INFO_ERROR = 1,
	RESOLUTION = 2,
	NORTH_TEXT = 4,
	SOUTH_TEXT = 8,
	WEST_TEXT = 16,
	EAST_TEXT = 32,
	SPRITE_TEXT = 64,
	FLOOR_COLOR = 128,
	CEILING_COLOR = 256,
	MAP_GET = 512,
}					t_infos_mask;

typedef enum		e_sequence
{
	SEQ_ID = '1',
	SEQ_TEXT = '2',
	SEQ_NUM = '3',
	SEQ_COMMA = '4',
	SEQ_SPACE = '5',
	SEQ_NRSPACE = '6',
}					t_sequence;

#endif
