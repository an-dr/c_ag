/*
 * tests.c
 *
 *  Created on: Dec 4, 2018
 *      Author: Andrey Gramakov
 */


#include "tests.h"

void test_cagmath()
{

    uint32_t arr[] = { 0,1,2,3,4,5,6,7,8,9,10};
    uint32_t arr_aver = CAG_GetArrAverage(  arr, (uint32_t)(sizeof(arr)/sizeof(arr[0])) );
    printf("Average: %d\n", arr_aver);

    uint32_t li = CAG_LinInterp(5,0,0,100,100);
    printf("LinInterp: %d\n", li);

}
