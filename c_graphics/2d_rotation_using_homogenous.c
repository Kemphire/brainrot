#include <graphics.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    int x, y;
} pt;

void mat_mul(float a[][3], float b[][1], float c[][1], int r1, int c1, int r2, int c2) {
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

void rotate_points(pt *point, pt *center, float angle) {
    point->x -= center->x;
    point->y -= center->y;

    float rad = (angle * M_PI) / 180.0;

    float a[3][1] = {{point->x}, {point->y}, {1}};
    float rotate[3][3] = {
        {cos(rad), -sin(rad), 0},
        {sin(rad), cos(rad), 0},
        {0, 0, 1}
    };

    float result[3][1];
    mat_mul(rotate, a, result, 3, 3, 3, 1);

    point->x = (int)(result[0][0] + center->x);
    point->y = (int)(result[1][0] + center->y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int center_x = getmaxx() / 2;
    int center_y = getmaxy() / 2;

    pt center = {center_x, center_y};
    pt point_1 = {center_x, center_y};
    pt point_2 = {center_x + 100, center_y + 100};

    setcolor(GREEN);
    line(point_1.x, point_1.y, point_2.x, point_2.y);

    rotate_points(&point_2, &center, 45);

    setcolor(RED);
    line(point_1.x, point_1.y, point_2.x, point_2.y);

    getch();
    closegraph();
    return 0;
}
