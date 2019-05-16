// This is a collection of various "graphics" functions used for
// drawing stuff on the LCD screen of the development board;
// the vast majority of these are put together with a lot
// of open source code, therefore with minimal effort;

#include <stdio.h>
#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "GLCD.h"
#include "GLCD_UTILS.h"

#define __FI        1                       /* Font index 16x24               */
                                                                         

// this is simply the midpoint circle algorithm for drawing a circle;
// it is a variant of Bresenham's line algorithm, and is thus sometimes 
// known as Bresenham's circle algorithm;
// see additional info:
// http://en.wikipedia.org/wiki/Midpoint_circle_algorithm  
// http://www.mathsisfun.com/algebra/circle-equations.html
// http://members.chello.at/~easyfilter/bresenham.html
void GLCD_draw_circle( int x0, int y0, int radius)
{
    int x = radius, y = 0;
    int xChange = 1 - (radius << 1);
    int yChange = 0;
    int radiusError = 0;

    while (x >= y) 
    {
        GLCD_PutPixel(x + x0, y + y0); // call of GCLD function;
        GLCD_PutPixel(y + x0, x + y0);
        GLCD_PutPixel(-x + x0, y + y0);
        GLCD_PutPixel(-y + x0, x + y0);
        GLCD_PutPixel(-x + x0, -y + y0);
        GLCD_PutPixel(-y + x0, -x + y0);
        GLCD_PutPixel(x + x0, -y + y0);
        GLCD_PutPixel(y + x0, -x + y0);

        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0)
        {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}

// this is similar to GLCD_draw_circle() but the circle is also filled;
void GLCD_draw_circle_full( int x0, int y0, int radius) 
{
    // you must write your code here;
}

// this is the so called Bresenham's line algorithm;
// draws a line between two points specified thru their
// x,y coordinates;
// see additional info:
// http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
// TODO: http://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
void GLCD_draw_line( int x0, int y0, int x1, int y1) 
{ 
    int dx = x0<x1 ? (x1-x0) : (x0-x1); // basically dx=abs(x1-x0) 
    int sx = x0<x1 ? 1 : -1;
    int dy = y0<y1 ? (y1-y0) : (y0-y1);
    int sy = y0<y1 ? 1 : -1; 
    int err = (dx>dy ? dx : -dy)/2, e2;

    for (;;) {
        GLCD_PutPixel(x0,y0); // call of GCLD function;
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

// this draws a simplified smiley face;
// what would you change to improve it?
void GLCD_draw_smiley_face( int x0, int y0, int radius)
{
    // you must write your code here;
}
