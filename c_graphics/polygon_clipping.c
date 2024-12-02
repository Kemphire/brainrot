#include <graphics.h>

#define MAX_POINTS 20

// Function to calculate intersection point of two lines
void intersect(int x1, int y1, int x2, int y2, int wx1, int wy1, int wx2,
               int wy2, int *x, int *y) {
  float m1, c1, m2, c2;
  if (x1 == x2) { // Line is vertical
    *x = x1;
    m2 = (float)(wy2 - wy1) / (wx2 - wx1);
    c2 = wy1 - m2 * wx1;
    *y = m2 * (*x) + c2;
  } else if (wx1 == wx2) { // Window boundary is vertical
    *x = wx1;
    m1 = (float)(y2 - y1) / (x2 - x1);
    c1 = y1 - m1 * x1;
    *y = m1 * (*x) + c1;
  } else {
    m1 = (float)(y2 - y1) / (x2 - x1);
    c1 = y1 - m1 * x1;
    m2 = (float)(wy2 - wy1) / (wx2 - wx1);
    c2 = wy1 - m2 * wx1;
    *x = (c2 - c1) / (m1 - m2);
    *y = m1 * (*x) + c1;
  }
}

// Function to check if a point is inside the window
int inside(int x, int y, int wx1, int wy1, int wx2, int wy2, int edge) {
  switch (edge) {
  case 1:
    return (x >= wx1); // Left
  case 2:
    return (x <= wx2); // Right
  case 3:
    return (y >= wy1); // Bottom
  case 4:
    return (y <= wy2); // Top
  }
  return 0;
}

// Sutherland-Hodgman Clipping Algorithm
void sutherlandHodgman(int poly_points[][2], int n, int wx1, int wy1, int wx2,
                       int wy2) {
  int clipped_points[MAX_POINTS][2], new_points[MAX_POINTS][2], i, j, k;
  int x1, y1, x2, y2, newn, x, y;

  // Clipping against the four edges of the window
  for (int edge = 1; edge <= 4; edge++) {
    newn = 0;
    for (i = 0; i < n; i++) {
      j = (i + 1) % n; // Next point
      x1 = poly_points[i][0];
      y1 = poly_points[i][1];
      x2 = poly_points[j][0];
      y2 = poly_points[j][1];

      if (inside(x2, y2, wx1, wy1, wx2, wy2, edge)) {
        if (inside(x1, y1, wx1, wy1, wx2, wy2, edge)) {
          new_points[newn][0] = x2;
          new_points[newn++][1] = y2;
        } else {
          intersect(x1, y1, x2, y2, wx1, wy1, wx2, wy2, &x, &y);
          new_points[newn][0] = x;
          new_points[newn++][1] = y;
          new_points[newn][0] = x2;
          new_points[newn++][1] = y2;
        }
      } else if (inside(x1, y1, wx1, wy1, wx2, wy2, edge)) {
        intersect(x1, y1, x2, y2, wx1, wy1, wx2, wy2, &x, &y);
        new_points[newn][0] = x;
        new_points[newn++][1] = y;
      }
    }
    // Copy new points back into original polygon points
    for (k = 0; k < newn; k++) {
      poly_points[k][0] = new_points[k][0];
      poly_points[k][1] = new_points[k][1];
    }
    n = newn;
  }

  // Draw the final clipped polygon
  int polygon[MAX_POINTS * 2];
  for (i = 0; i < n; i++) {
    polygon[2 * i] = poly_points[i][0];
    polygon[2 * i + 1] = poly_points[i][1];
  }
  fillpoly(n, polygon);
}

int main() {
  int gd = DETECT, gm;

  // Initialize graphics mode
  initgraph(&gd, &gm, "");

  // Define the polygon (a square in this case)
  int poly_points[4][2] = {{150, 150}, {300, 150}, {300, 300}, {150, 300}};

  // Define the clipping window (smaller than the polygon)
  int wx1 = 200, wy1 = 200, wx2 = 400, wy2 = 400;

  // Draw the original polygon
  setcolor(WHITE);
  line(poly_points[0][0], poly_points[0][1], poly_points[1][0],
       poly_points[1][1]);
  line(poly_points[1][0], poly_points[1][1], poly_points[2][0],
       poly_points[2][1]);
  line(poly_points[2][0], poly_points[2][1], poly_points[3][0],
       poly_points[3][1]);
  line(poly_points[3][0], poly_points[3][1], poly_points[0][0],
       poly_points[0][1]);

  // Draw the clipping window
  setcolor(RED);
  rectangle(wx1, wy1, wx2, wy2);

  // Wait for user input before clipping
  getch();

  // Perform Sutherland-Hodgman polygon clipping
  setcolor(YELLOW);
  sutherlandHodgman(poly_points, 4, wx1, wy1, wx2, wy2);

  // Wait for user to see the result
  getch();

  // Close the graphics mode
  closegraph();
  return 0;
}
