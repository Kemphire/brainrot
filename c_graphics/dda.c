#include <graphics.h>
#include <math.h>

void draw_line(float x1, float y1, float x2, float y2) {
  float dx = x2 - x1, dy = y2 - y1;
  int steps = abs((int)dx) > abs((int)dy) ? abs(dx) : abs(dy);

  float x_inc = (float)dx / steps;
  float y_inc = (float)dy / steps;
  float x = x1, y = y1;

  for (int i = 0; i < steps; i++) {
    putpixel((int)round(x), (int)round(y), RED);
    x += x_inc;
    y += y_inc;
  }
}

int main(void) {
  int gd = X11, gm = X11_1024x768;
  initgraph(&gd, &gm, (char *)"");
  draw_line(100, 100, 200, 200);
  getch();
  closegraph();
  return 0;
}
