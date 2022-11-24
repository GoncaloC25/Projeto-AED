#include <stdio.h>
#include <string.h>
#define MAX 500

int n=0;

typedef struct{
    char nome[50];
    char tipo[30];
    char nome_completo[100];
    int ano_pub[4];
    char local_pub[100];
    int num_pag[5];
    char endereco[100];
    char pal_chave[][30];
}referencias_biblio;

referencias_biblio livros[MAX];


void inserir();
void codigos();
void editar();
void mostrar();
//void eliminar();

int main() {
    int opcao=-1;
    for (int i=0; i<1; i++){
        printf("Insira o opção que pretende realizar:\n");
        printf("1 - Inserir informacao\n");
        printf("2 - Mostrar codigos\n");
        printf("3 - Editar informacao\n");
        printf("4 - Mostrar informacao\n");
        printf("5 - Eliminar informcao\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                inserir();
                i--;
                break;
                
            case 2:
                codigos();
                i--;
                break;

            case 3:
                editar();
                i--;
                break;

            case 4:
                mostrar();
                i--;
                break;


/*
case 5:
    eliminar();
    i--;
    break;
*/
            case 0:
                printf("Saiu com sucesso!!");

            default:
                printf("Erro: Opcao inserida nao existe, tente novamente!!\n");
                i--;
                break;
        }
    }
}
void inserir(){
    referencias_biblio livro_inserido;
    char sair='S';

    while (sair=='S'||sair=='s'){

        printf("Insira o nome do livro: ");
        fflush(stdin);
        fgets(livro_inserido.nome, 20, stdin);
        livro_inserido.nome[strcspn(livro_inserido.nome, "\n")] = 0;
        printf("\n");

        printf("Insira o tipo de publicação: ");
        fflush(stdin);
        fgets(livro_inserido.tipo, 20, stdin);
        livro_inserido.tipo[strcspn(livro_inserido.tipo, "\n")] = 0;
        printf("\n");

        printf("Insira o nome do autor: ");
        fflush(stdin);
        fgets(livro_inserido.nome_completo, 20, stdin);
        livro_inserido.nome_completo[strcspn(livro_inserido.nome_completo, "\n")] = 0;
        printf("\n");

        printf("Insira o ano de publicação: ");
        fflush(stdin);
        scanf("%d", &livro_inserido.ano_pub);
        printf("\n");

        printf("Insira o local de publicação: ");
        fflush(stdin);
        fgets(livro_inserido.local_pub, 20, stdin);
        livro_inserido.local_pub[strcspn(livro_inserido.local_pub, "\n")] = 0;
        printf("\n");

        printf("Insira o numero de paginas: ");
        fflush(stdin);
        scanf("%d", &livro_inserido.num_pag);
        printf("\n");

        printf("Insira o endereço HTTP: ");
        fflush(stdin);
        fgets(livro_inserido.endereco, 20, stdin);
        livro_inserido.endereco[strcspn(livro_inserido.endereco, "\n")] = 0;
        printf("\n");
        
        livro_inserido = livros[n];
        n++;
        printf("Livro guardado com o codigo %d", n+1);
        
        for(int i=0; i<1; i++){

            printf("Pretende inserir informações para mais um livro?\n");
            printf("S - Sim | N - Nao\n");
            scanf(" %c", &sair);

            switch (sair){
                case 'n':
                    printf("De volta para o menu!!");
                    i++;
                    break;

                case 'N':
                    printf("De volta para o menu!!");
                    i++;
                    break;

                default:
                    break;
            }

        }

    }
}

void codigos(){
    int i;

    for (i = 0; i < n; ++i) {
        printf("Livro: %c | Codigo : %d", livros[i].nome, i+1);    
    }
}

void editar(){
    int cod=0;
    for (int i = 0; i < 1; ++i) {
        printf("Insira o codigo do livro do qual pretende editar informacao (0 para sair): ");
        scanf("%d", &cod);
        
        if (cod == 0){
            printf("Saiu com sucesso!!");
            i++;
        }else {
            printf("Insira o nome do livro: ");
            fflush(stdin);
            fgets(livros[cod].nome, 20, stdin);
            livros[cod].nome[strcspn(livros[cod].nome, "\n")] = 0;
            printf("\n");

            printf("Insira o tipo de publicação: ");
            fflush(stdin);
            fgets(livros[cod].tipo, 20, stdin);
            livros[cod].tipo[strcspn(livros[cod].tipo, "\n")] = 0;
            printf("\n");

            printf("Insira o nome do autor: ");
            fflush(stdin);
            fgets(livros[cod].nome_completo, 20, stdin);
            livros[cod].nome_completo[strcspn(livros[cod].nome_completo, "\n")] = 0;
            printf("\n");

            printf("Insira o ano de publicação: ");
            fflush(stdin);
            scanf("%d", &livros[cod].ano_pub);
            printf("\n");

            printf("Insira o local de publicação: ");
            fflush(stdin);
            fgets(livros[cod].local_pub, 20, stdin);
            livros[cod].local_pub[strcspn(livros[cod].local_pub, "\n")] = 0;
            printf("\n");

            printf("Insira o numero de paginas: ");
            fflush(stdin);
            scanf("%d", &livros[cod].num_pag);
            printf("\n");

            printf("Insira o endereço HTTP: ");
            fflush(stdin);
            fgets(livros[cod].endereco, 20, stdin);
            livros[cod].endereco[strcspn(livros[cod].endereco, "\n")] = 0;
            printf("\n");
            
        }
    }
}

void mostrar(){
    int i=0;
    for (i = 0; i < 1; ++i) {
    
    }
}