//Author: Uður ÜN
//Date:   22.10.24

#include <stdio.h>
#include <string.h>
#include "nutility.h";

void* g_strstr(const void* vp1, size_t sz1, const void* vp2, size_t sz2, size_t sz_t)
{

    const char* p1 = (const char*)vp1;
    const char* p2 = (const char*)vp2;

    for (size_t i = 0; i <= (sz1 - sz2);++i)
    {
        if (!memcmp(p1 + i * sz_t, p2, sz2*sz_t))
            return  (p1 + i * sz_t);
    }
    return NULL;

}

int main()
{
    //const char p1[] = "ankara'da kara gozlu kara kasli bir arkadasim var";
    //const char p2[] = "del";
    //const int  p1[] = {10,20,30,40,50,60,70,80,90,100};
    //const int  p2[] = {40,50,60};
    //const double  p1[] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,100.5};
    //const double  p2[] = {8.5,9.5};
    
    int a = 65, b = 'A';
    const int *p1 = &a;
    const int *p2 = &b;


    //const char*   gp = (const char*)g_strstr(p1,asize(p1),p2,asize(p2),sizeof(*p1); 
    //const int*    gp = (const int*)g_strstr(p1, asize(p1), p2, asize(p2), sizeof(*p1));
    //const double* gp = (const double*)g_strstr(p1, asize(p1), p2, asize(p2), sizeof(*p1));
    const int* gp = (const int*)g_strstr(p1, asize(p1), p2, asize(p2), sizeof(*p1));
   
    if (gp)
        printf("%zu. Founded.", gp - p1);
    else
        printf("Not founded !");


}

