//this file includes almost all points in C's structure
/**
 this piece of code should be reviewd when you want to recolloection important points in this chapter.
 Lengjiabing
 James Leng
 2015.4.23
 17:11
*/

#include<stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

//the defination of a point, not a pointer in C language, but a point of a shape
struct point{
  int x; //x is the horizontal cooridnate of this point
  int y; //y is the vertical coordinate of this point
};

//the defination of a rect, which composed of two points
struct rect{
  //a struct can hold other struct as its elements, such as point struct in this case
  struct point pt1;
  struct point pt2;
};
//remember that there should have a ; after the defination of a sturct

//this function can canonicalize coordinates of rectangle
//this function also shows that a function can return a type of your own defined struct, in this case, a rect
//remember the struct key word
struct rect cannonrect(struct rect r)
{
  struct rect temp;
  temp.pt1.x=min(r.pt1.x,r.pt2.x);
  temp.pt1.y=min(r.pt1.y,r.pt2.y);
  temp.pt2.x=max(r.pt1.x,r.pt2.x);
  temp.pt2.y=max(r.pt1.y,r.pt2.y);
}

//the constructor of a structure point 
struct point makePoint(int x, int y)
{
  struct point temp;
  
  temp.x=x;
  temp.y=y;
  
  return temp;
}

//the operation function on structure point
struct point addPoint(struct point p1, struct point p2)
{
  p1.x+=p2.x;
  p1.y+=p2.y;
  return p1;
}

//this function can test if a point is inside a rectangle
int ptinrect(struct point p, struct rect r)
{
  return p.x>=r.pt1.x&&p.x<r.pt2.x
      &&p.y>=r.pt1.y&&p.y<r.pt2.y;
}

int test()
{
//add code here if any test needed
}

int main()
{
  //struct rect screen;
  //give a defination of a rect, which demonstrate a computer's screen
  //this should give the middle point of this defined screen
  struct point middle;
  //didn't know should make a declaration here before using, should remember
  struct point makePoint(int,int);
  struct point addPoint(struct point, struct rect);
  int ptinrect(struct point, struct rect);
  
  //test a pointer to a struct
  struct rect screen, *rp=&screen;
  
  struct point p1 = makePoint(23,33);
  struct point p2 = makePoint(222,345);
  screen.pt1 = p1;
  screen.pt2 = p2;
  middle = makePoint((screen.pt1.x+screen.pt2.x)/2,(screen.pt1.y+screen.pt2.y)/2);
  
  //these four expressions are equivalent,they are just different types of expression
  //all of them should be remembered and know how they works
  //here uses printf to put them on screen to verify.
 printf("floolowing should be the same,\nscreen.pt1.x = : %d",screen.pt1.x);
 printf("\nrp->pt1.x = : %d",rp->pt1.x);
 printf("\n(screen.pt1).x :%d", (screen.pt1).x);
 printf("\n(rp->pt1).x = : %d", (rp->pt1).x); //at first, I write (screen->pt1).x, so this is not correct
 
 //the structure operators . and -> together with () for function calls and [] for subscript are at the top
 //of the precedence hierarchy, and thus bind very tightly, for example:
 struct {
   int len;
   cahr *str;
 } *p;
 
 p->len = 871;
 p->str = "there is another bus named 650, which can drive many people mad!";
 /**then the expression
  ++p->len; increse len, not p
  and the expression
  *p->str; fetches whatever str points to;
  * here's the test:
 */
 printf("\n the expression ++p->len=%d",++p->len);
 printf("\ the expression *p->str=%s",*p->str);
}
