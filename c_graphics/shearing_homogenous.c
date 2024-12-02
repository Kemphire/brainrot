#include <graphics.h>
#include <math.h>
#include <stdio.h>

typedef struct {
  int x, y;
} pt;

void mat_mul(float a[][3], float b[][1], float c[][1], int r1, int c1, int r2,
             int c2) {
  if (c1 != r2) {
    printf("Matrix multiplication not possible\n");
    return;
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      c[i][j] = 0;
      for (int k = 0; k < c1; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void shear_points(int x[], int y[], pt *center, float shx, float shy, int n) {

  for (int i = 0; i < n; i++) {

    x[i] -= center->x;
    y[i] -= center->y;

    float a[3][1] = {{x[i]}, {y[i]}, {1}};
    float rotate[3][3] = {{1, shx, 0}, {shy, 1, 0}, {0, 0, 1}};

    float result[3][1];
    mat_mul(rotate, a, result, 3, 3, 3, 1);

    x[i] = (int)(result[0][0] + center->x);
    y[i] = (int)(result[1][0] + center->y);
  }
}

int main() {
  int gd = X11, gm = X11_1024x768;
  initgraph(&gd, &gm, NULL);

  int center_x = getmaxx() / 2;
  int center_y = getmaxy() / 2;

  pt center = {center_x, center_y};

  int x[] = {center_x + 100, center_x + 200, center_x + 200, center_x + 100};
  int y[] = {center_y + 100, center_y + 100, center_y + 200, center_y + 200};
  int n = 4;

  for (int i = 0; i < n; i++) {
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
  }

  float shx = 1.0, shy = 0.0;
  shear_points(x, y, &center, shx, shy, n);

  setcolor(RED);
  for (int i = 0; i < n; i++) {
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
  }

  getch();
  closegraph();
  return 0;
}
