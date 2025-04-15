#include <stdio.h>

//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int x = 2;
    int max_or = 0;
    int max_and = 0;
    int max_xor = 0;

    for(int i=1; i<n; ++i)
    {
        for(int j=x; j<=n; ++j)
        {
            max_and = ((i&j) < k && (i&j) > max_and) ? (i&j) : max_and;
            max_or =  ((i|j) < k && (i|j) > max_or)  ? (i|j) : max_or;
            max_xor = ((i^j) < k && (i^j) > max_xor) ? (i^j) : max_xor;
        }
        ++x; 
    }
    printf("%d\n%d\n%d\n",max_and,max_or,max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
