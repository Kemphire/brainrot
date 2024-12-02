#include <graphics.h>

struct pt {
  float x, y;
};

void scale_point(struct pt *point, float scaling_factor, struct pt *center) {
  point->x -= center->x;
  point->y -= center->y;
  point->x *= scaling_factor;
  point->y *= scaling_factor;
  point->x += center->x;
  point->y += center->y;
}

int main() {
  int gd = X11, gm = X11_1280x1024;
  initgraph(&gd, &gm, (char *)"");

  struct pt center = {.x = (float)(getmaxx() / 2), .y = (float)(getmaxy() / 2)};

  struct pt points[] = {{center.x + 100, center.y + 100},
                        {center.x + 200, center.y + 100},
                        {center.x + 200, center.y + 200},
                        {center.x + 100, center.y + 200}};

  for (int i = 0; i < 4; i++) {
    line(points[i].x, points[i].y, points[(i + 1) % 4].x,
         points[(i + 1) % 4].y);
  }

  for (int i = 0; i < 4; i++) {
    scale_point(&points[i], 1.5, &center);
  }

  setcolor(RED);
  for (int i = 0; i < 4; i++) {
    line(points[i].x, points[i].y, points[(i + 1) % 4].x,
         points[(i + 1) % 4].y);
  }

  getch();
  closegraph();
  return 0;
}
