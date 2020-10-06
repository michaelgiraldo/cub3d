/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx_event.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:53:45 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 13:02:21 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://tronche.com/gui/x/xlib/events/mask.html
** https://tronche.com/gui/x/xlib/events/types.html
** https://github.com/Adgeff/mlx_keycode/blob/master/mlx_keycode.h
*/

#ifndef CUB3D_MLX_EVENT_H

# define CUB3D_MLX_EVENT_H

/*
** Macros for mlx_hook function
*/

/*
** # define NOEVENTMASK 				0L
** # define KEYPRESSMASK 				1L<<0
** # define KEYRELEASEMASK				1L<<1
** # define BUTTONPRESSMASK				1L<<2
** # define BUTTONRELEASEMASK			1L<<3
** # define ENTERWINDOWMASK				1L<<4
** # define LEAVEWINDOWMASK				1L<<5
** # define POINTERMOTIONMASK			1L<<6
** # define POINTERMOTIONHINTMASK		1L<<7
** # define BUTTON1MOTIONMASK			1L<<8
** # define BUTTON2MOTIONMASK			1L<<9
** # define BUTTON3MOTIONMASK			1L<<10
** # define BUTTON4MOTIONMASK			1L<<11
** # define BUTTON5MOTIONMASK			1L<<12
** # define BUTTONMOTIONMASK			1L<<13
** # define KEYMAPSTATEMASK				1L<<14
** # define EXPOSUREMASK				1L<<15
** # define VISIBILITYCHANGEMASK		1L<<16
** # define STRUCTURENOTIFYMASK			1L<<17
** # define RESIZEREDIRECTMASK			1L<<18
** # define SUBSTRUCTURENOTIFYMASK		1L<<19
** # define SUBSTRUCTUREREDIRECTMASK	1L<<20
** # define FOCUSCHANGEMASK 			1L<<21
** # define PROPERTYCHANGEMASK			1L<<22
** # define COLORMAPCHANGEMASK			1L<<23
** # define OWNERGRABBUTTONMASK			1L<<24
*/

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24

#endif
