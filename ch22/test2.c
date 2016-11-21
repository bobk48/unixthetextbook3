#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>

Display *dis;
Window win;

int main() {
dis = XOpenDisplay(NULL);
win = XCreateSimpleWindow(dis, RootWindow(dis, 0), 1, 1, 500, 500, \
0, BlackPixel (dis, 0), BlackPixel(dis, 0));
XMapWindow(dis, win);
XFlush(dis);
/*Sleep 5 seconds before closing.*/
sleep(5);
return(0);
}
