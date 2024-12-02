#include <graphics.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    int x, y, z;
} pt;

void mat_mul(float a[][4], float b[][1], float c[][1], int r1, int c1, int r2, int c2) {
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

void project_point(pt *point, int *screen_x, int *screen_y, float focal_length) {
    if (point->z <= 0) {
        *screen_x = point->x;
        *screen_y = point->y;
        return;
    }
    *screen_x = (int)(point->x * focal_length / point->z);
    *screen_y = (int)(point->y * focal_length / point->z);
}

void scale_points(pt *point, pt *center, float scaling_factor) {
    point->x -= center->x;
    point->y -= center->y;
    point->z -= center->z;

    float a[4][1] = {{point->x}, {point->y}, {point->z}, {1}};
    float scale[4][4] = {
        {scaling_factor, 0, 0, 0},
        {0, scaling_factor, 0, 0},
        {0, 0, scaling_factor, 0},
        {0, 0, 0, 1}
    };

    float result[4][1];
    mat_mul(scale, a, result, 4, 4, 4, 1);

    point->x = (int)(result[0][0] + center->x);
    point->y = (int)(result[1][0] + center->y);
    point->z = (int)(result[2][0] + center->z);
}

void draw_cube(pt *vertices, int *projected_x, int *projected_y, float focal_length, int color) {
    setcolor(color);
    for (int i = 0; i < 8; i++) {
        project_point(&vertices[i], &projected_x[i], &projected_y[i], focal_length);
    }

    // Draw front face
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

    pt center = {center_x, center_y, 100}; // Center of the cube
    pt cube_vertices[8] = {
        {center_x - 100, center_y - 100, 0},   // V1
        {center_x - 100, center_y - 100, 200}, // V2
        {center_x - 100, center_y + 100, 0},   // V3
        {center_x - 100, center_y + 100, 200}, // V4
        {center_x + 100, center_y - 100, 0},   // V5
        {center_x + 100, center_y - 100, 200}, // V6
        {center_x + 100, center_y + 100, 0},   // V7
        {center_x + 100, center_y + 100, 200}  // V8
    };

    int projected_x[8], projected_y[8];
    float focal_length = 300;

    // Draw the original cube
    draw_cube(cube_vertices, projected_x, projected_y, focal_length, GREEN);

    // Scale the cube vertices
    for (int i = 0; i < 8; i++) {
        scale_points(&cube_vertices[i], &center, 1.5);
    }

    draw_cube(cube_vertices, projected_x, projected_y, focal_length, RED);

    getch();
    closegraph();
    return 0;
}
