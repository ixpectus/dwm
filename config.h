/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { 
  "MesloLGS Nerd Font:style=Regular:pixelsize=33:antialias=true:autohint=true",
  "EmojiOne:style=Regular:pixelsize=33:antialias=true:autohint=true",
};

// static const char *fonts[]          = {  
//   "MesloLGS Nerd Font:style=Regular:pixelsize=33:antialias=true:autohint=true", 
//   "EmojiOne:style=Regular:pixelsize=33:antialias=true:autohint=true",
// }; 
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#073642";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance    title       tags mask     isfloating   monitor */
	{ "TelegramDesktop",     NULL,       NULL,       1 << 2,            0,           0 },
	{ "firefox",             NULL,       NULL,       1 << 3,       0,           0 },
	{ "Slack",               NULL,       NULL,       1 << 6,       0,           0 },
	{ "Slack",               NULL,       NULL,       1 << 6,       0,           0 },
	{ "Element",     NULL,       NULL,       1 << 6,       0,           0 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/ixpectus/scripts/dmenu/run", NULL };
static const char *tmuxnewwindow[] = { "tmux new-window", NULL };
static const char *termcmd[]  = { "st", "-e", "tmux", NULL};
static const char *lock[]  = { "i3lock", "-e", "-f", "-c", "1d2021", NULL};
static const char *flatmenucmd[]  = { "/home/ixpectus/scripts/dmenu/flat.sh", NULL };
static const char *vpncmd[]  = { "/home/ixpectus/scripts/vpnAvito", NULL };
static const char *forceedpi[]  = { "/home/ixpectus/scripts/forceEdpi", NULL };
static const char *scrot[]  = { "/home/ixpectus/scripts/scrot_dmenu", NULL };
static const char *kp[]  = { "/home/ixpectus/scripts/dmenu/kp", NULL };
static const char *calc[]  = { "/home/ixpectus/scripts/dmenu/calc", NULL };
static const char *openmarks[]  = { "/home/ixpectus/scripts/dmenu/dmarksShort", "/home/ixpectus/projects/tasks/marks", NULL };
static const char *ctrlt[]  = { "xdotool", "getactivewindow", "key", "ctrl+t",  NULL };
static const char *ctrlw[]  = { "xdotool", "getactivewindow", "key", "ctrl+w",  NULL };
static const char *ctrla[]  = { "xdotool", "getactivewindow", "key", "ctrl+a",  NULL };
static const char *ctrlc[]  = { "xdotool", "getactivewindow", "key", "ctrl+c",  NULL };
static const char *ctrlv[]  = { "xdotool", "getactivewindow", "key", "ctrl+v",  NULL };



static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_k,      spawn,          {.v = kp } }, //ctrl+shift+k
	{ MODKEY|ShiftMask,             XK_o,      spawn,          {.v = openmarks } },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = lock } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },


	{ ControlMask|ShiftMask,             XK_k,      spawn,          {.v = kp } }, //ctrl+shift+k
	{ ControlMask|ShiftMask,             XK_m,      spawn,          {.v = openmarks } },
	{ ControlMask|ShiftMask,             XK_q,      spawn,          {.v = lock } },
	{ ControlMask|ShiftMask,             XK_space,  togglefloating, {0} },
	{ ControlMask|ShiftMask,             XK_p,      spawn,          {.v = dmenucmd } },

	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ ControlMask,                  XK_Return, spawn,          {.v = termcmd } },


	{ MODKEY,                       XK_n,      spawn,          {.v = vpncmd } },
	{ ControlMask|ShiftMask,        XK_n,      spawn,          {.v = vpncmd } },

	{ ControlMask|ShiftMask,        XK_e,      spawn,          {.v = forceedpi } },

	{ MODKEY,                       XK_Tab,    view,           {0} },

	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ ControlMask,                  XK_q,      killclient,     {0} },

  { MODKEY,                       XK_f,      fullscreen,     {0} },
  { ControlMask|ShiftMask,        XK_f,      fullscreen,     {0} },

	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

	{ MODKEY|ShiftMask,             XK_Down,   focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Up,     focusstack,     {.i = -1 } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

	{ MODKEY|ShiftMask,             XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_Right,  setmfact,       {.f = +0.05} },

	{ MODKEY,                       XK_o,      spawn,          {.v = flatmenucmd } },
	{ ControlMask|ShiftMask,        XK_o,      spawn,          {.v = flatmenucmd } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	// { MODKEY,                       XK_t,      spawn,          {.v = ctrlt } },
	// { MODKEY|ShiftMask,             XK_c,      spawn,          {.v = calc } },
	// { MODKEY,                       XK_w,      spawn,          {.v = ctrlw } },
	// { MODKEY,                       XK_a,      spawn,          {.v = ctrla } },
	// { MODKEY,                       XK_c,      spawn,          {.v = ctrlc } },
	// { MODKEY,                       XK_v,      spawn,          {.v = ctrlv } },
 //  { MODKEY,                       XK_F7,     spawn,          {.v = forceedpi } },
	// { MODKEY,                       XK_b,      togglebar,      {0} },
	/* { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, */
	/* { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, */
	// { MODKEY,                       XK_space,  setlayout,      {0} },
	// { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	// { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	// { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	/* { MODKEY|ShiftMask,             XK_q,      quit,           {0} }, */
	// { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	// { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	// { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	// { MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	// { MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	// { MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
 	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
 	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
 	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

