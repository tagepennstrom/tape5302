#include <stdio.h>

struct point
{
  int x;
  int y;
};


typedef struct point point_t;


int main()
{
    point_t p1 = { .x = 10, .y = 6 };
    point_t p2 = { .x = -42, .y = 7};
    point_t p3 = { .y = 0, .x = 10};

    return 0;
}

