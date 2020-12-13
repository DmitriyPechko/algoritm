#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 3)
        return 0;
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL)
        return 1;
    int n;
    fscanf(fp, "%d", &n);
    int m[n];
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d", &m[i]);
    }
    fclose(fp);
    for(int d = n/2; d >= 1; d /= 2){
        for(int i = d; i < n; i++){
            for(int j = i; j > 0 && m[j-d]>m[j]; j-=d && j>=d){
                m[j - d] += m[j];
                m[j] = m[j - d] - m[j];
                m[j - d] -= m[j];
            }
        }
    }
    fp = fopen(argv[2], "w");
    if(fp == NULL)
        return 2;
    for(int i = 0; i < n; i++){
        fprintf(fp, "%d\n", m[i]);
    }
    fclose(fp);
}