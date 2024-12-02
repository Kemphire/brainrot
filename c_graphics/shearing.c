#include <graphics.h>
#include <stdio.h>

void shearTransform(int x[], int y[], int n, float shx, float shy) {
  for (int i = 0; i < n; i++) {
    int newX = x[i] + shx * y[i];
    int newY = y[i] + shy * x[i];
    x[i] = newX;
    y[i] = newY;
  }
}

int main() {
  int gd = X11, gm = X11_1024x768;
  initgraph(&gd, &gm, NULL);

  int x[] = {100, 200, 200, 100};
  int y[] = {100, 100, 200, 200};
  int n = 4;

  for (int i = 0; i < n; i++) {
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
  }

  float shx = 1.0, shy = 0.0;
  shearTransform(x, y, n, shx, shy);

  setcolor(RED);
  for (int i = 0; i < n; i++) {
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
  }

  getch();
  closegraph();
  return 0;
}
