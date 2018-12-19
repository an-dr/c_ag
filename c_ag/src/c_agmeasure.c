//
// Created by Andrey Gramakov on 04-Dec-18.
//

#include "c_agmeasure.h"
#include "sf_uart.h"

static uint32_t SearchPoint1(Point2D_Typedef point_arr[], uint32_t n_points,
                             uint32_t interp_x)
{
    //search a points
    uint32_t point_0 = 0; // first
    while (point_0 < n_points)
    {
        if (point_arr[point_0].x > interp_x)
        {
            return (point_0); // got point_b
        }
        ++point_0;
    }
    return point_0;
}

uint32_t CAG_2dGetInterpY(Point2D_Typedef point_arr[], uint32_t n_points,
                          uint32_t interp_x)
{
    uint32_t res;
    uint32_t point_1 = SearchPoint1(point_arr, n_points, interp_x);
    if (point_1 < n_points)
    {
        uint32_t point_0 = point_1 - 1;
        res = CAG_LinInterp(
                            interp_x,
                            point_arr[point_0].x,
                            point_arr[point_0].y,
                            point_arr[point_1].x,
                            point_arr[point_1].y);
    }
    else
    {
        res = -1; // timescale exceeded
    }
    out_i(res);
    return res;
}

void CAG_2dGetInterpYArray(Point2D_Typedef* orig_arr, uint32_t orig_sz,
                           Point2D_Typedef* new_arr_with_xs,
                           uint32_t new_sz)
{
    uint32_t x; //value to storing of current approx x
    for (int n_out = 0; n_out < new_sz; ++n_out)
    {
        x = new_arr_with_xs[n_out].x;
        new_arr_with_xs[n_out].y = CAG_2dGetInterpY(orig_arr, orig_sz, x);
    }
}

uint32_t CAG_CreateArrayFromBase(Point2D_Typedef *orig_arr, uint32_t orig_sz,
                                 Point2D_Typedef *new_arr_buf,
                                 uint32_t new_sz)
{
    uint32_t x, y; //values to storing of current approx x
    if (new_sz > orig_sz) return -1; // should be smaller
    uint32_t discret = orig_arr[orig_sz - 1].x / (new_sz);
    //the first:
    int p = 0;
    x = 0;
    new_arr_buf[p].x = orig_arr[0].x;
    new_arr_buf[p].y = orig_arr[0].y;
    for (p = 1; p < new_sz; p++)
    {
        x += discret;
        y = CAG_2dGetInterpY(orig_arr, orig_sz, x);
        new_arr_buf[p].x = x;
        new_arr_buf[p].y = y;
    }
    return 0;
}
