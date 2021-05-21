#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int converter(char v[], int z){
    int num=0,i=0;
    int p1=0, p2=0; 
    if(z == 1){
        num = v[i] - 48;
        return num;
    }
    else if(z == 2)
    {
        p1 = v[i] - 48;
        p2 = v[i+1] - 48;
        num = p1*10+p2;
        return num;
    }
    return num;
}

int strTam(char v[]){
    int tam=0;
    for(int i=0; v[i] != '\0'; i++)
       tam++;
}

int compareStr(char str1[], char str2[]){
    int i=0;
    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
    {
        ++i;
    }
    if(str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
    
}

int isdi(char str[]){
   
}