//
// Created by Andrey Gramakov on 04-Dec-18.
//

#include <c_agmath.h>

uint32_t CAG_GetArrAverage(uint32_t* array, uint32_t arr_size)
{
    uint32_t sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum += array[i];
    }
    return (sum / arr_size);
}

uint32_t CAG_LinInterp(uint32_t x, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
    /*(y - y0) / (x - x0) = (y1 - y0) / (x1 - x0)
     * v
     * y = y0 + (x - x0) * (y1 - y0) / (x1 - x0)
     * */
    return ( y0 + (x - x0) * (y1 - y0) / (x1 - x0) );
}