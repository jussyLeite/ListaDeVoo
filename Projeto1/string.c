#include<stdio.h>
#include<string.h>



int recebe(char str[]){
    printf("\n Digite a sintaxe \n");
    gets(str);
    return 1;
}

void impri(char str[]){
    int t = strlen(str);
    printf(" %s ",str);
    printf("tam %d ",t);
}

void analizador(char frase[]){
    char str1[5],str0[10], str2[3], str3[10], str4[10], str5[10];
    int t = strlen(frase);
    int l=0,l1=0,l2=0,l3=0;
    int i,j=0,k=0,b=0;
    int e=0, y=0, z=0, space=0;

    for(int o=0; frase[o] != '\0'; o++)
        if(frase[o] == ' ')
            space++;

if(space == 1){
    for( i=0; frase[i] != ' '; i++){
         printf(" %d",i);
            str1[i] = frase[i];
    }
    str1[i] ='\0';
    printf(" i=%d ",i);

   for( j=i+1; frase[j] != '\0'; j++){
        printf(" %d ",j);
            str2[k] = frase[j];
            k++;
    } 
    str2[k] ='\0';
    
}
else
 if(space == 2){
    for( i=0; frase[i] != ' '; i++){
         printf(" %d",i);
            str1[i] = frase[i];
    }
    str1[i] ='\0';
    printf(" i=%d ",i);

   for( j=i+1; frase[j] != ' '; j++){
        printf(" %d ",j);
            str2[k] = frase[j];
            k++;
    } 
    str2[k] ='\0'; 
    
     for( e=j+1; frase[e] != '\0'; e++){
        printf(" %d ",t);
            str3[y] = frase[e];
            y++;
    }  
    str3[y] = '\0';
}
else if(space == 3){
    
     for( i=0; frase[i] != ' '; i++){
         printf(" %d",i);
            str1[i] = frase[i];
    }
    str1[i] ='\0';
    printf(" i=%d ",i);

   for( j=i+1; frase[j] != ' '; j++){
        printf(" %d ",j);
            str2[k] = frase[j];
            k++;
    } 
    str2[k] ='\0'; 
   


   
   
    
     for( e=j+1; frase[e] != ' '; e++){
        printf(" %d ",t);
            str3[y] = frase[e];
            y++;
    }  
    str3[y] = '\0';
    
    for( b=e+1; frase[b] != '\0'; b++){
            str4[z] = frase[b];
          z++;
    }

}

    
    


    l = strlen(str1);
    printf("\n str1 \n");
    for(int u=0; str1[u] != '\0'; u++)
        printf(" %c",str1[u]);
    printf("\n Tam: %d \n",l);


    printf("\n ----- \n");


    l1 = strlen(str2);
    printf("\n str2 \n");
    for(int u=0; str2[u] != '\0'; u++)
        printf(" %c",str2[u]);
    printf("\n Tam: %d \n",l1); 

      l2 = strlen(str3);
    printf("\n str3 \n");
    for(int u=0; str3[u] != '\0'; u++)
        printf(" %c",str3[u]);
     printf("\n Tam: %d \n",l2); 

     l3 = strlen(str4);
    printf("\n str4 \n");
    for(int u=0; str4[u] != '\0'; u++)
        printf(" %c",str4[u]);
     printf("\n Tam: %d \n",l3); 

    

}


int main(){

    char str[40];
    recebe(str);
    impri(str);
    analizador(str); 
    /*char x[20] = "um";
    char y[10] = {'d','o','i','s'};
    printf(" %s %s",x,y);

    printf(" \n ");
    

    for(int i=0; y[i] != '\0'; i++)
        printf(" %c",y[i]);

    strcpy(x,y);
    printf(" %s",x);  */

    


    return 0;
}