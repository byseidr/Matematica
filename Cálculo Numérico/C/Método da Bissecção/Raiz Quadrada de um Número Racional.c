#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

//NÃ£o Ã© possÃ­vel usar rho com o mÃ©todo da bisseÃ§Ã£o.

int main (){

setlocale(LC_ALL, "Portuguese_Brazil");

    double A, inf, sup, D, media, media1, F, f1, x1, y1, f2, f3, tecla, fmedia, fmedia1;

    int B;

    printf("Cálculo da raiz quadrada de um número\n\n");

    printf("Digite o número ao qual se deseja encontrar a raiz:\n");
    scanf("%lf", &A);
    fflush(stdin);

    double rho;

    sup=1+A;
    inf=1;
    f1=(inf*inf)-A;
    f2=(sup*sup)-A;
    D=f1*f2;


            if(D<0){

                printf("Temos uma raiz no intervalo (%lf, %lf).\n", inf, sup);
                printf("Continuando... Pelo método da bissecçãoo, considere o ponto médio desse intervalo:\n" );

                media=(inf+sup)/2;
                fmedia=(media*media)-A;
                x1=fmedia*f1;
                y1=fmedia*f2;

                printf("O valor do ponto médio é: %lf.\n", media);

                if(fmedia==0){
                    printf("A raiz é: %lf.", media);
                }else{

                while(x1<0 || y1<0){

                    if(fmedia=0){
                    printf("O valor da raiz é:%lf.\n", media );
                    }else{
                         if(x1<0){
                    printf("A raiz está no intervalo: (%lf, %lf).\n", inf, media);
                    sup=media;
                    }
                         if(y1<0){
                    printf("A raiz está no intervalo: (%lf, %lf).\n", media, sup);
                    inf=media;
                         }

                    }



                media=(inf+sup)/2;
                fmedia=(media*media)-A;
                x1=fmedia*f1;
                y1=fmedia*f2;


                }}


                return 0;
            }


}