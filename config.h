#include <X11/XF86keysym.h>

// Shell
char shell[] = "/bin/sh";

#define Super Mod4Mask

enum {
	Audio,
	Brightness,
	Notify,

	// Declare modes above this
	MODE_SIZE,
};

// Define mode key bindings here
// NOTE: "10" here is the maximum number of key bindings for each mode
Key modes[MODE_SIZE][10] = {
	[Audio] = {
		{ 0, XK_F6,	cmd("amixer set Master toggle") },
		{ 0, XK_F7,	cmd("amixer set Master 1%-") },
		{ 0, XK_F8,	cmd("amixer set Master 1%+") },
	},
	[Brightness] = {
		{ 0, XK_F2,	cmd("doas brightnessztl set -2") },
		{ 0, XK_F3,	cmd("doas brightnessztl set +2") },
	},
	[Notify] = {
		{ 0,	XK_t,		cmd("time.sh") },
	},
};

// Define normal mode key bindings here
Key keys[] = {
	{ Super,  	XK_d,             		cmd("dmenu_run") },
	{ Super,  	XK_e,             		cmd("emacs") },
	{ Super,  	XK_w,             		cmd("firefox") },
	{ Super,  	XK_Return,			cmd("st") },
	{ 0,		XF86XK_MonBrightnessUp,		cmd("doas brightnessztl set +2") },
	{ 0,		XF86XK_MonBrightnessUp,		mode(Brightness, True) },
	{ 0,		XF86XK_MonBrightnessDown,	cmd("doas brightnessztl set -2") },
	{ 0,		XF86XK_MonBrightnessDown,	mode(Brightness, True) },
	{ Super,	XK_n,				mode(Notify,	False) },
};

ModeProperties mode_properties[MODE_SIZE] = {
	[Audio] = { "Audio" },
	[Brightness]	= { "Brightness control" },
	[Notify]	= { "Notifications"},
};

// Call this script on mode change
char* on_mode_change = "notify-send \" [$SHOTKEY_MODE_ID] $SHOTKEY_MODE_LABEL\"";

