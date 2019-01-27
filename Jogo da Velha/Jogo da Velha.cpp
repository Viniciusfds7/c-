
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){

    //Navega pelo tabuleiro e coloca o simbolo de '-'
    int linha, coluna;
    for(linha = 0; linha<3; linha++){
            for (coluna = 0;coluna<3;coluna++){
            tabuleiro [linha][coluna]='-';
            }

      }
}

void exibeTabuleiro(char tabuleiro[3][3]){

    int linha,coluna;                                           //Auxiliares para tabuleiro

    //Exibe tabuleiro
      for(linha = 0; linha<3; linha++){
            for (coluna = 0;coluna<3;coluna++){
            cout << tabuleiro [linha][coluna];
            }
            cout << "\n";
      }


}


void jogo(){

     ///Variáveis Gerais
      char tabuleiro[3][3];                                       //Tabuleiro do Jogo
      int linha,coluna;                                           //Auxiliares para tabuleiro

      //Coloca os "-" no tabuleiro
      iniciaTabuleiro(tabuleiro);

    cout << "\n\n";
      exibeTabuleiro (tabuleiro);
     cout << "\n\n";


}


void menuInicial(){

    //Opção escolhida pelo usuário
    int opcao = 0;

    //Nome do usuário
    string nomeDoJogador;

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "\n\n\nBem vindo ao Jogo de Batalha Naval";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";

        //Faz a leitura da opcao
        cin >> opcao;

        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                //cout << "Jogo iniciado";
                jogo();
                break;
            case 2:
                //Mostra informacoes do Jogo
                cout << "Informacoes do jogo:";
                cout << "\n\nJogo desenvolvido por Vinicius Ferraz da Silva em 27/01/2019\nTodo feito em linguagem c++, esse eh uma maneira mais eficaz de fixar o conhecimento adquirido nas aulas.";
                break;
            case 3:
                cout << "Ate mais!";
                break;
        }
    }

}



int main(){

    menuInicial();

    return 0;
}
