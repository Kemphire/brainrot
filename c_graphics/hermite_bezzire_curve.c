#include <graphics.h>
#include <math.h>

void drawHermiteCurve(int x0, int y0, int x1, int y1, int rx0, int ry0, int rx1,int ry1) {
  float t, x, y;
  for (t = 0.0; t <= 1.0; t += 0.001) {
    float h1 = 2 * t * t * t - 3 * t * t + 1;
    float h2 = -2 * t * t * t + 3 * t * t;
    float h3 = t * t * t - 2 * t * t + t;
    float h4 = t * t * t - t * t;

    x = h1 * x0 + h2 * x1 + h3 * rx0 + h4 * rx1;
    y = h1 * y0 + h2 * y1 + h3 * ry0 + h4 * ry1;

    putpixel((int)x, (int)y, RED);
  }
}

void drawBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3,int y3) {
  float t, x, y;
  for (t = 0.0; t <= 1.0; t += 0.001) {
    float b0 = (1 - t) * (1 - t) * (1 - t);
    float b1 = 3 * t * (1 - t) * (1 - t);
    float b2 = 3 * t * t * (1 - t);
    float b3 = t * t * t;

    x = b0 * x0 + b1 * x1 + b2 * x2 + b3 * x3;
    y = b0 * y0 + b1 * y1 + b2 * y2 + b3 * y3;

    putpixel((int)x, (int)y, GREEN);
  }
}

int main() {
  int gd =X11, gm = X11_1280x1024;
  initgraph(&gd, &gm, (char *)"");

  drawHermiteCurve(100, 300, 400, 300, 100, -200, -100, 200);

  drawBezierCurve(200, 400, 250, 200, 350, 200, 400, 400);

  getch();
  closegraph();
  return 0;
}
