//
// Created by Andrey Gramakov on 04-Dec-18.
//

#include <c_agmeasure.h>

static uint32_t SearchPoint1(Point2D_Typedef point_arr[], uint32_t n_points, uint32_t interp_x)
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

uint32_t CAG_2dGetInterpY(Point2D_Typedef point_arr[], uint32_t n_points, uint32_t interp_x)
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
        return res;
    }
    else
    {
        return -1; // timescale exceeded
    }
}

void CAG_2dGetInterpYArray(Point2D_Typedef* orig_arr, uint32_t orig_sz,
                           Point2D_Typedef* new_arr,
                           uint32_t new_sz)
{
    uint32_t x; //value to storing of current approx x
    for (int n_out = 0; n_out < new_sz; ++n_out)
    {
        x = new_arr[n_out].x;
        new_arr[n_out].y = CAG_2dGetInterpY(orig_arr, orig_sz, x);
    }
}
