#include <graphics.h>

void drawCircle(int xc, int yc, int r) {
  int x = 0, y = r;
  int d = 3 - (2 * r);

  while (y >= x) {
    putpixel(xc + x, yc + y, CYAN);
    putpixel(xc - x, yc + y, CYAN);
    putpixel(xc + x, yc - y, CYAN);
    putpixel(xc - x, yc - y, CYAN);
    putpixel(xc + y, yc + x, CYAN);
    putpixel(xc - y, yc + x, CYAN);
    putpixel(xc + y, yc - x, CYAN);
    putpixel(xc - y, yc - x, CYAN);

    x++;

    if (d > 0) {
      y--;
      d = d + 4 * (x - y) + 10;
    } else {
      d = d + 4 * x + 6;
    }
  }
}


int main() {
  int gd = X11, gm = X11_1366x768;
  initgraph(&gd, &gm, "");
  int radius = 100;
  drawCircle(getmaxx() / 2, getmaxy() / 2,radius);
  getch();
  closegraph();
  return 0;
}
