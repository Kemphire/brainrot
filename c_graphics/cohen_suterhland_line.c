#include <graphics.h>
#include <math.h>
#include <stdbool.h>

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

int x_max = 250, y_max = 250, x_min = 100, y_min = 100;

int compute(int x, int y) {
  int code = INSIDE;
  if (x < x_min)
    code |= LEFT;
  else if (x > x_max)
    code |= RIGHT;
  if (y < y_min)
    code |= BOTTOM;
  else if (y > y_max)
    code |= TOP;
  return code;
}

void draw(int x1, int y1, int x2, int y2) {
  int line_code1 = compute(x1, y1);
  int line_code2 = compute(x2, y2);

  int line_inside = false;

  while (true) {
    if ((line_code1 == 0) && (line_code2 == 0)) {
      line_inside = true;
      break;
    } else if (line_code1 & line_code2) {
      break;
    } else {
      int code_out = 0;
      int x, y;
      code_out = line_code1 ? line_code1 : line_code2;

      if (code_out & TOP) {
        x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
        y = y_max;
      } else if (code_out & BOTTOM) {
        x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
        y = y_min;
      } else if (code_out & RIGHT) {
        y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
        x = x_max;
      } else if (code_out & LEFT) {
        y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
        x = x_min;
      }
      if (code_out == line_code1) {
        x1 = x, y1 = y;
        line_code1 = compute(x1, y1);
      } else {
        x2 = x, y2 = y;
        line_code2 = compute(x2, y2);
      }
    }
  }
  if (line_inside) {
    setcolor(GREEN);
    line(x1, y1, x2, y2);
  }
}

int main() {
  int gd = X11, gm = X11_800x600;
  initgraph(&gd, &gm, "");

  int x1 = 50, y1 = 250, x2 = 150, y2 = 120;

  rectangle(x_min, y_min, x_max, y_max);

  setcolor(RED);
  line(x1, y1, x2, y2);

  draw(x1, y1, x2, y2);

  getch();
  closegraph();
  return 0;
}
