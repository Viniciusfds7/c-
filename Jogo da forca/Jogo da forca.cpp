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

    string palavras[5] = {"abacaxi", "manga", "morango", "banana", "damasco"};

    //Indice gerado pelo intervalo [0,1,2]
    int indicealeatorio = rand() %5 ;

    cout << indicealeatorio;

    system("pause");

    //Exibe uma palavra aleatória
    return palavras[indicealeatorio];

}

string retornapalavracommascara(string palavra, int tamanhodapalavra){
    int cont = 0;
    string palavracommascara;


    //Coloca mascara
    while(cont < tamanhodapalavra){
        palavracommascara += "_";
        cont++;
    }

    return palavracommascara;
}

void  exibestatus(string palavracommascara, int tamanhodapalavra, int tentativasrestantes, string letrasjaarriscadas) {

    //cout << "A palavra secreta eh: "<< palavra << "(Tamanho: "<< tamanhodapalavra <<")\n\n" ;
    cout << "Palavra "<< palavracommascara << "(Tamanho: "<< tamanhodapalavra <<")\n\n" ;
    cout << "\nTentativas restantes: " << tentativasrestantes << "\n\n\n";


    //Exibe as letras arriscadas
    int cont;
    cout << "\nLetras Arriscadas: ";
    for(cont = 0; cont < letrasjaarriscadas.size(); cont++){
        cout << letrasjaarriscadas[cont] << ", ";
    }


}


void jogasozinho(){

    //palavra a ser adivinhada
    string palavra = retornapalavraaleatoria();

    //tamanho da palavra
    int tamanhodapalavra = palavra.size();

    //Palavra mascarada
    string palavracommascara = retornapalavracommascara(palavra, tamanhodapalavra);

    ///Variáveis pricipais
    int tentativas = 0, maximodetentativas = 7;       //números de tentativas
    int cont = 0;                                    //auxiliar ocntadora
    char letra;                                      //letra arriscada
    string letrasjaarriscadas;                       //acumula as tentativas do jogador
    bool jadigitouletra = false;                             //auxiliar para letra já digitada


    while (palavra != palavracommascara && (maximodetentativas - tentativas) > 0) {


        //limpatela();

        //exibe o status atual do jogo
        exibestatus(palavracommascara,tamanhodapalavra, maximodetentativas - tentativas, letrasjaarriscadas);

        //Palpites
        cout << "\nDigite uma letra: ";
        cin >> letra;


        //percorre as letras já arriscadas
        for (cont=0; cont<tentativas; cont++){

            //Se encontra a letra
            if(letrasjaarriscadas[cont] == letra){

                cout << "\nEssa letra já foi digitada.\n";
                //Indice com a variavel booleana
                jadigitouletra=true;
            }
        }

        if (jadigitouletra==false){
                letrasjaarriscadas += letra;


        //percorre a palavra real e se existir muda a palavra
        for(cont=0; cont<tamanhodapalavra; cont++){

            // Se a letra existir na palavra escondida
            if(palavra[cont]==letra){

                //Faço a letra aparecer na palavra
                palavracommascara[cont] = palavra[cont];
            }

        }

        //aumenta as tentativas
        tentativas++;

        }





    }

if (palavra == palavracommascara){

    limpatela();
    cout << "\n\n\nPARABENS!! VOCE VENCEU O MELHOR JOGO DO MUNDO. MUITO FELIZ POR VOCE. VOCE EH UM GENIO.\n\n\n";
    system("pause");
} else {
    limpatela();
    cout << "\n\n\nInfelizmente voce perdeu. Tente novamente.\n\n\n";
    system("pause");
}

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

    srand((unsigned) time(NULL));

    menuinicial();





    return 0;
}

