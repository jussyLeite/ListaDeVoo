#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"extensao.h"
#include"styles.c"
/*Estruturas  */
typedef struct Tpassageiro{
  char nome[30];
   char bi[30]; 
}passageiro;
passageiro pass;

typedef struct TlistaVoo{
   int iniListaVoo[TAMLISTA];
   int vooNumElem[TAMLISTA];
   int ultPos[TAMLISTA];

   int iniListaEspVoo[TAMLISTA];
   int vooNumEspElem[TAMLISTA];
   int ultPosEsp[TAMLISTA];

   passageiro pass;
} listaVoo;

typedef struct Tvoo{
    listaVoo listaVoo[MAX];
    listaVoo listaEsperaVoo[MAX];
    

    int ultPos[TAMLISTA];
    int ultPosEsp[TAMLISTA];
    
} voo;
voo p;

/*-----------------------------------------------------------------------------------
lineInsert Fuction: Entrada da frase por via teclado
Recebe:um conjuto de caracter, e ultimaPos
devolve: nada
----------------------------------------------------------------------------------- */
int lineInsert(char frase[], int ultPos){
    printf("Agencia-de-Voo@Agencia-de-Voo:");
    for(ultPos=0; ultPos < MAX; ultPos++)
      scanf("%[^\n]s",&frase[ultPos]);
      getchar();
    return ultPos;
}
/*-----------------------------------------------------------------------------------
comandAnalise Fuction: Verifica qual o comando foi inserido
Recebe: uma string
Retorna: O valor do comando
----------------------------------------------------------------------------------- */
int comandAnalise(char str[]){
    if((strcmp(str,"INC") == 0) || (strcmp(str,"inc") == 0))    return INC;
    if((strcmp(str,"REM") == 0) || (strcmp(str,"rem") == 0))    return REM;
    if((strcmp(str,"VEB") == 0) || (strcmp(str,"veb") == 0))    return VEB;
    if((strcmp(str,"VEN") == 0) || (strcmp(str,"ven") == 0))    return VEN;
    if((strcmp(str,"LIST") == 0) || (strcmp(str,"list") == 0))  return LIST;
    if((strcmp(str,"FIM") == 0) || (strcmp(str,"fim") == 0))    return FIM;
    if((strcmp(str,"CLS") == 0) || (strcmp(str,"cls") == 0))    return CLS;
    if((strcmp(str,"HELP") == 0) || (strcmp(str,"help") == 0))  return  HELP;
    else return INVALID_COMMAND;
}
/*-----------------------------------------------------------------------------------
space: Conta  o numero de espaco na frase
Recebe: uma string
Retorna: numero de espaços
----------------------------------------------------------------------------------- */
int space(char frase[]){
    int space=0;
    for(int o=0; frase[o] != '\0'; o++)
        {
          if(frase[o] == ' ')
            space+=1;
        }
    return space;
}
/*-----------------------------------------------------------------------------------
space: Conta  o numero de espaco na frase
Recebe: uma string
Retorna: numero de espaços
----------------------------------------------------------------------------------- */
int semantico(char frase[]){
    char str1[5], str2[20], str3[30], str4[30], str5[10], nomeCom[40];
    int i,j,y,z,t;
    int a,b,c,d,e,p=0;
    a = b = c = d = e = 0;
    if(space(frase) == 1){
        for( i=0; frase[i] != ' '; i++){
            str1[i] = frase[i];
            }
            str1[i] ='\0';

        for( j=i+1; frase[j] != '\0'; j++){
            str2[a] = frase[j];
            a++;
            }
            str2[a]='\0';      
            }
    else if(space(frase) == 4){
            for( i=0; frase[i] != ' '; i++){
                str1[i] = frase[i];
            }
            str1[i] ='\0';
            
            for( j=i+1; frase[j] != ' '; j++){
                    str2[a] = frase[j];
                    a++;
            } 
            str2[a] ='\0'; 
        
            for( y=j+1; frase[y] != ' '; y++){
                    str3[b] = frase[y];
                    b++;
            }  
            str3[b] = '\0';
            
            for( z=y+1; frase[z] != ' '; z++){
                    str4[c] = frase[z];
                c++;
            }
            str4[c] ='\0';
            //------------------------
            for(e=0; str3[e] != '\0'; e++)
                {
                    nomeCom[e] = str3[e];
                }
            nomeCom[e] = ' ';
            e+=1;
            for(p=0; str4[p] != '\0' ; p++)
            {
                nomeCom[e] = str4[p];
                e++;
            }
            nomeCom[e] = '\0';

            for( t=z+1; frase[t] != '\0'; t++){
                    str5[d] = frase[t];
                d++;
            }
            str5[d] ='\0';
            
    }else if(space(frase) == 2){
            for( i=0; frase[i] != ' '; i++){
                    str1[i] = frase[i];
            }
            str1[i] ='\0';

            for( j=i+1; frase[j] != ' '; j++){
                    str2[a] = frase[j];
                    a++;
            } 
            str2[a] ='\0'; 
            
            for( y=j+1; frase[y] != '\0'; y++){
                    str3[b] = frase[y];
                    b++;
            }  
            str3[b] = '\0';
            
    }else if(space(frase) == 0){
            for( i=0; frase[i] != ' '; i++){
                    str1[i] = frase[i];
                }
                str1[i] ='\0';
        }
    else return INVALID_COMMAND;
       return operacao(str1,str2,str3,str4,str5,nomeCom);
}

int operacao(char str1[],char str2[],char str3[],char str4[],char str5[],char nomeCom[]){
    int sucss, err, num;
    if(comandAnalise(str1) == FIM)
        return FIM;
    else if( comandAnalise(str1) == INVALID_COMMAND)
        errorMessage(comandAnalise(str1));
    else if(comandAnalise(str1) == CLS)
        system("clear");
    else if(comandAnalise(str1) == INC){
            sucss = incSet(str2,nomeCom,str5);
            if( sucss== OK)
                sucessMessage(sucss); 
            else if(sucss == NOT_SPACE)
            {
                sucss = inserirListaEspera(str2,nomeCom,str5);
                if(sucss == OK_ESP)
                sucessMessage(sucss); 
            }

        }
        else if(comandAnalise(str1) == VEN)
            ven(str2);
        else if(comandAnalise(str1) == REM){
            err = rem(str2, str3);
            if(err == NOT_FOUND)
                errorMessage(err);
            else if(err == REM_L)
                sucessMessage(err);
            else if(err == REM_E)
                sucessMessage(err);

        } 
    else if(comandAnalise(str1) == VEB)
              {
                err = veb(str2, str3); 
            if(err == NO_EXIST)
                errorMessage(err);
              }
    else if(comandAnalise(str1) == LIST)
    {
        sucss = list(str2);
        if(sucss == LIST_ISEMPTY)
            sucessMessage(sucss);
    }
    else if(comandAnalise(str1) == HELP)
        help();        

}

/*-----------------------------------------------------------------------------------
verificarNumVoo Fuction: 
Recebe:1 inteiro numero de voo
Retorna: O valor da verificação
----------------------------------------------------------------------------------- */
int verificaNumVoo(int numVoo){
    if(numVoo <= 0 || numVoo >= 13)
      return INVALID_VOO_N;
    else
        return OK;
}

/*-----------------------------------------------------------------------------------
messageError Fuction: 
Recebe:1 inteiro
devolve: mensagem de erro
----------------------------------------------------------------------------------- */
void errorMessage(int err){
    switch (err)
    {
    case INVALID_VOO_N:
        printf("\n Erro-Numero do voo Invalido! \n");
        break;
    case INVALIDE_NAME:
          printf("\n Erro-Nome Invalido! \n Nao pode conter no nome numeros ou caracters especiais! \n");
        break;
    case INVALIDE_BI:
          printf("\n Erro-BI Invalido! \n Nao pode conter no BI caracters especiais ou letras! \n");
        break;
    case INVALID_COMMAND:
          printf("\n Erro-Codigo operacao invalido!\n");
        break;
    case NOT_SPACE:
        printf("\n Erro-não há lugar disponível! \n");
        break; 
    case EXIST:
        printf("\n Erro-Passageiro ja esta na lista de voo! \n");
        break;
    case EQUAL_BI:
        printf("\n Erro –Bilhete de Identidade ja inserido! \n");
        break; 
    case EXIST_E:
        printf("\n Erro-Passageiro ja esta na lista de espera voo! \n");
        break;
    case EQUAL_BI_E:
        printf("\n Erro –Bilhete de Identidade ja inserido! \n");
        break; 
    case NOT_FOUND:
        printf("\n Erro – Passageiro não consta em nenhuma lista! \n");
        break;
    case NO_EXIST:
            printf("\n Erro – Bi inexistente ! \n");
        break;
    default:
        break;
    }
}
void sucessMessage(int succ){
    switch (succ)
    {
    case OK:
        printf("\n Passageiro incluído no voo! \n");
        break;
    case OK_ESP:
        printf("\n Passageiro na lista de espera! \n");
        break;
    case LIST_ISEMPTY:
        printf("\n Lista Esta Vazia! \n");
        break;
    case REM_L:
        printf("\n Passageiro removido da lista de voo!\n");
        break;
    case REM_E:
        printf("\n Passageiro removido do voo! \n");
        break;
    
    }
}
/*------------------------------------------------------------------------------------
verificaNome Fuction: Faz a validação do nome
Recebe:uma strings e o seu tamanho
retorna:o valor de retono OK ou INVALID_NAME
----------------------------------------------------------------------------------- */
int validarNome(char nome[]){
    char num[] ={'0','1','2','3','4','5','6','7','8','9'};
    char caraters[] ={'!','"','#','*','$','%','&','/','(','(',')','*','+','-','{','}'};
    int lenNome = strlen(nome);

    for(int i=0; i < lenNome; i++){
        for(int j=0; j < 10; j++)
            if(nome[i] == num[j]) return INVALIDE_NAME;
    }
    for(int i=0; i < lenNome; i++){
        for(int j=0; j < 17; j++)
            if(nome[i] == caraters[j]) return INVALIDE_NAME;
    }  
    return OK;   
}

int validarBi(char bi[]){
    char alfabeto[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char caraters[] ={'!','"','#','*','$','%','&','/','(','(',')','*','+','-','{','}'};
    char upper;
    int lenbi = strlen(bi);

    for(int i=0; i < lenbi; i++){ 
        for(int j=0; j < 26; j++){
            upper = toupper(alfabeto[j]);
            if((bi[i] == alfabeto[j]) || bi[i] == upper) return INVALIDE_BI;
        }
    }
    for(int i=0; i < lenbi; i++){
        for(int j=0; j < 16; j++)
            if(bi[i] == caraters[j]) return INVALIDE_BI;
    }  
    return OK;   
}
/*------------------------------------------------------------------------------------
INC Fuction: Inserir os dados dos passgeiros na lista de voo
Recebe:3 strings
retorna:Mensagem de error
----------------------------------------------------------------------------------- */
int incSet(char n_voo[],char nome[],char bi[]){
    int i=0,k=0,numVoo;
    numVoo = atoi(n_voo);

    if(verificaNumVoo(numVoo) == OK )
        if(validarNome(nome) == OK)
            if(validarBi(bi) == OK )
                {
                    i = numVoo;
                    i=i*5-4;
                    if(eh_existe(nome,bi) == NO_EXIST){
                        if(espacoVoo(numVoo,i) == OK) {    
                            if(p.listaVoo[i].vooNumElem[numVoo] < 1){
                                strcpy(p.listaVoo[i].pass.nome,nome);
                                strcpy(p.listaVoo[i].pass.bi,bi);
                                
                                p.listaVoo[i].vooNumElem[numVoo]=k+1;
                                p.listaVoo[i].iniListaVoo[numVoo]=i;
                                p.ultPos[numVoo]=i+1;
                                return OK;
                            }
                        else
                            {
                                strcpy(p.listaVoo[p.ultPos[numVoo]].pass.nome,nome);
                                strcpy(p.listaVoo[p.ultPos[numVoo]].pass.bi,bi);
                                p.listaVoo[i].vooNumElem[numVoo]++;
                                p.ultPos[numVoo]++;
                                return OK;
                            }
                }
                else {
                        return NOT_SPACE;
                }
            }else if(eh_existe(nome,bi) == EQUAL_BI)
                   {
                        errorMessage(eh_existe(nome,bi));
                        mostrarDados(bi);
                   }
            else
                errorMessage(eh_existe(nome,bi));  
                }
         else
           errorMessage(validarBi(bi));
    else 
        errorMessage(validarNome(nome));
else 
   errorMessage(verificaNumVoo(numVoo));
        
}
/*------------------------------------------------------------------------------------
inserirListaEspera Fuction: Inserir os dados dos passgeiros na lista de espera
Recebe:3 strings
retorna:Mensagem de error
----------------------------------------------------------------------------------- */
int inserirListaEspera(char n_voo[],char nome[],char bi[]){
    int i=0,numVoo;
    numVoo = atoi(n_voo);
    if(verificaNumVoo(numVoo) == OK )
        if( validarNome(nome) == OK)
            if( validarBi(bi) == OK )
                {
                    i = numVoo;
                    i=i*5-4;
                    if(eh_existeEsp(nome,bi) == NO_EXIST_E && eh_existe(nome,bi) == NO_EXIST){   
                     if(espacoEspVoo(numVoo,i) == OK) {   
                        if(p.listaEsperaVoo[i].vooNumEspElem[numVoo] < 1){
                            strcpy(p.listaEsperaVoo[i].pass.nome,nome);
                            strcpy(p.listaEsperaVoo[i].pass.bi,bi);

                            p.listaEsperaVoo[i].vooNumEspElem[numVoo]++;
                            p.listaEsperaVoo[i].iniListaEspVoo[numVoo]=i;
                            p.ultPosEsp[numVoo]=i+1;
                            return OK_ESP;  
                        }
                    else
                        {
                            strcpy(p.listaEsperaVoo[p.ultPosEsp[numVoo]].pass.nome,nome);
                            strcpy(p.listaEsperaVoo[p.ultPosEsp[numVoo]].pass.bi,bi);
                            
                            p.listaEsperaVoo[i].vooNumEspElem[numVoo]++;
                            p.ultPosEsp[numVoo]++;
                            return OK_ESP;
                        }
                     }
                     else
                            errorMessage(espacoEspVoo(numVoo,i));
                 
                }
               else if(eh_existeEsp(nome,bi) == EQUAL_BI_E){
                        errorMessage(eh_existeEsp(nome,bi));
                        mostrarDados(bi);
                }
                else
                        errorMessage(eh_existeEsp(nome,bi));
                }   

         else
           errorMessage(validarBi(bi));
    else 
        errorMessage(validarNome(nome));
else 
   errorMessage(verificaNumVoo(numVoo));
        
}
/*------------------------------------------
-----------------------------------------*/
int espacoVoo(int numVoo, int i){
    if(p.listaVoo[i].vooNumElem[numVoo] == 5){
        return NOT_SPACE;
    }
    else{
        return OK;
    }
}
int espacoEspVoo(int numVoo, int i){
    if(p.listaEsperaVoo[i].vooNumEspElem[numVoo] == 5)
        return NOT_SPACE;
    else
        return OK;
}
/*------------------------------------------------------------------------------------
isEmpty: Verifica se a lista de voo esta vazia
Recebe:numero de voo,e posicao
retorna:TRUE OU FALSE
----------------------------------------------------------------------------------- */
Boolean isEmpty(int voo, int i){
    return (p.listaVoo[i].vooNumElem[voo] == 0);
}
/*------------------------------------------------------------------------------------
isEmpty: Verifica se a lista de espera esta vazia
Recebe:numero de voo,e posicao
retorna:TRUE OU FALSE
----------------------------------------------------------------------------------- */
Boolean isEmptyE(int voo, int i){
    return (p.listaEsperaVoo[i].vooNumEspElem[voo] == 0);
}
/*------------------------------------------------------------------------------------
eh_existe: Verifica se é existe um nome ou bi na lista de voo 
Recebe:o nome e bi
retorna:mensagem de error ou sucess
----------------------------------------------------------------------------------- */
int eh_existe(char nome[], char bi[]){
     for(int j=0; j < MAX; j++){
         if(strcmp(nome,p.listaVoo[j].pass.nome) == 0) return EXIST;
        else if(strcmp(bi,p.listaVoo[j].pass.bi) == 0) return EQUAL_BI;      
     }
    return NO_EXIST;
} 
/*------------------------------------------------------------------------------------
eh_existeEsp: Verifica se existe um nome ou bi na lista de espera 
Recebe:o nome e bi
retorna:mensagem de error ou sucess
----------------------------------------------------------------------------------- */
int eh_existeEsp(char nome[], char bi[]){
     for(int j=0; j < MAX; j++){
         if(strcmp(nome,p.listaEsperaVoo[j].pass.nome) == 0) return EXIST_E;
        else if(strcmp(bi,p.listaEsperaVoo[j].pass.bi) == 0) return EQUAL_BI_E;    
     }
    return NO_EXIST_E;
} 
/*------------------------------------------------------------------------------------
existe: Verifica se existe um bi em uma lista de voo especifica 
Recebe:bi e numero de voo
retorna:mensagem de error ou sucess
----------------------------------------------------------------------------------- */
int existe(char bi[], int n_voo){
    int tam=n_voo;
    for(int j=n_voo*5-4; j <= tam*5; j++)
        if(strcmp(bi,p.listaVoo[j].pass.bi) == 0) return OK;
    
    return NO_EXIST;
}
/*------------------------------------------------------------------------------------
existeEsp: Verifica se existe um bi em uma lista de espera especifica 
Recebe:bi e numero de voo
retorna:mensagem de error ou sucess
----------------------------------------------------------------------------------- */
int existeEsp(char bi[], int n_voo){
    int tam=n_voo;
    for(int j=n_voo*5-4; j <= tam*5; j++)
        if(strcmp(bi,p.listaEsperaVoo[j].pass.bi) == 0) return OK;

    return NO_EXIST_E;
}
/*------------------------------------------------------------------------------------
veb: Mostra os dados de um passageiro cujo o bi seja igual ao inserido
Recebe:num de voo, bi
Devolve:dado do passageiro
Retorna: messagem de sucess
----------------------------------------------------------------------------------- */
int veb(char voo[], char bi[]){
    int n_voo = atoi(voo),tam = n_voo;
    if(verificaNumVoo(n_voo) == OK)
      if(validarBi(voo) == OK)
        if(validarBi(bi) == OK){
            for(int i=n_voo*5-4; i <= tam*5; i++){
                if( strcmp(bi,p.listaVoo[i].pass.bi) == 0)
                    {
                        style4();
                        printf("\n %s  \t\t\t\t\t  %s  \t\t\t\t Lista de Voo# \n",p.listaVoo[i].pass.nome, p.listaVoo[i].pass.bi);
                        return OK;
                    }
                    else if(strcmp(bi,p.listaEsperaVoo[i].pass.bi) == 0)
                    {
                        style4();
                        printf("\n %s  \t\t\t\t\t  %s  \t\t\t\t Lista de Espera* \n",p.listaEsperaVoo[i].pass.nome, p.listaEsperaVoo[i].pass.bi);
                        return OK;       
                    }             
                }
                    return NO_EXIST;
        }
        else
           errorMessage(validarBi(bi));
    else
        errorMessage(validarBi(voo));
    else
        errorMessage(verificaNumVoo(n_voo));

}
void mostrarDados(char bi[]){
    for(int i=1; i <= MAX; i++){
        if(strcmp(bi,p.listaVoo[i].pass.bi) == 0){
                style4();
                printf("\n %s  \t\t\t\t\t  %s  \t\t\t\t Lista de Voo# \n",p.listaVoo[i].pass.nome, p.listaVoo[i].pass.bi);
                break;
        }
        else if(strcmp(bi,p.listaEsperaVoo[i].pass.bi) == 0){
                style4();
                printf("\n %s  \t\t\t\t\t  %s  \t\t\t\t Lista de Espera* \n",p.listaEsperaVoo[i].pass.nome, p.listaEsperaVoo[i].pass.bi);
                break;       
           }
    }             
}

/*------------------------------------------------------------------------------------
sequencilaSort: Ordena os passageiros por ordem alfabetica
Recebe:num de voo
Devolve: Nada
----------------------------------------------------------------------------------- */
void sequencialSort(int n_voo){
    char auxN[40], auxB[10];
    int tam=0;
    tam=n_voo;
    for(int i=n_voo*5-4; i < p.ultPos[tam]; i++){
        for(int j=i+1; j < p.ultPos[n_voo]; j++)
        {
            if(p.listaVoo[i].pass.nome[0] > p.listaVoo[j].pass.nome[0]){
                strcpy(auxN,p.listaVoo[i].pass.nome);
                strcpy(auxB,p.listaVoo[i].pass.bi); 
                
                strcpy(p.listaVoo[i].pass.nome,p.listaVoo[j].pass.nome);
                strcpy(p.listaVoo[i].pass.bi,p.listaVoo[j].pass.bi);

                strcpy(p.listaVoo[j].pass.nome,auxN);
                strcpy(p.listaVoo[j].pass.bi,auxB); 
            } 
        }
    }
}
/*------------------------------------------------------------------------------------
list: Lista os dados  dos pasaageiros de uma lista especifica, de forma ordenada 
Recebe:num de voo
Devolve:dado do passageiro
Retorna: messagem de sucess
----------------------------------------------------------------------------------- */
int list(char voo[]){
    int v_voo,n_voo = atoi(voo),tam = n_voo;
    int j = n_voo*5-4;
    if(verificaNumVoo(n_voo) == OK){
        style1(n_voo);
    if(isEmpty(n_voo,p.listaVoo[j].iniListaVoo[n_voo])) return LIST_ISEMPTY;
    else{
            sequencialSort(n_voo);
            for(int i=n_voo*5-4; i < p.ultPos[tam]; i++)
                printf("\n \t  %s  \t\t %s\n",p.listaVoo[i].pass.nome,p.listaVoo[i].pass.bi);
        }
        style2(n_voo);
    if(isEmptyE(n_voo,p.listaEsperaVoo[j].iniListaEspVoo[n_voo])) return LIST_ISEMPTY;
    else{
            for(int i=n_voo*5-4; i < p.ultPosEsp[tam]; i++)
                printf("\n \t  %s  \t\t %s\n",p.listaEsperaVoo[i].pass.nome,p.listaEsperaVoo[i].pass.bi);              
            style3(); 
        }
        return OK;
    }
    else
        errorMessage(verificaNumVoo(n_voo));         
}
/*------------------------------------------------------------------------------------
ven: Mostra os dados de todos passageiros cujo o primeiro nome seja igual a nome inserido
Recebe:nome
Devolve:dados dos passageiros
Retorna: messagem de sucess
----------------------------------------------------------------------------------- */
int ven(char nome[]){
    int cont=0,cont2=0,lenNome=0;
    
    for(int i=0; nome[i] != '\0'; i++)
        lenNome++;

   style4();
   for(int j=1; j <= MAX; j++){
        for(int i=0; nome[i] == p.listaVoo[j].pass.nome[i] && p.listaVoo[j].pass.nome[i] != ' '; i++){
            cont++;
    }
    if(cont == lenNome)
        printf("\n  %s  \t\t\t\t%s    \t\t\t Lista de Voo#\n",p.listaVoo[j].pass.nome,p.listaVoo[j].pass.bi);
       
    cont = 0;
    } 

    for(int j=1; j <= MAX; j++){
        for(int i=0; nome[i] == p.listaEsperaVoo[j].pass.nome[i] && p.listaEsperaVoo[j].pass.nome[i] != ' '; i++){
            cont2++;
    }
    if(cont2 == lenNome)
        printf("\n  %s  \t\t\t\t %s    \t\t\t Lista de Espera*\n",p.listaEsperaVoo[j].pass.nome,p.listaEsperaVoo[j].pass.bi);
    cont2 = 0;
    } 
    lenNome=0;
    return OK;

}
/*------------------------------------------------------------------------------------
rem: remove um passageiro da lista de espera ou de voo
Recebe:num de voo, bi
Retorna: messagem de sucess
----------------------------------------------------------------------------------- */
int rem(char voo[], char bi[]){
    int n_voo = atoi(voo), tam = n_voo,y=n_voo*5-4,i,j,k,t = p.listaVoo[y].vooNumElem[tam],t1 = p.listaEsperaVoo[y].vooNumEspElem[tam];
    char aux[30], aux2[40];
    
    if(verificaNumVoo(n_voo) == OK){
        for(i=n_voo*5-4; i <= tam*5; i++){
            if(existe(bi,n_voo) == OK){
                if(strcmp(bi,p.listaVoo[i].pass.bi) == 0){
                    strcpy(aux,p.listaVoo[i].pass.nome);
                    strcpy(aux,p.listaVoo[i].pass.bi);

                    p.listaVoo[y].vooNumElem[tam] =t-1;
                    p.ultPos[tam]--;
                
                    for(k=i; k <= tam*5; k++){
                        strcpy(p.listaVoo[k].pass.nome,p.listaVoo[k+1].pass.nome);
                        strcpy(p.listaVoo[k].pass.bi,p.listaVoo[k+1].pass.bi);
                    }
                    if(!isEmptyE(n_voo,p.listaEsperaVoo[y].iniListaEspVoo[n_voo])){
                        incSet(voo,p.listaEsperaVoo[y].pass.nome,p.listaEsperaVoo[y].pass.bi);
            
                        strcpy(aux2,p.listaEsperaVoo[y].pass.nome);
                        strcpy(aux2,p.listaEsperaVoo[y].pass.bi);

                        p.listaEsperaVoo[y].vooNumEspElem[tam] =t1-1;
                        p.ultPosEsp[tam]--;

                        for(; y <= tam*5; y++){
                            strcpy(p.listaEsperaVoo[y].pass.nome,p.listaEsperaVoo[y+1].pass.nome);
                            strcpy(p.listaEsperaVoo[y].pass.bi,p.listaEsperaVoo[y+1].pass.bi); 
                        } 
                    }
                    return REM_L; 
                }
            }
            else if(existeEsp(bi,n_voo) == OK){
                    strcpy(aux2,p.listaEsperaVoo[y].pass.nome);
                    strcpy(aux2,p.listaEsperaVoo[y].pass.bi);

                    p.listaEsperaVoo[y].vooNumEspElem[tam] =t1-1;
                    p.ultPosEsp[tam]--;

                    for(; y <= tam*5; y++){
                        strcpy(p.listaEsperaVoo[y].pass.nome,p.listaEsperaVoo[y+1].pass.nome);
                        strcpy(p.listaEsperaVoo[y].pass.bi,p.listaEsperaVoo[y+1].pass.bi);
                    }
                return REM_E; 
            }
        }
        return NOT_FOUND;
    }
    else
        errorMessage(verificaNumVoo(n_voo));
}

void imprimirListas(){
    int n=1;
    for( int i = n*5-4; i <= TAMLISTA; i++)
        {
            style1(n);
            
                for(int i= n*5-4; i < p.ultPos[n]; i++)
              {
                printf("\n  %s  \t\t\t\t%s    \t\n",p.listaVoo[i].pass.nome,p.listaVoo[i].pass.bi);
              }
              style2(n);
              
              for(int i= n*5-4; i < p.ultPosEsp[n]; i++)
              {
                printf("\n  %s  \t\t\t\t%s    \t\n",p.listaEsperaVoo[i].pass.nome,p.listaEsperaVoo[i].pass.bi);
              }
              n += 1;
        
         }        
    }  
/*------------------------------------------------------------------------------------
preMain: Mostra os dados de um passageiro cujo o bi seja igual ao inserido
----------------------------------------------------------------------------------- */
void preMain(){
    char str[MAX];
    int t;
    do{
        lineInsert(str,0);
        t = semantico(str);
     }while(t != FIM);
     imprimirListas();        
}
