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


//определяем функция факториал
float factorial(float n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    //открываем файлы для чтения и записи
    FILE *write , *result ;
    write = fopen("Data.txt", "r");
    result = fopen("Result.txt" , "w");
    float a , b ;
    int z , t , i ,n ;
    //Считываем данные из файла ,производим вычисления
    fscanf(write ,"%i" , &z);
    if (z==0){
        fscanf(write ,"%f" , &a);//Считываются переменные
        fscanf(write ,"%f" , &b);
        fscanf(write ,"%i" , &t);//считывается номер операции
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
        fscanf(write,"%i", &i );
        float *A , *B ,e ,d;
        A = malloc(i*sizeof(float));
        B = malloc(i*sizeof(float));
        //поочередно сканируются координаты
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
