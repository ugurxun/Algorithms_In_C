#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    double *areas = (double *)malloc(n*sizeof(double));
    double eps =0.001;

    for(int i=0; i<n;++i)
    {   
        double p = (tr[i].a + tr[i].b + tr[i].c)/2.0;
        areas[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }

    
    for(int i=0; i<n-1;++i)
    {
        for(int k=i+1; k<n;++k)
        {
            if(areas[i]-areas[k]>eps)
            {
                double temp_ar = areas[k];
                areas[k] = areas[i];
                areas[i] = temp_ar;
                triangle temp_tr = tr[k];
                tr[k] = tr[i];
                tr[i] = temp_tr;
            }
        }
    }
    free(areas);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}