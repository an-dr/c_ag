//
// Created by Andrey Gramakov on 04-Dec-18.
//

#ifndef CAG_CAGMATH_H
#define CAG_CAGMATH_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint32_t CAG_GetArrAverage(uint32_t* array, uint32_t arr_size);
uint32_t CAG_LinInterp(uint32_t x, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif //CAG_CAGMATH_H
