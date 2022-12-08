#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 500 //numero maximo de livros que odem ser guardados
#define AUT 200 //numero maximo de autores

int n=0;
int nta=0;

typedef struct{
    char nome[50];
    char tipo[30];
    char nome_completo[100];
    int ano_pub[4];
    char local_pub[100];
    char nomes_aut[400];
    int num_pag[5];
    char endereco[100];
    char pal_chave[][30];
}referencias_biblio;

typedef struct{
   char nome_prpio[20];
   char apelido[50];
   char nome_completo[70];
   int n_livros;
}autores_diff;

referencias_biblio livros[MAX];
autores_diff autores_dif[AUT];


void inserir();         // a funcionar
void codigos();         // a funcionar
void editar();          // a funcionar
void eliminar();        // a funcionar

void listar_menu();     // a funcionar
void listar_tudo();     // a funcionar
void inserir_aut(int cod);     //
void listar_autores();  // ??

void stats_menu();      //
void total_pub();
void total_aut();
void total_palchave();
void total_pag();
void media_pag();



int main() {

    int opcao=-1;
    for (int i=0; i<1; i++){
        printf("\nInsira a opcao que pretende realizar:\n");
        printf("1 - Inserir informacao\n");
        printf("2 - Mostrar codigos\n");
        printf("3 - Editar informacao\n");
        printf("4 - Mostrar informacao\n");
        printf("5 - Eliminar informcao\n");
        printf("0 - Sair\n");
        fflush(stdin);
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
                listar_menu();
                i--;
                break;

            case 5:
                eliminar();
                i--;
                break;

            case 0:
                printf("\nSaiu com sucesso!!");
                break;

            default:
                printf("\nErro: Opcao inserida nao existe, tente novamente!!\n");
                i--;
                break;
        }
    }
}

void inserir(){
    referencias_biblio livro_inserido;
    char sair='S';
    int num_palchave=0;
    int cod = n+1;

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

        inserir_aut(cod-1);

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

       /* printf("Insira o numero de palavra-chave que vai inserir: ");
        scanf("%d", &num_palchave);
        printf("\n");
        for(int i=0; i<num_palchave; i++){
            fflush(stdin);
            printf("&d Palavra-Chave: ", i+1);
            fgets(&(livro_inserido.pal_chave[i][30]), 30,stdin);
            livro_inserido.pal_chave[strcspn(livro_inserido.pal_chave[i], "\n")] = 0;
            printf("\n");
        }*/

        livros[n] = livro_inserido ;
        printf("Livro guardado com o codigo %d\n", n+1);
        n++;


        for(int i=0; i<1; i++){

            printf("\nPretende inserir informacoes para mais um livro?\n");
            printf("S - Sim | N - Nao\n");
            scanf(" %c", &sair);

            switch (sair){
                case 'n':
                    printf("\nDe volta para o menu!!\n\n");
                    i++;
                    break;

                case 'N':
                    printf("\nDe volta para o menu!!\n\n");
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
        printf("\nLivro: %s | Codigo : %d\n",livros[i].nome, i+1);
    } // mostra os codigos de todos os livros
    system("pause");
}

void editar(){
    referencias_biblio info;
    int cod=0, edit=0;

        printf("\nInsira o codigo do livro do qual pretende editar informacao (0 para sair): ");
        scanf("%d", &cod);
        if (cod == 0){
            printf("\nSaiu com sucesso!!");
        }else {
            for (int i = 0; i < 1; ++i) {
                info = livros[cod-1];
                    printf("\nO que pretende editar?\n");
                    printf("1 - Nome do livro (Atual: %s)\n", info.nome);
                    printf("2 - Tipo de publicacao (Atual: %s)\n", info.tipo);
                    printf("3 - Autores (Atual: %s)\n", info.nome_completo);
                    printf("4 - Ano de publicacao (Atual: %d) \n",  *(info.ano_pub));
                    printf("5 - Local de publicacao (Atual: %s)\n", info.local_pub);
                    printf("6 - Numero de paginas (Atual: %d) \n",  *(info.num_pag));
                    printf("7 - Endereco HTTP (Atual: %s)\n", info.endereco);
                    printf("9 - Utilizar outro codigo (editar outro livro)\n");
                    printf("0 - Sair\n");
                    scanf("%d", &edit);

                switch (edit) {
                    case 1:
                        printf("Edite o nome do livro (Nome atual: %s):", info.nome);
                        fflush(stdin);
                        fgets(livros[cod-1].nome, 20, stdin);
                        livros[cod-1].nome[strcspn(livros[cod-1].nome, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 2:
                        printf("Edite o tipo de publicação (Tipo atual: %s): ", info.tipo);
                        fflush(stdin);
                        fgets(livros[cod-1].tipo, 20, stdin);
                        livros[cod-1].tipo[strcspn(livros[cod-1].tipo, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 3:
                        printf("Insira o nome do autor (Atual: %s): ", info.nome_completo);
                        fflush(stdin);
                        fgets(livros[cod-1].nome_completo, 20, stdin);
                        livros[cod-1].nome_completo[strcspn(livros[cod-1].nome_completo, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 4:
                        printf("Insira o ano de publicacao (Atual: %d): ", *(info.ano_pub));
                        fflush(stdin);
                        scanf("%d", &(livros[cod-1].ano_pub));
                        printf("\n");
                        i--;
                        break;

                    case 5:
                        printf("Insira o local de publicação (Atual: %s): ", info.local_pub);
                        fflush(stdin);
                        fgets(livros[cod-1].local_pub, 20, stdin);
                        livros[cod-1].local_pub[strcspn(livros[cod-1].local_pub, "\n")] = 0;
                        printf("\n");
                        i--;
                        break;

                    case 6:
                        printf("Insira o numero de paginas (Atual: %d): ", (*info.num_pag));
                        fflush(stdin);
                        scanf("%d", &(livros[cod-1].num_pag));
                        printf("\n");
                        i--;
                        break;

                    case 7:
                        printf("Insira o endereco HTTP (Atual: %s): ", info.endereco);
                        fflush(stdin);
                        fgets(livros[cod-1].endereco, 20, stdin);
                        livros[cod-1].endereco[strcspn(livros[cod-1].endereco, "\n")] = 0;
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


            }
        }
    }
}

void listar_tudo(){
    referencias_biblio lista;
    int i=0;
    int cod = 0;
    char sair;

    for(i=0; i<1; i++) {
        printf("\nIndique o codigo do livro que quer mostrar (0 para voltar ao menu anterior): ");
        scanf("%d", &cod);
        if(cod == 0){
            printf("\nSaiu com sucesso!!");
            i++;}
        else{
            lista = livros[cod - 1];
            printf("\nNome do livro: %s", lista.nome);
            printf("\nTipo de livro: %s", lista.tipo);
            printf("\nNome do autor: %s", lista.nomes_aut);
            printf("\nAno de publicacao: %d", *lista.ano_pub);
            printf("\nLocal de publicacao: %s", lista.local_pub);
            printf("\nNumero de paginas: %d", *lista.num_pag);
            printf("\nEndereco HTTP: %s\n\n", lista.endereco);


        printf("Pretende mostrar outro livro?\n");
        printf("S - Sim | N - Nao: ");
        fflush(stdin);
        scanf("%c", &sair);

        switch (sair) {
            case 'n':
                i++;
                printf("\nDe volta para o menu!!\n");
                break;
            case 'N':
                i++;
                printf("\nDe volta para o menu!!\n");
                break;
            case 'S':
                i--;
                break;
            case 's':
                i--;
                break;;
            default:
                printf("Opcao inserida invalida\n");
                i--;
            }
        }
    }
}

void eliminar(){
    int cod;
    for(int i = 0; i < 1; i++){
        printf("\nIndique o codigo do livro que quer eliminar(0 para sair): ");
        scanf("%d", &cod);
        if(cod == 0){
            printf("Saiu com sucesso!!\n");
            i++;}
        else{
            livros[cod -1] = livros[cod];
            printf("Eliminou o livro de codigo %d com sucesso!!\n", cod);
            n--;
            i++;
        }

    }

}

void listar_menu(){
    int opcao = -1;
    for(int i = 0; i<1; i++){
        printf("\n1 - Listar informacao toda de um livro\n");
        printf("2 - Listar autores\n");
        printf("3 - Listar publicacoes por autor\n");
        printf("4 - Listar publicacoes por tipo\n");
        printf("5 - Listar publicacoes por palavra-chave\n");
        printf("6 - Listar publicacoes por ano\n");
        printf("7 - Listar palavras-chave\n");
        printf("8 - Mostrar outras estatisticas\n");
        printf("0 - Sair\n");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Saiu com sucesso!!\n");
                i++;
                break;
            case 1:
                listar_tudo();
                i--;
                break;
            case 2:
                listar_autores();
                i--;
                break;

            case 8:
                stats_menu();
                i--;


        }
    }
}

void inserir_aut (int cod){
    autores_diff novo_aut;
    referencias_biblio  nome_aut;

    char ma='n', lnp='n', pesq_aut[60];
    int i, anl, igual;

    printf("Quantos autores tem este livro?: ");
    scanf("%d", &anl);
    if(anl>0 && anl<5){

        for (int k = 1; k <= anl ; ++k) {
            printf("Este autor tem algum livro registado no progrma?(S-Sim | N-Nao)\n");
            scanf(" %c", &lnp);
            if (lnp == 'n' || lnp == 'N') {
                for (i =0; i < 1; ++i) {
                    printf("Insira o nome proprio do/a autor/a: ");
                    fflush(stdin);
                    fgets(novo_aut.nome_prpio, 10, stdin);
                    novo_aut.nome_prpio[strcspn(novo_aut.nome_prpio, "\n")] = 0;
                    printf("\n");

                    printf("Insira o apelido do/a autor/a: ");
                    fflush(stdin);
                    fgets(novo_aut.apelido, 35, stdin);
                    novo_aut.apelido[strcspn(novo_aut.apelido, "\n")] = 0;
                    printf("\n");

                    strcat(novo_aut.nome_completo, novo_aut.nome_prpio);
                    strcat(novo_aut.nome_completo, novo_aut.apelido);
                    strcat(nome_aut.nomes_aut, novo_aut.nome_completo);
                    if(k != anl) {
                        strcat(nome_aut.nomes_aut, "; ");
                    }
                    novo_aut.n_livros = 1;
                    autores_dif[nta] = novo_aut;
                    livros[cod]=nome_aut;
                    nta++;
                }
            } else if (lnp == 's' || lnp == 'S') {
                char aut_transf[70];
                autores_diff lf_aut;
                printf("Insira o nome completo do autor: ");
                fflush(stdin);
                fgets(pesq_aut, 35, stdin);
                pesq_aut[strcspn(pesq_aut, "\n")] = 0;
                printf("\n");
                for (int pa = 0; pa < nta; ++pa) {
                    lf_aut = autores_dif[pa];
                    strcpy(aut_transf, lf_aut.nome_completo);
                    igual = strcmp(aut_transf, pesq_aut);
                    if(igual == 0){
                        printf("Autor encontrado!!!");
                        strcat(nome_aut.nomes_aut, lf_aut.nome_completo);
                        if(k != anl) {
                            strcat(nome_aut.nomes_aut, "; ");
                        }
                        pa=nta+1;
                        lf_aut.n_livros++;
                        livros[cod] = nome_aut;
                    }
                    if(pa==nta){
                        printf("Autor não encontrado!!\n");
                        printf("Insira Não ou tente outro nome!!\n");
                        k--;
                        system ("pause");
                    }
                }
            }
        }
    }
}


void listar_autores() {
    autores_diff list_aut;
    int i;
    for (i = 0; i < nta; i++){
        list_aut=autores_dif[i];
        printf("%s\n", list_aut.nome_completo);
        printf("Autor de %d livros", list_aut.n_livros);
    }
    system("pause");
}

void stats_menu(){
    int opcao = -1;
    for(int i = 0; i<1; i++){
        printf("Indique a opcao que quer realizar\n");
        printf("1 - Total de publicacoes\n");
        printf("2 - Total de autores\n");
        printf("3 - Total de palavras-chave\n");
        printf("4 - Total de paginas na base de dados\n");
        printf("5 - Media de paginas por publicacao\n");
        printf("0 - Sair\n");
        switch(opcao){
            case 0:
                i++;
                break;
            case 4:
                total_pag();
                break;
            case 5:
                media_pag();
                break;
        }
    }
}

void total_pag(){
    int soma = 0;
    for (int i = 0; i<n; i++){
        soma += livros[i].num_pag;
    }
    printf("O numero total de paginas na base de dados e %d\n", soma);
}

void media_pag(){
    int soma = 0;
    float media=0;
    for (int i = 0; i<n; i++){
        soma += livros[i].num_pag;
    }
    media = (float)soma / n;
    printf("Ha em media $.f paginas por publicacao", media);
}

