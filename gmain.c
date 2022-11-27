#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

struct xorshift32_state* global_state = NULL;

struct xorshift32_state {
    uint32_t a;
};

uint32_t xorshift32(struct xorshift32_state* state) {
    uint32_t x = state->a;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return state->a = x;
}

float rnd(float upper) {
    if (global_state == NULL) {
        int size = sizeof(struct xorshift32_state);
        struct xorshift32_state* pointer = malloc(size);
        global_state = pointer;
    }
    global_state->a = xorshift32(global_state);
    return (global_state->a / (float)UINT32_MAX) * upper;
}

int tab(int tabs) {
    for (int i = 0; i < tabs; i++) {
        printf(" ");
    }
}

int sgn(float velue) {
    if (velue < 0) {
        return -1;
    }
    else if (velue > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

float udate(float Z) {
    Z = Z + 0.5;
    char str[10];
    sprintf(str, "%i", (int)Z);
    int size = strlen(str);
    tab(5 - size);
    tab(1);
    printf("%s", str);
    return Z;
}

int main() {
    tab(29);
    printf("RABBIT CHASE\n");
    tab(15);
    printf("CREATIVE COMPUTING  MORRISTOWN NEW JERSEY\n");
    printf("\n\n\n");

    int H, C, D1, D2, T = 400, X2 = 0, Y2 = 0;
    int V1 = (int)(rnd(1) * 10 + 0.5) * 10 + 50;
    int V2 = ((int)(rnd(1) * 2 + 0.5) + 1) * V1;
    int X1 = 0, Y1 = 0;

    float Z, X3, Y3, X4, Y4;

    for (;;) {
        X1 = ((int)(rnd(1) * 400) + 100) * sgn(rnd(1) - 0.5);
        Y1 = ((int)(rnd(1) * 400) + 100) * sgn(rnd(1) - 0.5);
        if (Y1 != 0 && X1 != 0) { break; }
    }

    printf("SPEEDS (UNITS/HOP):\n");
    printf("RABBIT - %i YOU - %i", V1, V2);
    printf("\n\n\n");

    C = pow((X2 - X1), 2) + pow((Y2 - Y1), 2);
    float P1 = (3.141592653589 / 180) * 100;

    H = 1;

    for (;;)
    {
        D1 = ((int)(rnd(1) * 359));
        printf("HOP#: ");
        Z = H;
        Z = udate(Z);

        printf(" DISTANCE TO RABBIT: ");
        Z = sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2));
        Z = udate(Z);

        printf("   CLOSEST APPROACH:");
        Z = sqrt(C);
        Z = udate(Z);

        printf("\n");
        printf("RABBIT ---     POSITION: (");
        Z = X1;
        Z = udate(Z);

        printf(",");
        Z = Y1;
        Z = udate(Z);

        printf(")   AND DIRECTION:");
        Z = D1;
        Z = udate(Z);

        printf("\n");
        printf("YOU ------     POSITION: (");
        Z = X2;
        Z = udate(Z);

        printf(",");
        Z = Y2;
        Z = udate(Z);

        printf(")   AND DIRECTION:");
        scanf("%i", &D2);

        for (;;) {
            if (D2 < 0 || D2 >= 360) {
                scanf("%i", &D2);
            }
            else { break; }
        }
        printf("\n\n");

        X3 = V1 * cos(D1 * P1) / 100;
        Y3 = V1 * sin(D1 * P1) / 100;
        X4 = V2 * cos(D2 * P1) / 100;
        Y4 = V2 * sin(D2 * P1) / 100;

        C = pow((X2 - X1), 2) + pow((Y2 - Y1), 2);

        for (int i = 1; i <= 100; i++) {
            X1 = X1 + X3;
            Y1 = Y1 + Y3;
            X2 = X2 + X4;
            Y2 = Y2 + Y4;
            C = pow((X2 - X1), 2) + pow((Y2 - Y1), 2);
        }
        H = H + 1;

        if (C > T) {

        }
        else {
            printf("\n\n");
            printf("**********\n* GOT YA *\n**********\n");
            printf("\n\n");
            break;
        }
    }
}
