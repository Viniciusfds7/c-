#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpatela(){
    system("CLS");
}

void menuinicial(){

    //opçao escolhida pelo usuário
    int opcao = 0;

     //Enquanto o jogadro não digita um valor valido ele repete o menu
    while (opcao < 1 || opcao >3)
    {

        limpatela ();
        cout << "\n\n---BEM VINDO AO JOGO DE BATALHA NAVAL---";
        cout <<"\n  1 - Jogar;";
        cout <<"\n  2 - Sobre;";
        cout <<"\n  3 - Sair.";
        cout <<"\n ESOLHA UMA OPCAO E TECLE ENTER: ";
        cin >> opcao;

            switch (opcao)
            {

                case 1:
                    limpatela ();
                    //Inicia o Jogo
                    cout << "\n Jogo inicado.\n\n\n";
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



int main(){






    //system("\n\npause");
    return 0;
}
