#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void QS(int * m, int n, int k)
{
    int l = n;
    int r = k;
    int o;
    int key = m[(n+k)/2];
    do
    {
        while(m[l]<key)
        {
            l++;
        }
        while(m[r]>key)
        {
            r--;
        }
        if(l<=r)
        {
            o = m[l];
            m[l] = m[r];
            m[r] = o;
            l++;
            r--;
        }

    }while(l<=r);
    if (n<r)
    {
        QS(m, n, r);
    }
    if (l<k)
    {
        QS(m, l, k);
    }
    return;
}
int main(int argc, char * argv[])
{
    FILE *inpf;
    inpf = fopen(argv[1], "r");
    int n;
    fscanf(inpf, "%d", &n);
    //scanf("\n%d\n", &n);
    int *q = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
	{
		fscanf(inpf, "%d", &q[i]);
	}
    //for(int i = 0;i<n;i++)
    //{
    //    scanf("\n%d",&q[i]);
    //}

    clock_t begin=clock();

    QS(q, 0, n-1);

    clock_t end=clock();

    printf("Time taken:%lf",(double)(end-begin)/CLOCKS_PER_SEC);

    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\n",q[i]);
        //fprintf(fp,"%d\n",q[i]);
    }
    fclose(inpf);
    free(q);
    return 0;
}