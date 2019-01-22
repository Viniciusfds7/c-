#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpatela () {
    system ("CLS");
}


void menuinicial (){

//Opção escolhida pelo usuário
    int opcao = 0;


    // Enquanto o valor não digita uma opcao valida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
    limpatela ();
    cout << "\n\nBEM VINDO AO JOGO";
    cout <<"\n1 - Jogar";
    cout <<"\n2 - Sobre";
    cout <<"\n3 - Sair";
    cout <<"\nEscolha uma opcao e tecle ENTER:";

    //leitura da opcao
    cin >> opcao;

    switch (opcao){
        case 1:
            //inicia o jogo
            cout << "\n\nJogo iniciado\n\n";
            break;

         case 2:
             //informacoes do jogo
            cout << "\n\nInformacoes do jogo\n\n";
            break;

         case 3:
             //até mais
            cout << "\n\nAte mais\n\n";
            break;
    }
    }

}

int main(){

    menuinicial();



    return 0;
}
