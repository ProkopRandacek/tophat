#include "../lib/rawdraw/CNFG.h"
#include "entity.h"
#include "debug.h"
#include "misc.h"

#include <stdio.h>

void HandleKey( int keycode, int bDown ) { }
void HandleButton( int x, int y, int button, int bDown ) { }
void HandleMotion( int x, int y, int mask ) { }
void HandleDestroy() { }

int scaling;

// this will be a init function or something
int main() {
	short w, h;

	entity o = entityfromrect(newrect(10, 20, 40, 40), 0xffffebff);
	rect cam = newrect(20, 70, 210, 120);

	CNFGSetup( "Example App", 1024, 768 );

	CNFGGetDimensions(&w, &h);
	scaling =	getscaling(w, h, cam.w, cam.h);

	while (1) {
		CNFGBGColor = 0x080808ff;

		CNFGClearFrame();
		CNFGHandleInput();
		CNFGGetDimensions(&w, &h);
		scaling = getscaling(w, h, cam.w, cam.h); 

		visualizecam(cam);
		draw(o, cam);
		CNFGSwapBuffers();
	}

	return 0;
}
