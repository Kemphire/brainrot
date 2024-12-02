#include <graphics.h>

void draw_circle(int xc, int yc, int rad) {
  int x = 0, y = rad;
  int p = 5 - 4 * rad;

  while (y >= x) {
    putpixel(xc + x, yc + y, RED);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc - y, yc + x, RED);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc - y, yc - x, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc + y, yc - x, RED);
    x++;

    if (p < 0) {
      p = p + 2 * x + 3;
    } else {
      y--;
      p = p + 5 + (2 * x) - (2 * y);
    }
  }
}

void draw_curve(int x0, int y0, int x1, int y1, int x2, int y2) {
  for (float i = 0; i <= 1; i += (float)0.001) {
    int x_c1 = (1 - i) * x0 + x1 * i;
    int y_c1 = (1 - i) * y0 + y1 * i;

    int x_c2 = (1 - i) * x1 + x2 * i;
    int y_c2 = (1 - i) * y1 + y2 * i;

    int x_f = (1 - i) * x_c1 + x_c2 * i;
    int y_f = (1 - i) * y_c1 + y_c2 * i;
    draw_circle(x_f, y_f, 2);
  }
}

int main(int argc, char **argv) {
  int gd = X11, gm = X11_1280x1024;
  initgraph(&gd, &gm, (char *)"");

  int x0 = 100, y0 = 200;
  int x1 = 300, y1 = 100;
  int x2 = 700, y2 = 400;
  draw_curve(x0, y0, x1, y1, x2, y2);
  getch();
  closegraph();
}
