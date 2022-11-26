#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500 //numero maximo de livros que odem ser guardados

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
        printf("Insira o opcao que pretende realizar:\n");
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
                break;

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

        printf("Insira o tipo de publicacao: ");
        fflush(stdin);
        fgets(livro_inserido.tipo, 20, stdin);
        livro_inserido.tipo[strcspn(livro_inserido.tipo, "\n")] = 0;
        printf("\n");

        printf("Insira o nome do autor: ");
        fflush(stdin);
        fgets(livro_inserido.nome_completo, 20, stdin);
        livro_inserido.nome_completo[strcspn(livro_inserido.nome_completo, "\n")] = 0;
        printf("\n");

        printf("Insira o ano de publicacao: ");
        fflush(stdin);
        scanf("%d", &livro_inserido.ano_pub);
        printf("\n");

        printf("Insira o local de publicacao: ");
        fflush(stdin);
        fgets(livro_inserido.local_pub, 20, stdin);
        livro_inserido.local_pub[strcspn(livro_inserido.local_pub, "\n")] = 0;
        printf("\n");

        printf("Insira o numero de paginas: ");
        fflush(stdin);
        scanf("%d", &livro_inserido.num_pag);
        printf("\n");

        printf("Insira o endereco HTTP: ");
        fflush(stdin);
        fgets(livro_inserido.endereco, 20, stdin);
        livro_inserido.endereco[strcspn(livro_inserido.endereco, "\n")] = 0;
        printf("\n");

        livros[n] = livro_inserido ;
        printf("Livro guardado com o codigo %d\n", n+1);
        n++;
        
        
        for(int i=0; i<1; i++){

            printf("Pretende inserir informacoes para mais um livro?\n");
            printf("S - Sim | N - Nao\n");
            scanf(" %c", &sair);

            switch (sair){
                case 'n':
                    printf("De volta para o menu!!\n\n");
                    i++;
                    break;

                case 'N':
                    printf("De volta para o menu!!\n\n");
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
        printf("Livro: %s | Codigo : %d\n",livros[i].nome, i+1);
    } // mostra os codigos de todos os livros
    system("pause");
}

void editar(){
    referencias_biblio info;
    referencias_biblio edits;
    int cod=0, edit=0;

        printf("Insira o codigo do livro do qual pretende editar informacao (0 para sair): ");
        scanf("%d", &cod);
        if (cod == 0){
            printf("Saiu com sucesso!!");
        }else {
            for (int i = 0; i < 1; ++i) {
                info = livros[cod-1];
                    printf("O que pretende editar?\n");
                    printf("1 - Nome do livro (Atual: %s)\n", info.nome);
                    printf("2 - Tipo de publicacao (Atual: %s)\n", info.tipo);
                    printf("3 - Autores (Atual: %s)\n", info.nome_completo);
                    printf("4 - Ano de publicacao (Atual: %d) \n",  *(info.ano_pub));
                    printf("5 - Local de publicacao (Atual: %s)\n", info.local_pub);
                    printf("6 - Numero de paginas (Atual: %d) \n",  *(info.num_pag));
                    printf("7 - Endereco HTTP (Atual: %s)\n", info.endereco);
                    printf("9 - utilizar outro codigo (editar outro livro)\n");
                    printf("0 - Sair\n");
                    scanf("%d", &edit);
            
                switch (edit) {
                    case 1:
                        printf("Edite o nome do livro (Nome atual: %s):", info.nome);
                        fflush(stdin);
                        fgets(edits.nome, 20, stdin);
                        edits.nome[strcspn(edits.nome, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 2:
                        printf("Edite o tipo de publicação (Tipo atual: %s): ", info.tipo);
                        fflush(stdin);
                        fgets(edits.tipo, 20, stdin);
                        edits.tipo[strcspn(edits.tipo, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 3:
                        printf("Insira o nome do autor (Atual: %s): ", info.nome_completo);
                        fflush(stdin);
                        fgets(edits.nome_completo, 20, stdin);
                        edits.nome_completo[strcspn(edits.nome_completo, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 4:
                        printf("Insira o ano de publicação (Atual: %d): ", info.ano_pub);
                        fflush(stdin);
                        scanf("%d", &edits.ano_pub);
                        printf("\n");
                        i--;
                        break;

                    case 5:
                        printf("Insira o local de publicação (Atual: %s): ", info.local_pub);
                        fflush(stdin);
                        fgets(edits.local_pub, 20, stdin);
                        edits.local_pub[strcspn(edits.local_pub, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 6:
                        printf("Insira o numero de paginas (Atual: %d): ", info.num_pag);
                        fflush(stdin);
                        scanf("%d", &edits.num_pag);
                        printf("\n");
                        i--;
                        break;

                    case 7:
                        printf("Insira o endereco HTTP (Atual: %s): ", info.endereco);
                        fflush(stdin);
                        fgets(edits.endereco, 20, stdin);
                        edits.endereco[strcspn(edits.endereco, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 9:
                        printf("Novo codigo (Atual: %d): ", cod);
                        scanf("%d", &cod);
                        i--;
                        break;


                    case 0:
                        printf("Saiu com sucesso!!\n");
                        i++;
                        break;

                    default:
                        printf("Opcao inserida invalida!!");
                        i--;

                        livros[cod-1]=edits ;
            }
        }
    }
}

void mostrar(){
    int i=0;
    for (i = 0; i < 1; ++i) {

    }
}