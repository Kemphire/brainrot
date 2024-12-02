#include <graphics.h>
#include <math.h>

typedef struct {
  int x, y;
} pt;

void rotate_pt(pt *rt_points, float angle, pt *center) {
  float rad = angle * M_PI / 180.0;
  int x = rt_points->x - center->x;
  int y = rt_points->y - center->y;
  int x_f = (int)(x * cos(rad) - y * sin(rad));
  int y_f = (int)(y * cos(rad) + x * sin(rad));
  rt_points->x = x_f + center->x;
  rt_points->y = y_f + center->y;
}

int main() {
  int gd = X11, gm = X11_800x600;
  initgraph(&gd, &gm, (char *)"");
  int center_x = (int)(getmaxx()/2);
  int center_y = (int)(getmaxy()/2);
  pt center = {.x = center_x,.y = center_y};
  pt point_1 = {.x = center_x, .y = center_y};
  pt point_2 = {.x = center_x + 100, .y = center_y+ 100};
  setcolor(GREEN);
  line(point_1.x, point_1.y, point_2.x, point_2.y);
  rotate_pt(&point_2, 45,&center);
  setcolor(RED);
  line(point_1.x, point_1.y, point_2.x, point_2.y);
  getch();
  closegraph();
}
