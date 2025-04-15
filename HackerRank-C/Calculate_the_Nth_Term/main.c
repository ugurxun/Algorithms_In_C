#include <stdio.h>
//Complete the following function.
#define NMAX 20

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
    int arr[NMAX] ={a,b,c,0};
    
    if(n < 4)
        return arr[n-1];

    for(int i =4; i<=n; ++i)
        arr[i-1]= arr[i-2] + arr[i-3] + arr[i-4];

    return arr[n-1];

}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}