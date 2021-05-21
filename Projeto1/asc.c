#include<stdio.h>
#include<stdlib.h>

/*Autor: Eduardo Cavalcante
*/
int main()
{
    int a=0;
    int x=0;
    char str[256];
    printf("IMPRIMINDO TABELA ASCII");
    for(a=1;a<255;a++)
        {
            str[x] = (char)a;
            x++;
        }

    for(int i=0;str[i] !='\0';i++)
    printf(" %d-> %c ",i,str[i]);


     printf("\n");
    if(str[93] == '^')
        printf("\n EH 9\n");
    else
        printf(" nanana ");

    //Obs: %i imprime iteiro, %o imprime octal, %x imprime Hexadecimal, %c imprime caractere char
    printf("Digite algo para finalizar");

   


system("pause");
}
		