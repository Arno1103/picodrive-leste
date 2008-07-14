// platform specific things for common menu code

#ifdef __GP2X__
#include "../gp2x/gp2x.h"

#define BTN_UP    GP2X_UP
#define BTN_DOWN  GP2X_DOWN
#define BTN_LEFT  GP2X_LEFT
#define BTN_RIGHT GP2X_RIGHT

#define BTN_NORTH GP2X_Y
#define BTN_SOUTH GP2X_X
#define BTN_WEST  GP2X_A
#define BTN_EAST  GP2X_B
#define BTN_L     GP2X_L
#define BTN_R     GP2X_R

unsigned long wait_for_input(unsigned long interesting);
void gp2x_pd_clone_buffer2(void);
void menu_darken_bg(void *dst, int pixels, int darker);
void menu_flip(void);

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240
#define SCREEN_BUFFER gp2x_screen

#define read_buttons(which) \
	wait_for_input(which)
#define menu_draw_begin() \
	gp2x_pd_clone_buffer2()
#define clear_screen() \
	memset(gp2x_screen, 0, 320*240*2)
#define darken_screen() \
	menu_darken_bg(gp2x_screen, 320*240, 0)
#define menu_draw_end() \
	menu_flip()

// ------------------------------------

#elif defined(__GIZ__)

// TODO
//#include "../gizmondo/giz.h"
#define SCREEN_WIDTH 321
#define SCREEN_BUFFER menu_screen
extern unsigned char *menu_screen;

// ------------------------------------

#elif defined(PSP)

#include "../psp/psp.h"

#define BTN_NORTH BTN_TRIANGLE
#define BTN_SOUTH BTN_X
#define BTN_WEST  BTN_SQUARE
#define BTN_EAST  BTN_CIRCLE

unsigned long wait_for_input(unsigned int interesting, int is_key_config);
void menu_draw_begin(void);
void menu_darken_bg(void *dst, const void *src, int pixels, int darker);
void menu_draw_end(void);

#define SCREEN_WIDTH  512
#define SCREEN_HEIGHT 272
#define SCREEN_BUFFER psp_screen

#define read_buttons(which) \
	wait_for_input(which, 0)
#define clear_screen() \
	memset(SCREEN_BUFFER, 0, SCREEN_WIDTH*SCREEN_HEIGHT*2)
#define darken_screen() \
	menu_darken_bg(psp_screen, psp_screen, SCREEN_WIDTH*SCREEN_HEIGHT, 0)

#endif
