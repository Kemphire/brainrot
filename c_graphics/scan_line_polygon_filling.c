#include <graphics.h>
#include <stdio.h>

// Function to implement the scan line polygon filling algorithm
void scanLineFill(int n, int x[], int y[]) {
  int i, j, ymin, ymax, k = 0;
  int edges[20], currentX;

  // Determine ymin and ymax
  ymin = ymax = y[0];
  for (i = 1; i < n; i++) {
    if (y[i] < ymin)
      ymin = y[i];
    if (y[i] > ymax)
      ymax = y[i];
  }

  // Scan through each scanline
  for (int scanline = ymin; scanline <= ymax; scanline++) {
    k = 0;

    // Find intersections with the polygon edges
    for (i = 0; i < n; i++) {
      j = (i + 1) % n;

      if ((y[i] <= scanline && y[j] > scanline) ||
          (y[j] <= scanline && y[i] > scanline)) {
        currentX = x[i] + (scanline - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
        edges[k++] = currentX;
      }
    }

    // Sort intersections
    for (i = 0; i < k - 1; i++) {
      for (j = 0; j < k - i - 1; j++) {
        if (edges[j] > edges[j + 1]) {
          int temp = edges[j];
          edges[j] = edges[j + 1];
          edges[j + 1] = temp;
        }
      }
    }

    for (i = 0; i < k; i += 2) {
      setcolor(RED);
      line(edges[i], scanline, edges[i + 1], scanline);
    }
  }
}

int main() {
  int gd = X11, gm = X11_1280x1024;
  int n = 4, x[20] = {100, 200, 200, 100}, y[20] = {100, 100, 200, 200};  // Predefined points for a square

  initgraph(&gd, &gm, "");

  for (int i = 0; i < n; i++) {
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
  }

  scanLineFill(n, x, y);

  getch();
  closegraph();
  return 0;
}
