/* Xlib and standard headers */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <stdlib.h>

/* Declare the X variables and pointers */
Display *dis;
int screen;
Window win;
GC gc;

/* X routines */
void init_x();
void close_x();
void redraw();

main () {
	
/*Initialization*/
    XEvent event;		/* declare the XEvent */
	KeySym key;		    /* KeyPress Events */	
	char text[255];		/* a char buffer for KeyPress Events */

	init_x();

	/* Start the Event-Request Loop*/
	while(1) {		
		/* get the next event 
		   We set the mask for events that we want detected
		*/
		XNextEvent(dis, &event);
	
		if (event.type==Expose && event.xexpose.count==0) {
		/* the window was exposed redraw it! */
			redraw();
		}
		if (event.type==KeyPress&&
		    XLookupString(&event.xkey,text,255,&key,0)==1) {
		/* use the XLookupString routine to convert the invent
		   KeyPress data into regular text.
		*/
			if (text[0]=='q') {
				close_x();
			}
			printf("You pressed the %c key!\n",text[0]);
		}
		if (event.type==ButtonPress) {
		/* report where the mouse Button was Pressed */
			int x=event.xbutton.x,
			    y=event.xbutton.y;

			strcpy(text,"UNIX Rocks");
			XSetForeground(dis,gc,rand()%event.xbutton.x%255);
			XDrawString(dis,win,gc,x,y, text, strlen(text));
		}
	}
}

void init_x() {
/* set the colors black and white */        
	unsigned long black,white;

	dis=XOpenDisplay((char *)0);
   	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen),
	white=WhitePixel(dis, screen);
   	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,	
		300, 300, 5,black, white);
	XSetStandardProperties(dis,win,"Report","E",None,NULL,0,NULL);
	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);
        gc=XCreateGC(dis, win, 0,0);        
	XSetBackground(dis,gc,white);
	XSetForeground(dis,gc,black);
	XClearWindow(dis, win);
	XMapRaised(dis, win);
};

/* Cleanup */
void close_x() {
	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);	
	exit(1);				
};

void redraw() {
	XClearWindow(dis, win);
};
