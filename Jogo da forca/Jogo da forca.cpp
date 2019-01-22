#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpatela () {
    system ("CLS");
}

string retornapalavraaleatoria (){

    string palavras[3] = ("Abacaxi", "Manga", "Morango");

    //Indice gerado pelo intervalo [0,1,2]
    int indiceAleatorio = rand() % 3;

    //Exibe uma palavra aleatória
    return palavras[indiceAleatorio];

}

string retornapalavracommascara(string palavra, int tamanhodapalavra){
int cont = 0;
    string palavracommascara;


    //Coloca mascara
    while(cont < tamanhodapalavra){
        palavracommascara += "_ ";
        cont++;
    }

    return palavracommascara;
}


void jogasozinho(){

    //palavra a ser adivinhada
    string palavra = retornapalavraaleatoria();

    //tamanho da palavra
    int tamanhodapalavra = palavra.size();

    //Palavra mascarada
    string palavracommascara = retornapalavracommascara(palavra, tamanhodapalavra);

    cout << "A palavra secreta eh: "<< palavra << "(Tamanho: "<< tamanhodapalavra <<")\n\n" ;
    cout << "\nMascara:" << palavracommascara << "\n\n\n";

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
            jogasozinho();
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

    srand[(unsigned) time(NULL)];

    menuinicial();



    return 0;
}

