/*
 * tests.c
 *
 *  Created on: Dec 4, 2018
 *      Author: Andrey Gramakov
 */

#include "tests.h"

void test_c_agmath()
{

    uint32_t arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    uint32_t arr_aver = CAG_GetArrAverage(arr, (uint32_t)(sizeof(arr) / sizeof(arr[0])));
    printf(">>Average: %d\n", arr_aver);

    uint32_t li = CAG_LinInterp(5, 0, 0, 100, 100);
    printf(">>LinInterp: %d\n", li);

}

void test_c_agmeasure()
{
    Point2D_Typedef new_arr[] = {
                                   { 1, 0 },
                                   { 5, 0 },
                                   { 10, 0 },
                                   { 20, 0 },
                                   { 30, 0 },
    };
    Point2D_Typedef old_arr[] = {
                                   { 1, 1 },
                                   { 3, 3 },
                                   { 17, 17 },
                                   { 40, 40 },
    };
    uint32_t old_sz =sizeof(old_arr)/sizeof(old_arr[0]);
    uint32_t new_sz =sizeof(new_arr)/sizeof(new_arr[0]);

    CAG_2dGetInterpYArray(old_arr, old_sz, new_arr, new_sz);

    printf(">> Interp\n");
    printf("Old arr: \n");
    for (int el = 0; el < old_sz; ++el) {
        printf("(%d;%d)", old_arr[el].x,old_arr[el].y);
        printf("\n");
    }
    printf("New arr: \n");
    for (int el = 0; el < new_sz; ++el) {
        printf("(%d;%d)", new_arr[el].x,new_arr[el].y);
        printf("\n");
    }
}
