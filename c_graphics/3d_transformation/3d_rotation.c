#include <graphics.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    int x, y, z;
} pt;

void mat_mul(float a[][4], float b[][1], float c[][1], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void project_point(pt *point, int *screen_x, int *screen_y, float focal_length) {
    if (point->z < 1) point->z = 1;  // Avoid division by small z-values.
    *screen_x = (int)(point->x * focal_length / point->z);
    *screen_y = (int)(point->y * focal_length / point->z);
}

void rotate_x(pt *point, pt *center, float angle) {
    float rad = angle * M_PI / 180.0;

    point->x -= center->x;
    point->y -= center->y;
    point->z -= center->z;

    float a[4][1] = {{point->x}, {point->y}, {point->z}, {1}};
    float rotate[4][4] = {
        {1, 0, 0, 0},
        {0, cos(rad), -sin(rad), 0},
        {0, sin(rad), cos(rad), 0},
        {0, 0, 0, 1}
    };

    float result[4][1];
    mat_mul(rotate, a, result, 4, 4, 4, 1);

    point->x = (int)(result[0][0] + center->x);
    point->y = (int)(result[1][0] + center->y);
    point->z = (int)(result[2][0] + center->z);
}

void draw_cube(pt *vertices, int *projected_x, int *projected_y, float focal_length, int color) {
    setcolor(color);
    for (int i = 0; i < 8; i++) {
        project_point(&vertices[i], &projected_x[i], &projected_y[i], focal_length);
    }
    line(projected_x[0], projected_y[0], projected_x[1], projected_y[1]); // V1-V2
    line(projected_x[1], projected_y[1], projected_x[3], projected_y[3]); // V2-V4
    line(projected_x[3], projected_y[3], projected_x[2], projected_y[2]); // V4-V3
    line(projected_x[2], projected_y[2], projected_x[0], projected_y[0]); // V3-V1

    line(projected_x[4], projected_y[4], projected_x[5], projected_y[5]); // V5-V6
    line(projected_x[5], projected_y[5], projected_x[7], projected_y[7]); // V6-V8
    line(projected_x[7], projected_y[7], projected_x[6], projected_y[6]); // V8-V7
    line(projected_x[6], projected_y[6], projected_x[4], projected_y[4]); // V7-V5

    line(projected_x[0], projected_y[0], projected_x[4], projected_y[4]); // V1-V5
    line(projected_x[1], projected_y[1], projected_x[5], projected_y[5]); // V2-V6
    line(projected_x[2], projected_y[2], projected_x[6], projected_y[6]); // V3-V7
    line(projected_x[3], projected_y[3], projected_x[7], projected_y[7]); // V4-V8
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int center_x = getmaxx() / 2;
    int center_y = getmaxy() / 2;

    pt center = {center_x, center_y, 100}; // Increase z-value
    pt cube_vertices[8] = {
        {center_x - 100, center_y - 100, 100},
        {center_x - 100, center_y - 100, 200},
        {center_x - 100, center_y + 100, 100},
        {center_x - 100, center_y + 100, 200},
        {center_x + 100, center_y - 100, 100},
        {center_x + 100, center_y - 100, 200},
        {center_x + 100, center_y + 100, 100},
        {center_x + 100, center_y + 100, 200}
    };

    int projected_x[8], projected_y[8];
    float focal_length = 200;

    draw_cube(cube_vertices, projected_x, projected_y, focal_length, GREEN);

    for (int i = 0; i < 8; i++) {
        rotate_x(&cube_vertices[i], &center, 30);  // Rotate by 30 degrees
    }
    draw_cube(cube_vertices, projected_x, projected_y, focal_length, RED);

    getch();
    closegraph();
    return 0;
}
