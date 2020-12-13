#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int l, int r){
    int c = a[l];
    a[l] = a[r];
    a[r] = c;
}

void tri(int* a,int n, int c){
    int l = 2*c + 1;
    int r = 2*c + 2;
    int max = a[c];
    int imax = c;
    if (l < n && max < a[l]) {
        max = a[l];
        imax = l;
    }
    if (r < n && max < a[r]) {
        max = a[r];
        imax = r;
    }
    if (imax != c) {
        swap(a, c, imax);
        tri(a, n, imax);
    }
}

void sort(int * a, int n){
    for(int i = n - 1; i >= 0; i--){
        tri(a, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(a, 0, i);
        tri(a, i, 0);
    }
}



int main(int argc, char* argv[]){
    if(argc != 3)
        return 0;
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL)
        return 1;
    int n;
    fscanf(fp, "%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    sort(a, n);
    fp = fopen(argv[2], "w");
    if(fp == NULL)
        return 2;
    for(int i = 0; i < n; i++){
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    return 0;
}