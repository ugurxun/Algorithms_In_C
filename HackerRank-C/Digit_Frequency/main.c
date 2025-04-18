#include <stdio.h>
#include <ctype.h>

#define NUM 10

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char* str;
    int c;
    int numbers[NUM] ={0};

    while((c = getchar()) != '\n')
        if (isdigit(c))
            ++numbers[c-'0'];

    for(int i=0; i<NUM; ++i)
        printf("%d ",numbers[i]);
    
    return 0;
}
