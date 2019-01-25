#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpatela(){
    system("CLS");
}

//

void iniciatabuleiro(char tabuleiro [10][10], char mascara [10][10]){

    int linha, coluna;         // Variáveis auxiliares

    //Popula o tabuleiro com água
    for(linha = 0; linha < 10 ; linha ++){
        for (coluna = 0 ; coluna < 10 ; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }

}

//


void exibetabuleiro (char tabuleiro [10][10], char mascara [10][10]){

    int linha, coluna;         // Variáveis auxiliares


    for(linha = 0; linha < 10 ; linha ++){
        for (coluna = 0 ; coluna < 10 ; coluna++){
            cout << " " << mascara[linha][coluna];
        }
        cout << "\n";
    }

    for(linha = 0; linha < 10; linha++){
             for(coluna = 0; coluna < 10; coluna++){
                 cout << " " <<tabuleiro[linha][coluna];
             }
             cout << "\n";
        }




}

//


void posicionabarcos(char tabuleiro [10][10]){


    //Coloca 10 barcos no tabuleiro
    int cont, quantidade = 10, quantidadeposicionada = 0;


    //verifica se já posicionou os barcos
    while (quantidadeposicionada < quantidade){

        for (cont = 0 ; cont < quantidade;cont++){

            int linhaaleatoria = rand() % 10;     //Gera número aleatóio
            int colunaaleatoria = rand() % 10;

        if (tabuleiro [linhaaleatoria][colunaaleatoria] == 'A'){
            //posiciona barcos aleatóriamente
            tabuleiro[linhaaleatoria][colunaaleatoria] = 'B';

            //aumenta contador de barcos posicionados
            quantidadeposicionada++;
        }
    }
}
}


//

void jogo () {

    ///Variáveis Gerais
    char tabuleiro [10][10], mascara [10][10];       // Tabuleiro do Jogo
    int linha, coluna;                               // Variáveis auxiliares
    int linhajogada, colunajogada;                   // posição escolhida pelo usuário
    int estadodejogo = 1;                            // 1 = jogo acontecendo 0 = fim de jogo



    //Inicia o Tabuleiro com agua
    iniciatabuleiro(tabuleiro, mascara);

    //posiciona barcos aleatoriamente
    posicionabarcos(tabuleiro);




    while (estadodejogo == 1){

        limpatela();

        //limpa tela
        cout << "\n\n\n";
        //exibe tabuleiro
        exibetabuleiro(tabuleiro,mascara);

        cout << "\nDigite uma linha: ";
        cin >> linhajogada;
        cout << "\nDigite uma coluna: ";
        cin >> colunajogada;

        //revela o tabuleiro
        mascara[linhajogada-1][colunajogada-1] = tabuleiro[linhajogada][colunajogada];
    }
}

//



void menuinicial(){

    //opçao escolhida pelo usuário
    int opcao = 0;

     //Enquanto o jogadro não digita um valor valido ele repete o menu
    while (opcao < 1 || opcao >3){

        limpatela ();
        cout << "\n\n---BEM VINDO AO JOGO DE BATALHA NAVAL---";
        cout <<"\n  1 - Jogar;";
        cout <<"\n  2 - Sobre;";
        cout <<"\n  3 - Sair.";
        cout <<"\n ESOLHA UMA OPCAO E TECLE ENTER: ";
        cin >> opcao;

            switch (opcao){

                case 1:
                    limpatela ();
                    //Inicia o Jogo
                   // cout << "\n Jogo inicado.\n\n\n";
                   jogo();


                break;

                case 2:
                    limpatela ();
                    //Informacoes do jogo
                    cout << "\n Informacoes do jogo.\n\n\n";
                break;

                case 3:
                    limpatela ();
                    //Sai do jogo
                    cout << "\n Ate mais!\n\n\n";
                break;
            }
    }
}

//


int main(){

    srand((unsigned) time(NULL));

    menuinicial();




    //system("\n\npause");
    return 0;
}
