#ifndef LISTA_SEQUENCIAL_
#define LISTA_SEQUENCIAL_

/*----- SET COMMANDS LINE*/
#define OK                  1 
#define OK_ESP              0 
#define INC                 2  
#define REM                 3
#define VEB                 4
#define VEN                 5
#define LIST                6
#define FIM                 7
#define CLS                 8
#define HELP                9
#define INVALID_COMMAND    -1
#define INVALID_VOO_N      -2 
#define INVALIDE_NAME      -3
#define INVALIDE_BI        -4
#define NOT_SPACE          -5
#define EXIST              -6
#define NO_EXIST           -7
#define EQUAL_BI           -8
#define EXIST_E            -9
#define NO_EXIST_E         -10
#define EQUAL_BI_E         -11
#define NOT_FOUND          -12
#define LIST_ISEMPTY       -13
#define REM_L              -14
#define REM_E              -15
#define MAX 60
#define TAM 30
#define TAMLISTA 12


/*  ESTRUTURAS */
typedef struct Tvoo voo;
typedef enum { FALSE =0, TRUE=1} Boolean;

/*------
PROTOTICOS DE FUNCOES
----*/
int lineInsert(char frase[], int ultPos);
int incSet(char n_voo[],char nomeP[],char bi[]); 
int comandAnalise(char  str[]);
int space(char frase[]);
int semantico(char frase[]);
int operacao(char str1[],char str2[],char str3[],char str4[],char str5[],char nomeCom[]);
int verificaNumVoo(int numVoo);
void errorMessage(int err);
void sucessMessage(int succ);
int validarNome(char nome[]);
int validarBi(char bi[]);
int espacoVoo(int numVoo, int i);
int espacoEspVoo(int numVoo, int i);
int inserirListaEspera(char n_voo[],char nome[],char bi[]);
int eh_existe(char nome[], char bi[]);
int eh_existeEsp(char nome[], char bi[]);
int list(char voo[]);
void mostrarDados(char bi[]);
int rem(char voo[], char bi[]);
int veb(char voo[], char bi[]);
int ven(char nome[]);
void sequencialSort(int voo);
void imprimirListas();
int existe(char bi[], int n_voo);
int existeEsp(char bi[], int n_voo);
void preMain();

#endif