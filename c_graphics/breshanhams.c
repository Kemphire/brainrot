#include <graphics.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bresenham(int x1, int y1, int x2, int y2) {
  int dx, dy, p, x, y;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  if (x1 > x2)
    swap(&x1, &x2);
  if (y1 > y2)
    swap(&y1, &y2);

  int x_inc = x2 > x1 ? 1 : -1;
  int y_inc = y2 > y1 ? 1 : -1;

  x = x1;
  y = y1;

  p = 2 * (dy - dx);

  if (dx >= dy) {
    while (x <= x2) {
      putpixel(x, y, CYAN);
      if (p >= 0) {
        y += y_inc;
        p = p + 2 * dy - 2 * dx;
      } else {
        p = p + 2 * dy;
      }
      x += x_inc;
    }
  } else if (dy > dx) {
    while (y <= y2) {
      putpixel(x, y, CYAN);
      if (p >= 0) {
        x += x_inc;
        p = p + 2 * dy - 2 * dx;
      } else {
        p = p + 2 * dy;
      }
      y += y_inc;
    }
  }
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  // int x1 = 00, y1 = 00, x2 = 200, y2 = 200;
  // bresenham(x1, y1, x2, y2);
  bresenham(500, 300, 100, 100);

  getch();
  closegraph();
  return 0;
}
