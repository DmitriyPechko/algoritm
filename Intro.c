 #include <stdio.h>
#include <math.h>
#include <time.h>

void rec(int * arr, int g){
    int c = arr[0];
    arr[0] = arr[g];
    arr[g] = c;
    g--;
    if (g == 0)
        return;
    int j = 0;
    while(1==1){
        if (2*j + 1 > g)
            break;
        if (2*j + 1 == g){
            if (arr[j] < arr[2*j + 1]){
                int c = arr[j];
                arr[j] = arr[2*j + 1];
                arr[2*j + 1] = c;
                j = 2*j + 1;
            }
            else
                break;
        }
        if (2*j + 1 < g){
            if (arr[j] < arr[2*j + 1]){
                if (arr[2*j + 1] > arr[2*j + 2]){
                    int c = arr[j];
                    arr[j] = arr[2*j + 1];
                    arr[2*j + 1] = c;
                    j = 2*j + 1;
                }
                else{
                    int c = arr[j];
                    arr[j] = arr[2*j + 2];
                    arr[2*j + 2] = c;
                    j = 2*j + 2;
                }
            }
            else{
                if (arr[j] < arr[2*j + 2]){
                    int c = arr[j];
                    arr[j] = arr[2*j + 2];
                    arr[2*j + 2] = c;
                    j = 2*j + 2;
                }
                else
                    break;
            }
        }
    }
    rec(arr, g);
}
void tree(int * arr, int j, int n){
    if (2*j + 1 > n)
        return;
    if (2*j + 1 == n){
        if (arr[j] < arr[2*j + 1]){
            int c = arr[j];
            arr[j] = arr[2*j + 1];
            arr[2*j + 1] = c;
            tree(arr, 2*j+1, n);
        }
        return;
    }
    if (2*j + 1 < n){
        tree(arr, 2*j + 1, n);
        tree(arr, 2*j + 2, n);
        if (arr[j] < arr[2*j + 1]){
            int c = arr[j];
            arr[j] = arr[2*j + 1];
            arr[2*j + 1] = c;
            tree(arr, 2*j+1, n);
        }
        if (arr[j] < arr[2*j + 2]){
            int c = arr[j];
            arr[j] = arr[2*j + 2];
            arr[2*j + 2] = c;
            tree(arr, 2*j+2, n);
        }
    }
}

void psort(int * arr, int j, int n){
    tree(arr,j,n);
    rec(arr,n);
}

void intro(int * arr, int l, int g, int tmp, int length, int index){
    if ((double)tmp >= log(length) - 1)
        return;
    if(l >= g)
        return;
    int op = (arr[l] + arr[g])/2;
    int n = g;
    int m = l;
    while(l < g) {
        while ((arr[l] <= op)&&(l<=n-1))
            l++;
        while ((arr[g] > op)&&(g>=m+1))
            g--;
        if(l <= g) {
            int c = arr[l];
            arr[l] = arr[g];
            arr[g] = c;
        }
    }
    if(g<l){
        g++;
        l--;
    }
    if(l == g){
        if(l-1<m)
            g++;
        else
            l--;
    }
    tmp++;
    index = 0;
    intro(arr, m, l, tmp, length, index);
    if (index != 1){
        if (m < l)
            psort(arr + m, 0, l-m);
    }
    intro(arr, g, n, tmp, length, index);
    if (index != 1){
        if (g < n)
            psort(arr + g, 0, n-g);
    }
    index  = 1;
    tmp--;
}

int main(int argc, char * argv[]) {
    int n  = 0;
    FILE * f = fopen(argv[1], "r");
    FILE * size = fopen("size.txt", "a");
    if(f == NULL)
        return 1;
    int arr[10000];
    while (!(feof(f))){
        fscanf(f, "%d", &arr[n]);
        n++;
    }
    fprintf(size, "%d ", n);

    struct timespec t1;
    clock_gettime (CLOCK_REALTIME, &t1);

    intro(arr,0,n-1,0, n, 0);

    struct timespec t2;
    clock_gettime (CLOCK_REALTIME, &t2);

    FILE * f2 = fopen(argv[2], "w");
    if(f2 == NULL)
        return 1;
    for(int i = 0; i < n; i++)
        fprintf(f2, "%d ", arr[i]);
    FILE * time = fopen("time.TXT", "a");
    fprintf(time,"%lld ", ((1000000000*t2.tv_sec+t2.tv_nsec) - (1000000000*t1.tv_sec+t1.tv_nsec)));

    fclose(f);
    fclose(size);
    fclose(time);
    fclose(f2);
    return 0;
}