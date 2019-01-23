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

    //system("pause");

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

void  exibestatus(string palavracommascara, int tamanhodapalavra, int tentativasrestantes, string letrasjaarriscadas, string mensagem) {

    //cout << "A palavra secreta eh: "<< palavra << "(Tamanho: "<< tamanhodapalavra <<")\n\n" ;
    cout << mensagem;
    cout << "\nPalavra "<< palavracommascara << "(Tamanho: "<< tamanhodapalavra <<")\n\n" ;
    cout << "\nTentativas restantes: " << tentativasrestantes << "\n\n\n";


    //Exibe as letras arriscadas
    int cont;
    cout << "\nLetras Arriscadas: ";
    for(cont = 0; cont < letrasjaarriscadas.size(); cont++){
        cout << letrasjaarriscadas[cont] << ", ";
    }


}


int jogar(int numerodejogadores){

    //Palavra a ser adivinhada
    string palavra;

    //Confere o número de jogadores
    if (numerodejogadores == 1){

        //palavra a ser adivinhada
        palavra = retornapalavraaleatoria();
    }else {

        cout << "\nDigite uma palavra:  ";
        //palavra a ser adivinhada
         cin >> palavra;

    }





    //tamanho da palavra
    int tamanhodapalavra = palavra.size();

    //Palavra mascarada
    string palavracommascara = retornapalavracommascara(palavra, tamanhodapalavra);

    ///Variáveis pricipais
    int tentativas = 0, maximodetentativas = 10;       //números de tentativas
    int cont = 0;                                    //auxiliar ocntadora
    char letra;                                      //letra arriscada
    int opcao;                                       //Opçoes finais
    string letrasjaarriscadas;                       //acumula as tentativas do jogador
    string mensagem = "Bem vindo ao jogo!\n";          //Feed back Jogador
    bool jadigitouletra = false, acertouletra = false;                     //auxiliar para letra já digitada


    while (palavra != palavracommascara && (maximodetentativas - tentativas) > 0) {


        limpatela();

        //exibe o status atual do jogo
        exibestatus(palavracommascara,tamanhodapalavra, maximodetentativas - tentativas, letrasjaarriscadas, mensagem);

        //Palpites
        cout << "\nDigite uma letra: ";
        cin >> letra;


        //percorre as letras já arriscadas
        for (cont=0; cont<tentativas; cont++){

            //Se encontra a letra
            if(letrasjaarriscadas[cont] == letra){

                mensagem = "\nEssa letra ja foi digitada!\n";
                //Indice com a variavel booleana
                jadigitouletra=true;
            }
        }
            //Incrementa as letras já arriscadas
            if (jadigitouletra==false){
                letrasjaarriscadas += tolower (letra);


        //percorre a palavra real e se existir muda a palavra
        for(cont=0; cont<tamanhodapalavra; cont++){



            // Se a letra existir na palavra escondida
            if(palavra[cont]== tolower(letra)){

                //Faço a letra aparecer na palavra
                palavracommascara[cont] = palavra[cont];


                acertouletra = true;
            }

        }



        if (acertouletra == false ) {

            mensagem = "\nVoce errou uma letra";
        }else{

            mensagem = "\nVoce acertou uma letra!\n";


        }

         //aumenta as tentativas
        tentativas++;

        }

        jadigitouletra = false;
        acertouletra = false;



    }

if (palavra == palavracommascara){

    limpatela();
        cout << "\nA palavra eh: " << palavra;
        cout << "\n\n\nPARABENS!! VOCE VENCEU O MELHOR JOGO DO MUNDO. MUITO FELIZ POR VOCE. VOCE EH UM GENIO.\n\n\n";
        cout << "\n Deseja reiniciar?";
        cout << "\n1 - Sim.";
        cout << "\n2 - Nao.\n";
        cin >> opcao;
        return opcao;


    //system("pause");
} else {

    limpatela();
        cout << "\nA palavra eh: " << palavra;
        cout << "\n\n\nInfelizmente voce perdeu. Tente novamente.\n\n\n";
        cout << "\n Deseja reiniciar?";
        cout << "\n1 - Sim.";
        cout << "\n2 - Nao.\n";
        cin >> opcao;
        return opcao;
    //system("pause");
}

}



void menuinicial (){

//Opção escolhida pelo usuário
    int opcao = 0;


    // Enquanto o valor não digita uma opcao valida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
    limpatela ();
    cout << "\n\n---BEM VINDO AO JOGO DA FORCA---";
    cout <<"\n  1 - Jogar Sozinho;";
    cout <<"\n  2 - Jogar em Dupla;";
    cout <<"\n  3 - Sobre;";
    cout <<"\n  4 - Sair.";
    cout <<"\nEscolha uma opcao e tecle ENTER:";


    //leitura da opcao
    cin >> opcao;

    switch (opcao){
        case 1:
            //inicia o jogo
            cout << "\n\nJogo iniciado\n\n";
            if (jogar(1)==1){
                menuinicial();
            };
            break;

        case 2:
            //inicia o jogo
            cout << "\n\nJogo iniciado\n\n";
            if (jogar(2)==1){
                menuinicial();
            };
            break;

         case 3:
             //informacoes do jogo

            cout << "\n\nInformacoes do jogo\n\n";
            limpatela ();
            cout << "\n\nJogo desenvolvido por Vinicius Ferraz da Silva em 23/01/2019\nTodo feito em linguagem c++, esse eh uma maneira mais eficaz de fixar o conhecimento adquirido nas aulas.";
            cout << "\n\n1 - Voltar.";
            cout << "\n2 - Sair.\n";
            cin >> opcao;
            if (opcao == 1) {
                menuinicial();
            }

            break;

         case 4:
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

