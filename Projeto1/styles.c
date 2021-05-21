#include<stdio.h>
#include<stdlib.h>

void style1(int n){
    printf("\n*************************LISTA-VOO-%d****************************************************************\n",n);
    printf("\n-----------------------------------+-----------------------------------------------------------------\n");
    printf(" \n \t\t Nome \t\t\t\t BI\n ");
    printf("\n-----------------------------------+-----------------------------------------------------------------\n");
}
void style2(int n){
    printf("\n***********************LISTA-ESPERA-VOO-%d**********************************************************\n",n);
}
void style3(){
    printf("\n------------------------------------------------------------------------------------------------------\n");
}
void style4(){
    
    printf("\n-----------------------------------+---------------------------------+----------------------------------\n");
    printf(" \n \t\t Nome \t\t\t\t BI \t\t\t Situacao\n ");
    printf("\n-----------------------------------+---------------------------------+-----------------------------------\n");

}
void sobre(){
    printf("\n Estudante:Juscelino Leite Francisco \n Luanda""/""2021 \n");  
}
void help()
{
    printf("\n------------------------------HELP------------------------------------------------------------------------\n");
    printf("\n INC numero do voo primeiro nome último nome numero do BI \n");
    printf("\n REM numero do voo numero do BI \n");
    printf("\n VEB numero do voo numero do BI \n");
    printf("\n VEN primeiro nome \n");
    printf("\n LIST numero do voo \n");
    printf("\n CLS limpa a tela \n");
    printf("\n FIM terminar o programa \n");
    printf("\n HELP ajuda \n");
    printf("\n");

    sobre();
    style3();

}
