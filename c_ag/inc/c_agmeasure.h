//
// Created by Andrey Gramakov on 04-Dec-18.
//

#ifndef CAG_CAGMEASURE_H
#define CAG_CAGMEASURE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "c_agmath.h"

typedef struct
{
    uint32_t x;
    uint32_t y;
} Point2D_Typedef;

uint32_t CAG_2dGetInterpY(Point2D_Typedef point_arr[], uint32_t n_points, uint32_t interp_x);
void CAG_2dGetInterpYArray(Point2D_Typedef *orig_arr, uint32_t orig_sz,
                           Point2D_Typedef *new_arr,  uint32_t new_sz);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif //CAG_CAGMEASURE_H
