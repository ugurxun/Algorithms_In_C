#include"sorting.h"
#include <stdio.h>

#define LEN 50

int main()
{
    data_type seq[LEN] = {12, -5, 7, -3, 12, 0, -8, 23, 7, -16, -3, 9, 14, -7, -21, 9, 18, -12, 23, 5,
                      0, -5, 7, -8, 14, 19, -2, -12, 25, 18,-21, 6, 3, -3, -5, 19, 12, -7, 4, -16,
                      14, -2, 9, -3, 7, -5, 6, 23, -8, 0};
    
    selection_sort(seq, LEN, ASCENDING);
    display(seq, LEN);
    selection_sort(seq, LEN, DESCENDING);
    display(seq, LEN);

} 
