#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500 //numero maximo de livros que odem ser guardados
#define AUT 200 //numero maximo de autores

int n=0;    // numero total de referencias inserido
int nta=0;  // numero total de autores inseridos
int ntpc=0; // numero total de palavras-chave inseridas
int temppc=0; // variavel temporaria para palavras-chave

typedef struct{
    char nome[50];
    char tipo[30];
    char nome_completo[100];
    int ano_pub[4];
    char local_pub[100];
    char nomes_aut[400];
    int num_pag[5];
    char endereco[100];
    char pal_chave[6][30];
}referencias_biblio;

typedef struct{
   char nome_prpio[20];
   char apelido[50];
   char nome_completo[70];
   int n_livros;
}autores_diff;

referencias_biblio livros[MAX];
autores_diff autores_dif[AUT];


void inserir();                                                 // a funcionar
void inserir_aut(int cod);                                      //

void editar();                                                  // a funcionar
void alterar_palchave_menu(int cod,referencias_biblio info);    // a funcionar
void alterar_palchave(int cod, referencias_biblio info);        // a funcionar
void add_palchave(int cod, referencias_biblio info);            // almost

void eliminar_menu();   // a funcionar
void eliminar();        // a funcionar
void eliminar_aut();    //
void eliminar_pc();     //

void listar_menu();     // a funcionar
void codigos();         // a funcionar
void listar_tudo();     // a funcionar
void listar_autores();  // ??
void filtro_palchave();
void filtro_autores();
void filtro_anopub();   // a funcionar
void filtro_tipo();     // a funcionar

void stats_menu();      // a funcionar
void total_pub();       // a funcionar
void total_aut();
void total_palchave();  // a funcionar
void total_pag();       // a funcionar
void media_pag();       // a funcionar

int main(){
    int opcao=-1;
    for (int i=0; i<1; i++){
        printf("\n\n.......................................\n");
        printf("Insira a opcao que pretende realizar:\n");
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
                eliminar_menu();
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
        if(*livro_inserido.ano_pub>=2022){
            printf("Ano inserido invalido!!");
            break;
        }

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
        fgets(livro_inserido.endereco, 50, stdin);
        livro_inserido.endereco[strcspn(livro_inserido.endereco, "\n")] = 0;
        printf("\n");

        printf("Insira o numero de palavra-chave que vai inserir(maximo 5): ");
        fflush(stdin);
        scanf("%d", &num_palchave);
        printf("\n");
        if(num_palchave>5){
            printf("Erro: Numero de palavras-chave invalido!!\n");
            break;
        }
        else{
            for(int i=0; i<num_palchave; i++){
                printf("%d Palavra-Chave: ", i+1);
                fflush(stdin);
                fgets(&(livro_inserido.pal_chave[i][30]), 30,stdin);
                livro_inserido.pal_chave[i][strcspn(livro_inserido.pal_chave[i], "\n")]=0;
                temppc = num_palchave;
                ntpc++;
            }
        }

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

void eliminar_menu(){
int opcao = -1;
for(int i=0; i<1;i++){
    printf("\n\n.......................................\n");
    printf("Indique a opcao que pretende realizar\n");
    printf("1 - Eliminar uma referencia por completo\n");
    printf("2 - Eliminar um autor de uma referencia\n");
    printf("3 - Eliminar uma palavra-chave de uma referencia\n");
    scanf("%d", &opcao);
    switch (opcao){
        case 1:
            eliminar();
            i--;
            break;
        case 2:
            eliminar_aut();
            i--;
            break;
        case 3:
            eliminar_pc();
            i--;
            break;
        default:
            printf("Erro: Opcao Invalida!!");
            i--;
            break;
    }
}
}

void eliminar(){
    int cod;
    for(int i = 0; i < 1; i++){
        printf("\n\n.......................................");
        printf("\nIndique o codigo do livro que quer eliminar(0 para sair): ");
        scanf("%d", &cod);
        if(cod == 0){
            printf("Saiu com sucesso!!\n");
            i++;
        }
        livros[cod -1] = livros[cod];
        printf("Eliminou o livro de codigo %d com sucesso!!\n", cod);
        n--;
        i++;
    }
}

void eliminar_aut(){

}

void eliminar_pc(){

}

void editar(){
    referencias_biblio info;
    int cod=0, edit=0;
    printf("\n\n...................................................");
    printf("\nInsira o codigo do livro do qual pretende editar informacao (0 para sair): ");
    scanf("%d", &cod);
    if (cod == 0){
        printf("\nSaiu com sucesso!!");
    }
    else if(cod>n+1)
        printf("Erro: Nao existe uma referencia com o codigo '%d'", cod);

    else {
        for (int i = 0; i < 1; ++i) {
            info = livros[cod-1];
            printf("\nO que pretende editar?\n");
            printf("1 - Nome do livro (Atual: %s)\n", info.nome);
            printf("2 - Tipo de publicacao (Atual: %s)\n", info.tipo);
            printf("3 - Autores (Atual: %s)\n", info.nomes_aut);
            printf("4 - Ano de publicacao (Atual: %d) \n",  *(info.ano_pub));
            printf("5 - Local de publicacao (Atual: %s)\n", info.local_pub);
            printf("6 - Numero de paginas (Atual: %d) \n",  *(info.num_pag));
            printf("7 - Endereco HTTP (Atual: %s)\n", info.endereco);
            printf("8 - Palavras-Chave\n");
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
                    printf("Insira o numero de paginas (Atual: %d): ", *(info.num_pag));
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

                case 8:
                    alterar_palchave_menu(cod, info);
                    i--;
                    break;

                case 9:
                    printf("Novo codigo (Atual: %d): ", cod);
                    fflush(stdin);
                    scanf("%d", &cod);
                    i--;
                    break;

                case 0:
                    printf("Saiu com sucesso!!\n");
                    i++;
                    break;

                default:
                    printf("Opcao inserida invalida!!\n");
                    i--;
                    break;
            }
        }
    }
}

void alterar_palchave_menu(int cod, referencias_biblio info){
    int opcao = -1;
    for(int j=0; j<1; j++){
        info = livros[cod-1];
        printf("Indique qual opcao quer realizar:\n");
        printf("1 - Editar uma palavra-chave existente\n");
        printf("2 - Adicionar uma palavra-chave\n");
        printf("0 - Sair\n");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao){
            case 0:
                printf("Saiu com sucesso!!\n");
                j++;
                break;
            case 1:
                alterar_palchave(cod, info);
                j--;
                break;
            case 2:
                add_palchave(cod, info);
                j--;
                break;
            default:
                printf("Erro: Opcao Invalida!!");
                j--;
                break;
        }


    }
}

void alterar_palchave(int cod, referencias_biblio info){
    int editpc;
    for(int j=0; j<1;j++){
        info = livros[cod-1];
        printf("Palavras-chave do livro de codigo '%d':\n", cod);
        for(int k=0;k<temppc;k++){
            printf("%d - %s\n",k+1, &(info.pal_chave[k][30]));
        }

        printf("Indique qual das palavras-chave quer alterar(0 para sair): ");
        fflush(stdin);
        scanf("%d", &editpc);
        if(editpc>5){
            printf("Erro: Opcao Invalida\n\n");
            j++;
        }
        switch(editpc){
            case 1:
                printf("Nova palavra-chave(Atual: %s): ", info.pal_chave[1]);
                fflush(stdin);
                fgets(livros[cod-1].pal_chave[1], 30, stdin);
                livros[cod-1].pal_chave[1][strcspn(livros[cod-1].pal_chave[1], "\n")]=0;
                printf("\nAlterou '%s' para '%s' com sucesso!!\n\n", info.pal_chave[1], livros[cod-1].pal_chave[1]);
                j--;
                break;
            case 2:
               printf("Nova palavra-chave(Atual: %s): ", info.pal_chave[2]);
               fflush(stdin);
               fgets(livros[cod-1].pal_chave[2], 30, stdin);
               livros[cod-1].pal_chave[2][strcspn(livros[cod-1].pal_chave[2], "\n")]=0;
               printf("\nAlterou '%s' para '%s' com sucesso!!\n\n", info.pal_chave[2], livros[cod-1].pal_chave[2]);
               j--;
               break;
            case 3:
                printf("Nova palavra-chave(Atual: %s): ", info.pal_chave[3]);
                fflush(stdin);
                fgets(livros[cod-1].pal_chave[3], 30, stdin);
                livros[cod-1].pal_chave[3][strcspn(livros[cod-1].pal_chave[3], "\n")]=0;
                printf("\nAlterou '%s' para '%s' com sucesso!!\n\n", info.pal_chave[3], livros[cod-1].pal_chave[3]);
                j--;
                break;
            case 4:
                printf("Nova palavra-chave(Atual: %s): ", info.pal_chave[4]);
                fflush(stdin);
                fgets(livros[cod-1].pal_chave[4], 30, stdin);
                livros[cod-1].pal_chave[4][strcspn(livros[cod-1].pal_chave[4], "\n")]=0;
                printf("\nAlterou '%s' para '%s' com sucesso!!\n\n", info.pal_chave[4], livros[cod-1].pal_chave[4]);
                j--;
                break;
            case 5:
                printf("Nova palavra-chave(Atual: %s): ", info.pal_chave[5]);
                fflush(stdin);
                fgets(livros[cod-1].pal_chave[5], 30, stdin);
                livros[cod-1].pal_chave[5][strcspn(livros[cod-1].pal_chave[5], "\n")]=0;
                printf("\nAlterou '%s' para '%s' com sucesso!!\n\n", info.pal_chave[5], livros[cod-1].pal_chave[5]);
                j--;
                break;
            case 0:
                printf("Saiu com sucesso!!\n\n");
                j++;
            default:
                printf("Erro: Opcao Invalida\n\n");
                j--;
                break;
        }
    }
}

void add_palchave(int cod, referencias_biblio info){
    int addpc;
    char sair;
    for(int i=0; i<1; i++){
        printf("Palavras-chave do livro de codigo '%d':\n", cod);
        for(int j=0;j<temppc;j++){
            printf("%d - %s\n",j+1, &(info.pal_chave[j][30]));
        }
        printf("Numero de palavras-chave que vai adicionar: ");
        fflush(stdin);
        scanf("%d", &addpc);
        printf("\n");
        if((temppc + addpc)>5){
            printf("Erro: Uma referencia nao pode ter mais de 5 palavras-chave\n\n");
            i++;
        }
        for(int k=0; k<addpc;k++){
            printf("%d Palavra: ",k+1);
            fflush(stdin);
            fgets(&livros[cod-1].pal_chave[temppc+1][30],30, stdin);
            livros[cod-1].pal_chave[temppc+1][strspn(livros[cod-1].pal_chave[temppc+1], "\n")]=0;
            printf("\n");
            temppc++;
            ntpc++;
        }
            printf("Quer adicionar mais alguma palavra-chave?(S - Sim | N - Nao): ");
            scanf("%c", &sair);
            switch (sair){
                case 'n':
                    i++;
                    break;
                case 'N':
                    i++;
                    break;
                case 's':
                    i--;
                    break;
                case 'S':
                    i--;
                    break;
                default:
                    printf("\nErro: Opcao Invalida!!\n\n");
                    i++;
                    break;
        }
    }
}

void listar_menu(){
    int opcao = -1;
    for(int i = 0; i<1; i++){
        printf("\n\n----------------------------------------------------------------------------------------------");
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
                printf("Saiu com sucesso!!\n\n");
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
            case 4:
                filtro_tipo();
                i--;
                break;
            case 5:
                filtro_palchave();
                i--;
                break;
            case 6:
                filtro_anopub();
                i--;
                break;
            case 8:
                stats_menu();
                i--;
            default:
                printf("Erro: Opcao invalida\n\n");
                i--;
                break;
        }
    }
}

void listar_tudo(){
    referencias_biblio lista;
    int i;
    int cod = 0;
    char sair;

    for(i=0; i<1; i++) {
        printf("\n\n----------------------------------------------------------------------------------------------");
        printf("\nIndique o codigo do livro que quer mostrar (0 para voltar ao menu anterior): ");
        scanf("%d", &cod);
        if(cod == 0){
            printf("\nSaiu com sucesso!!");
            i++;}
        else if(cod>n){
            printf("Erro: Nao existe um livro com o codigo '%d'", cod);
            i--;
        }
        else{
        lista = livros[cod - 1];
        printf("\nNome do livro: %s", lista.nome);
        printf("\nTipo de livro: %s", lista.tipo);
        printf("\nNome do autor: %s", lista.nomes_aut);
        printf("\nAno de publicacao: %d", *lista.ano_pub);
        printf("\nLocal de publicacao: %s", lista.local_pub);
        printf("\nNumero de paginas: %d", *lista.num_pag);
        printf("\nEndereco HTTP: %s\n", lista.endereco);
        printf("Palavras-Chave:\n");
        for(int j=0; j<temppc; j++){
            printf("- %s", &(lista.pal_chave[j][30]));
            printf("\n");

        }

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

void codigos(){
    int i;
    printf("\n\n--------------------------------------------------------------------------------------------------");
    for (i = 0; i < n; ++i) {
        printf("\nLivro: %s | Codigo : %d\n",livros[i].nome, i+1);
    } // mostra os codigos de todos os livros
    system("pause");
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


void filtro_anopub(){
    int anoinserido;
    printf("\n\n--------------------------------------------------------------------------------------------------\n");
    printf("Indique o ano que vai verificar: ");
    scanf("%d", &anoinserido);
    printf("\n");
    printf("Publicacoes encontradas:\n");
    for(int i=0; i<MAX;i++){
        if(anoinserido==*(livros[i].ano_pub)){
            printf("%s\n", livros[i].nome);
            system("pause");
        }
        else break;
    }
}

void filtro_tipo(){
    char tipoinserido[30];
    printf("\n\n--------------------------------------------------------------------------------------------------\n");
    printf("Indique o tipo de referencia que vai verificar: ");
    fflush(stdin);
    fgets(tipoinserido, 30, stdin);
    tipoinserido[strcspn(tipoinserido, "\n")]=0;
    printf("Referencias com o tipo '%s': \n", tipoinserido);
    for(int i=0; i<1; i++){
        for(int j=0; j<n; j++) {
            if (strcmp(livros[j].tipo, tipoinserido) == 0){
                printf("Codigo: %d - %s \n", j + 1, livros[j].nome);
            }
        }
    }
    system("pause");
}

void filtro_palchave(){
    char palchave_inserido[5][30];
    int num_pc;
    for(int j=0; j<1; j++){
        printf("\n\n----------------------------------------------------------------------------------------------\n");
        printf("Indique o numero de palavras-chave que vai verificar(maximo 5): ");
        fflush(stdin);
        scanf("%d", &num_pc);
        if(num_pc>5){
            printf("Erro: Numero de palavras-chave invalido!!");
            j++;
        }

        printf("\n");
        for(int i=0; i<num_pc; i++){
            printf("%d Palavra: ", i+1);
            fflush(stdin);
            fgets(palchave_inserido[i],30, stdin);
            palchave_inserido[i][strcspn(palchave_inserido[i], "\n")]=0;
            printf("\n");
        }
        for(int k=0; k<5; k++){
            for(int l=0; l<n; l++){
                if(strcmp(palchave_inserido[k], livros[l].pal_chave[k])==0)
                    printf("Codigo %d - %s\n",l+1, livros[l].nome);
            }
        }
        system("pause");
    }
}

void stats_menu(){
    int opcao = -1;
    for(int i = 0; i<1; i++){
        printf("\n\n----------------------------------------------------------------------------------------------\n");
        printf("Indique a opcao que quer realizar\n");
        printf("1 - Total de publicacoes\n");
        printf("2 - Total de autores\n");
        printf("3 - Total de palavras-chave\n");
        printf("4 - Total de paginas na base de dados\n");
        printf("5 - Media de paginas por publicacao\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                total_pub();
                i--;
                break;
            case 2:
                total_aut();
                i--;
                break;
            case 3:
                total_palchave();
                i--;
                break;
            case 4:
                total_pag();
                i--;
                break;
            case 5:
                media_pag();
                i--;
                break;
            case 0:
                i++;
                break;
        }
    }
}

void total_pag(){
    int soma = 0;
    for (int i = 0; i<n; i++){
        soma += *(livros[i].num_pag);
    }
    printf("\n\n--------------------------------------------------------------------------------------------------");
    printf("\nTotal de paginas na base de dados: %d paginas\n", soma);
    system("pause");
}

void media_pag(){
    int soma = 0;
    float media;
    for (int i = 0; i<n; i++){
        soma += *(livros[i].num_pag);
    }
    media = (float)soma / n;
    printf("\n\n--------------------------------------------------------------------------------------------------\n");
    printf("Ha em media %.f paginas por publicacao\n", media);
    system("pause");
}

void total_pub(){
    printf("\n\n--------------------------------------------------------------------------------------------------\n");
    printf("Total de publicacoes na base de dados: %d publicacao/oes\n", n);
    system("pause");
}

void total_aut(){
    printf("\n\n--------------------------------------------------------------------------------------------------\n");
    printf("Total de autores na base de dados: %d\n", nta);
    system("pause");
}

void total_palchave(){
    printf("\n\n--------------------------------------------------------------------------------------------------\n");
    printf("Total de palavras-chave na base de dados: %d\n", ntpc);
    system("pause");
}