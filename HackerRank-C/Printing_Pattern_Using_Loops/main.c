#include <stdio.h>


int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int max_idx = 2*n - 2;

    for(int i=0; i<= max_idx;++i)
    {
        for(int j=0; j<= max_idx;++j)
        {
            if(i<=j && j<= max_idx-i)
                printf("%d ",n-i);
            else if(max_idx-i<=j && j<= i)
                printf("%d ",n+i-max_idx);
            else if(j<=i && i<= max_idx-j)
                printf("%d ",n-j);
            else if(max_idx-j<=i && i<=j)
                printf("%d ",n+j-max_idx);
            else
                printf("%d ",n);
        }
        putchar('\n');
    }

    return 0;
}