/*
 ============================================================================
 Name        : Calc_with_vectors.c
 Author      : Andrew_Vorotyntsev
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>


float factorial(float n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *write , *result ;
    write = fopen("Data.txt", "r");
    result = fopen("Result.txt" , "w");
    float a , b ;
    int z , t , i ,n ;
    fscanf(write ,"%i" , &z);
    if (z==0){
        fscanf(write ,"%f" , &a);
        fscanf(write ,"%f" , &b);
        fscanf(write ,"%i" , &t);
        switch (t)
            {
                case 0:
                    fprintf(result," Answer=%f", a+b);
                    break;
                case 1:
                    fprintf(result," Answer=%f", a-b);
                    break ;
                case 2:
                    fprintf(result," Answer=%f", a*b);
                    break ;
                case 3:
                    fprintf(result," Answer=%f", a/b);
                   break;
                case 4:
                    fprintf(result," Answer=%f", pow (a, b));
                    break;
                case 5:
                    fprintf(result," Answer=%f", factorial(a));
                    break;
        }
    }
    if(z==1){
        fscanf(write,"%i", &i ); // Вводим размерность векторов
        float *A , *B ,e ,d;
        if (A != NULL) A = malloc(i*sizeof(float));
        if (B != NULL) B = malloc(i*sizeof(float));
        for (int k=0;k<i;k++)
            fscanf(write,"%f", &A[k]);
        for (int l=0;l<i;l++)
            fscanf(write,"%f", &B[l]);
        fscanf (write,"%i",&n) ;
        switch (n)
            {
                case 0:
                    for (int p=0;p<i;p++)
                        fprintf(result,"Answer=%f" , A[p]+B[p]);
                    break;
                case 1:
                    for (int r=0;r<i;r++)
                        fprintf(result,"Answer=%f" , A[r]-B[r]);
                    break ;
                case 2:
                    e=0;
                    for (int s=0;s<i;s++)
                    {
                        d=A[s]*B[s];
                        e=e+d;
                    }
                    fprintf(result,"Answer=%f", e);
                    break;
            }
    }
        printf("That's all");
}
