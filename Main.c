#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // manipular bool
#include <string.h> //manipular string
#include <conio.h> //

typedef struct {
   bool vivo;
   
   char nome[16];// permite um nome de ate 16 caracteres
   int hp;

   int PlayerX;
   int PlayerY;

}player;
    int continuar = 1;
    player newPlayer; //declaro a existencia do player
    
void GenerateMap1(char mapa[13][13],int PlayerX, int PlayerY) {
    // Layout do mapa em forma de array de strings
    int i,j;
    char layout2[23][23] = {
		"\t\t\t####################",
		"\t\t\t##				  #",
		"\t\t\t#				  #",
		"\t\t\t#   			      #",
		"\t\t\t#		 	      #",
		"\t\t\t#		 	      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t#			      #",
		"\t\t\t##			     ##",
		"\t\t\t####################",
		}
    char layout[13][13] = {
        "\t\t\t#########",
        "\t\t\t##     ##",
        "\t\t\t#       #",
        "\t\t\t#       #",
        "\t\t\t#  ######",
        "\t\t\t#  #@   #",
        "\t\t\t#  ###  #",
        "\t\t\t#  #D#  #",
        "\t\t\t#       #",
        "\t\t\t#########"
    };

    // Copiando o layout para o mapa do jogo
    for (i = 0; i < 13; i++){
        for (j = 0; j < 13; j++){
            mapa[i][j] = layout[i][j];
        }
    }
    mapa[PlayerY][PlayerX] = '&';
};

void PrintMap(char mapa[13][13]){
    int i,j;
    for (i = 0; i < 13; i++){
        for (j = 0; j < 13; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
};

void PrintTuto(){
    printf("Tutorial");
    printf("\n\
    'W' = Mover para cima\n\
    'A' = Mover para a esquerda\n\
    'S' = Mover para baixo\n\
    'D'= Mover para a direita\n\
    'I' = Interagir com objetos (Somente quando estiver embaixo do jogador)\n\n\
    Voce (Player) tem apenas 3 vidas, seu objetivo eh pegar a '@' (Chave) para abrir a porta identificada como 'D' e concluir a fase.\n\n\
    Tome cuidado! Conforme voce avanca no jogo a dificuldade ira aumentar.\n\
    Esteja atento com inimigos e obstaculos identificados como 'X' (inimigo nivel 1),'V' (inimigo nivel 2) e '#' (Espinhos).\n\
    Caso encoste em algum desses inimigos ou obstaculos a fase sera reiniciada.\n\n\
    Obs: Aperte o botao ('O') encontrado em alguma fase e descubra algo secreto :)\n");

    printf("\nPressione qualquer tecla para voltar ao menu...\n");
    getch();
    system("cls");

}

void PlayerSettingsBase(){ // função só para facilitar o reset do game 
    newPlayer.vivo = true;
    newPlayer.hp = 3;
}

/*void charcreation(){
    
    printf("Digite o nome do Player: ");
    PlayerSettingsBase();
    scanf(newPlayer.nome);

    if(strlen(newPlayer.nome) == 0){
        strcpy(newPlayer.nome, "Lumine");
    }
    printf("Nome: %s\n", newPlayer.nome);// mostra o nome do jogador
 
   if (newPlayer.vivo == true) {//fala se o jogador esta vivo ou morto
        printf("O jogador %s esta vivo.\n", newPlayer.nome);
    } else {
        printf("O jogador %s esta morto.\n", newPlayer.nome);
    }
}*/



void sair(){
    printf("Saindo do jogo...\n");
    exit(0);
}

/*void Interact(char mapa[13][13], int PlayerX, int PlayerY) {
    // Verifica se o jogador está próximo ao objeto '@' em qualquer direção
for (int i = PlayerY - 1; i <= PlayerY + 1; i++) {
    for (int j = PlayerX - 1; j <= PlayerX + 1; j++) {
        // Verifica se a posição está dentro dos limites do mapa
        if (i >= 0 && i < 13 && j >= 0 && j < 13) {
            if (mapa[i][j] == '@') {
                // Adicione este printf para verificar as coordenadas
                printf("Encontrou '@' na posição [%d][%d]\n", i, j);

                // Remove o '@' do mapa
                mapa[i][j] = ' ';
                interacted = true;
                system("cls");
                GenerateMap1(mapa, PlayerX, PlayerY);
                PrintMap(mapa);
            }
        }
    }
}

}

    
    if (interacted) {
        printf("Voce assumiu o controle do '@' e o '@' desapareceu!\n");

        // Troca 'D' por '+' no mapa para indicar que a porta foi aberta
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                if (mapa[i][j] == 'D') {
                    mapa[i][j] = '+';
                }
            }
        }
    } else {
        printf("Nada para interagir aqui.\n");
    }
}
*/
void Interact(){
	char mapa[13][13];
	int PlayerX;
	int PlayerY;
    if (mapa[PlayerY][PlayerX] == '@') {
        mapa[PlayerY][PlayerX] = ' '; // Remove o '@' do mapa
        printf("Voce pegou a chave '@'!\n");
    }
}

// coordenada do objeto = x 7 e y 5
void GameStart(){
    int PlayerX = 5; // Coordenada X inicial do jogador
    int PlayerY = 5; // Coordenada Y inicial do jogador
    
    char mapa[13][13];
    
    GenerateMap1(mapa, PlayerY, PlayerX);
    
    //charcreation();
    
    char command;
    
        PrintMap(mapa);
    while(1) {
        command = getch();
    
        switch(command){
            case 'W':
            case 'w':   
                    if (mapa[PlayerY - 1][PlayerX] != '#' && mapa[PlayerY - 1][PlayerX] != 'D') // Verifica se a próxima posição não é uma parede
                    PlayerY--;
                break;
            case 'S':
            case 's':
                if (mapa[PlayerY + 1][PlayerX] != '#' && mapa[PlayerY + 1][PlayerX] != 'D') // Verifica se a próxima posição não é uma parede
                    PlayerY++;
                break;
            case 'D':
            case 'd':
                if (mapa[PlayerY][PlayerX + 1] != '#' && mapa[PlayerY][PlayerX + 1] != 'D') // Verifica se a próxima posição não é uma parede
                    PlayerX++; 
                break;
            case 'A':
            case 'a':
                if (mapa[PlayerY][PlayerX - 1] != '#' && mapa[PlayerY][PlayerX - 1] != 'D') // Verifica se a próxima posição não é uma parede
                    PlayerX--;
                break;
            case 'I':
            case 'i':
            	interact(mapa, PlayerX, PlayerY);
                break;
        }
        system("cls");
        GenerateMap1(mapa, PlayerX, PlayerY);
        PrintMap(mapa);
    }
}



int main(){ // corrigir o bug do infinito
    int option; 
    bool tutorial = false; 
    printf("\n\n");
    printf("\t\t\t88^^Yb 888888 88^^Yb 88   88 888888 88^^Yb 888888  .o. .dP'Y8   8888b. 88   88 88b 88  dP^^b8  888888  dP^Yb  88b 88\n");
    printf("\t\t\t88__dP 88__   88__dP 88   88 88__   88__dP 88__   ,dP' `Ybo.'   8I  Yb 88   88 88Yb88  dP   `' 88__   dP   Yb 88Yb88\n");
    printf("\t\t\t88^^^  88^^   88^^Yb Y8   8P 88^^   88^^Yb 88^^        o.`Y8b   8I  dY Y8   8P 88 Y88  Yb  ^88 88^^   Yb   dP 88 Y88\n");
    printf("\t\t\t88     888888 88  Yb ^YbodP^ 888888 88  Yb 888888      8bodP^   8888Y' `YbodP' 88  Y8  YboodP  888888  YbodP  88  Y8\n");
    printf("\n\n");
    do{
        printf("\t1 - Jogar\n\t2 -Tutorial\n\t3 - Sair\n");
        scanf("%d",&option);
        system("cls");

        switch(option){
            case 1:
                GameStart();// Iniciar o Jogo
                charcreation();
                break;
            case 2:
                system("cls");
                PrintTuto();
                if(!tutorial){
                    tutorial = true;
                }
                printf("\n\n");
                printf("\t\t\t88^^Yb 888888 88^^Yb 88   88 888888 88^^Yb 888888  .o. .dP'Y8   8888b. 88   88 88b 88  dP^^b8  888888  dP^Yb  88b 88\n");
                printf("\t\t\t88__dP 88__   88__dP 88   88 88__   88__dP 88__   ,dP' `Ybo.'   8I  Yb 88   88 88Yb88  dP   `' 88__   dP   Yb 88Yb88\n");
                printf("\t\t\t88^^^  88^^   88^^Yb Y8   8P 88^^   88^^Yb 88^^        o.`Y8b   8I  dY Y8   8P 88 Y88  Yb  ^88 88^^   Yb   dP 88 Y88\n");
                printf("\t\t\t88     888888 88  Yb ^YbodP^ 888888 88  Yb 888888      8bodP^   8888Y' `YbodP' 88  Y8  YboodP  888888  YbodP  88  Y8\n");
                printf("\n\n");
                break;
            case 3:
                sair();//Sair do Jogo
                break;
            default:
                printf("Opção invalida.");
        }
    }while(option != 3);
    getch();
    return 0;
}
