#ifndef __SSYSTEMMESSAGE_H__
#define __SSYSTEMMESSAGE_H__

#include "../types.h"

typedef enum EMessageType
{
	SM_DEFAULT,

	SM_QUIT,

	SM_WINDOW_CREATE,
	SM_WINDOW_RESIZE,
	SM_WINDOW_MINIMIZE,
	SM_WINDOW_MAXIMIZE,
	SM_WINDOW_FOCUS_GAINED,
	SM_WINDOW_FOCUS_LOST,
	SM_WINDOW_DESTROY,

	SM_KEYDOWN,
	SM_KEYUP,

	SM_MOUSE_MOVE,
	SM_MOUSEDOWN,
	SM_MOUSEUP,
	SM_MOUSEWHEEL

} EMessageType;

typedef struct SWindowMessage
{
	s32 data1;
	s32 data2;
} SWindowMessage;

typedef struct SKeyboardMessage
{
	u32 keycode;
} SKeyboardMessage;

typedef struct SMouseMoveMessage
{
	s32 x;           /**< X coordinate, relative to window */
	s32 y;           /**< Y coordinate, relative to window */
} SMouseMoveMessage;

typedef struct SMouseButtonMessage
{
	u8 button;       /**< The mouse button index */
	s32 x;           /**< X coordinate, relative to window */
	s32 y;           /**< Y coordinate, relative to window */
} SMouseButtonMessage;

typedef struct SMouseWheelMessage
{
	s32 x;           /**< The amount scrolled horizontally */
	s32 y;           /**< The amount scrolled vertically */
} SMouseWheelMessage;

typedef struct SSystemMessage
{
	EMessageType type;
	u32 timestamp;
	u32 windowID;
	union
	{
		SWindowMessage window;
		SKeyboardMessage key;
		SMouseMoveMessage mouseMove;
		SMouseButtonMessage mouseButton;
		SMouseWheelMessage mouseWheel;
		s8 padding[12];
	};
} SSystemMessage;

#endif // !__SSYSTEMMESSAGE_H__
