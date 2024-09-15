#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point
{
  int x;
  int y;
};
typedef struct point point_t;

struct rectangle
{
    point_t upl;
    point_t lowr;
};
typedef struct rectangle rectangle_t;


void translate(point_t *p1, point_t *p2)
{
  p1->x += p2->x;
  p1->y += p2->y;
}

void print_point(point_t *pt)
{
    printf("point(%d,%d)\n", pt->x, pt->y);
}

point_t make_point(int x, int y)
{
    point_t point = { .x = x, .y = y };
    return point;
}

void print_rect(rectangle_t *rect)
{
    printf("rectangle(upper_left=(%d,%d), lower_right=(%d,%d)))\n", 
    rect->upl.x, rect->upl.y, rect->lowr.x, rect->lowr.y);
}

rectangle_t make_rect(int ul_x, int ul_y, int lr_x, int lr_y)
{
    point_t upper_left = make_point(ul_x, ul_y);
    point_t lower_right = make_point(lr_x, lr_y);

    rectangle_t rect = { .upl = upper_left, .lowr = lower_right};
    return rect;
}   

int area_rect(rectangle_t *rect)
{
    int ul_x = rect->upl.x;
    int ul_y = rect->upl.y;
    int lr_x = rect->lowr.x;
    int lr_y = rect->lowr.y;

    int basen = lr_x - ul_x;
    int höjden = ul_y - lr_y;

    int area = basen * höjden;
    return abs(area); //retunerar absolutbellopet av area eftersom en area aldrig är negativ.
}

bool intersects_rect(rectangle_t *r1, rectangle_t *r2)
{
    int r1_ul_x = r1->upl.x;
    int r1_ul_y = r1->upl.y;
    int r1_lr_x = r1->lowr.x;
    int r1_lr_y = r1->lowr.y;

    int r2_ul_x = r2->upl.x;
    int r2_ul_y = r2->upl.y;
    int r2_lr_x = r2->lowr.x;
    int r2_lr_y = r2->lowr.y;

    if( r1_lr_y > r2_ul_y || r2_lr_y > r1_ul_y  ||      // Om de är över eller under varandra
        r1_lr_x < r2_ul_x || r2_lr_x < r1_ul_x)         // Om de är brevid varandra 
        {
            return false;
        }
        else
        {
            return true;
        }
}

rectangle_t intersection_rect(rectangle_t *r1, rectangle_t *r2) {
    int r1_ul_x = r1->upl.x;
    int r1_ul_y = r1->upl.y;
    int r1_lr_x = r1->lowr.x;
    int r1_lr_y = r1->lowr.y;

    int r2_ul_x = r2->upl.x;
    int r2_ul_y = r2->upl.y;
    int r2_lr_x = r2->lowr.x;
    int r2_lr_y = r2->lowr.y;     //Allt detta kan man säga jag gjorde i onödan då det bara tog längre tid men lika mycket plats lol
    
    int overlap_left = (r1_ul_x > r2_ul_x) ? r1_ul_x : r2_ul_x;     //Retunera det störtsa left punken
    int overlap_top = (r1_ul_y < r2_ul_y) ? r1_ul_y : r2_ul_y ;     //Retunera det minsta top punkten
    int overlap_right = (r1_lr_x < r2_lr_x) ? r1_lr_x : r2_lr_x;    //Retunera det minsta right punkten
    int overlap_bottom = (r1_lr_y > r2_lr_y) ? r1_lr_y : r2_lr_y;   //Retunera högsta low punkten

    rectangle_t overlap;
    overlap.upl.x = overlap_left;
    overlap.upl.y = overlap_top;
    overlap.lowr.x = overlap_right;
    overlap.lowr.y = overlap_bottom;
    return overlap;
}
int main()
{
    rectangle_t r1 = make_rect(1, 3, 10, 1);
    rectangle_t r2 = make_rect(1, 2, 7, 0);

    print_rect(&r1);
    printf("arean av rektangeln är: %d\n", area_rect(&r1));

    if (intersects_rect(&r1, &r2))
    {
        puts("De överlappar");
    }
    else
    {
        puts("De överlappar inte");
    }
    rectangle_t r3 = intersection_rect(&r1, &r2);
    print_rect(&r3);
    return 0;
}