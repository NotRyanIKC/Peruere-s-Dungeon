#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // manipular bool
#include <string.h> // manipular string
#include <conio.h> // getch()

char mapa[13][13];

typedef struct {
    bool vivo;
    char nome[16]; // permite um nome de até 16 caracteres
    int hp;
    int PlayerX;
    int PlayerY;
    int ChaveX;
    int ChaveY;
    int PortaX;
    int PortaY;
    bool chavePega;
} player;

int continuar = 1;
player newPlayer; // declaro a existência do player
/*Void loadmap(mapname){
    If(mapname == 1){
    Mapa = Loadmap(mapa1);
    Printmap(mapa);
    }
}*/
/*char layout2[23][23] = {
		"\t\t\t********************",
		"\t\t\t**	&	 *****#O#**",
		"\t\t\t*		  ****	 **",
		"\t\t\t*   		   ***  #**",
		"\t\t\t*		 	**   **",
		"\t\t\t*		 	 *#  **",
		"\t\t\t*			      *",
		"\t\t\t**			     **",
		"\t\t\t*			      *",
		"\t\t\t**			     **",
		"\t\t\t***			    ***",
		"\t\t\t***			    ***",
		"\t\t\t***			    ***",
		"\t\t\t**			     **",
		"\t\t\t*			      *",
		"\t\t\t**	   *	 X    *",
		"\t\t\t** ##  ***	      *",
		"\t\t\t**D## *****	 @   **",
		"\t\t\t********************",
		};*/
void GenerateMap1(char mapa[13][13], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY) {
    int i, j;
    char layout[13][13] = {
        "\t\t\t*********",
        "\t\t\t**     **",
        "\t\t\t*       *",
        "\t\t\t*       *",
        "\t\t\t*  ******",
        "\t\t\t*  *@   *",
        "\t\t\t*  ***  *",
        "\t\t\t*  *D*  *",
        "\t\t\t*       *",
        "\t\t\t*********",
    };
    
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 13; j++) {
            mapa[i][j] = layout[i][j];
        }
    }
    mapa[PlayerY][PlayerX] = '&';
    if (newPlayer.chavePega) {
        mapa[ChaveY][ChaveX] = ' ';
        mapa[PortaY][PortaX] = '=';
    } else {
        mapa[ChaveY][ChaveX] = '@';
        mapa[PortaY][PortaX] = 'D';
    }
}


void PrintMap(char mapa[13][13]) {
    int i, j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 13; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

void PrintTuto() {
    printf("Tutorial\n");
    printf("'W' = Mover para cima\n'A' = Mover para a esquerda\n'S' = Mover para baixo\n'D' = Mover para a direita\n'I' = Interagir com objetos (Somente quando estiver embaixo do jogador)\n\n");
    printf("Voce (Player) tem apenas 3 vidas, seu objetivo eh pegar a '@' (Chave) para abrir a porta identificada como 'D' e concluir a fase.\n");
    printf("Tome cuidado! Conforme voce avanca no jogo a dificuldade ira aumentar.\n");
    printf("Esteja atento com inimigos e obstaculos identificados como 'X' (inimigo nivel 1),'V' (inimigo nivel 2) e '#' (Espinhos).\n");
    printf("Caso encoste em algum desses inimigos ou obstaculos a fase sera reiniciada.\n\n");
    printf("Obs: Aperte o botao ('O') encontrado em alguma fase e descubra algo secreto :)\n");

    printf("\nPressione qualquer tecla para voltar ao menu...\n");
    getch();
    system("cls");
}

void PlayerSettingsBase() { // função só para facilitar o reset do game 
    newPlayer.vivo = true;
    newPlayer.hp = 3;
    newPlayer.chavePega = false;

}

void sair() {
    printf("Saindo do jogo...\n");
    exit(0);
}

void Interact() {
    // Verifica se o jogador está na posição da chave
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !newPlayer.chavePega) {
        // Remove o '@' do mapa e marca como encontrado
        mapa[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        newPlayer.chavePega = true;
        printf("Voce pegou a chave '@'!\n");

        // Troca 'D' por '=' no mapa para indicar que a porta foi aberta
        mapa[newPlayer.PortaY][newPlayer.PortaX] = '=';
    } else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && newPlayer.chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    } else {
        printf("Nada para interagir aqui.\n");
    }
}

void GameStart() {
    newPlayer.PlayerX = 7; // Coordenada X inicial do jogador
    newPlayer.PlayerY = 1; // Coordenada Y inicial do jogador
    newPlayer.ChaveX = 7;
    newPlayer.ChaveY = 5;
    newPlayer.PortaX = 7;
    newPlayer.PortaY = 7;

    GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);

    char command;

    PrintMap(mapa);
    while (1) {
        command = getch();

        switch (command) {
            case 'W':
            case 'w':
                if (mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D') // Verifica se a próxima posição não é uma parede
                    newPlayer.PlayerY--;
                break;
            case 'S':
            case 's':
                if (mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D') // Verifica se a próxima posição não é uma parede
                    newPlayer.PlayerY++;
                break;
            case 'D':
            case 'd':
                if (mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D') // Verifica se a próxima posição não é uma parede
                    newPlayer.PlayerX++;
                break;
            case 'A':
            case 'a':
                if (mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D') // Verifica se a próxima posição não é uma parede
                    newPlayer.PlayerX--;
                break;
            case 'I':
            case 'i':
                Interact();
                break;
        }
        system("cls");
        GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
        PrintMap(mapa);
        if (mapa[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            system("cls");
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            break;
        }
    }
}

int main() {
    int option;
    bool tutorial = false;
    printf("\n\n");
    printf("\t\t\t88^^Yb 888888 88^^Yb 88   88 888888 88^^Yb 888888  .o. .dP'Y8   8888b. 88   88 88b 88  dP^^b8  888888  dP^Yb  88b 88\n");
    printf("\t\t\t88__dP 88__   88__dP 88   88 88__   88__dP 88__   ,dP' `Ybo.'   8I  Yb 88   88 88Yb88  dP   `' 88__   dP   Yb 88Yb88\n");
    printf("\t\t\t88^^^  88^^   88^^Yb Y8   8P 88^^   88^^Yb 88^^        o.`Y8b   8I  dY Y8   8P 88 Y88  Yb  ^88 88^^   Yb   dP 88 Y88\n");
    printf("\t\t\t88     888888 88  Yb ^YbodP^ 888888 88  Yb 888888      8bodP^   8888Y' `YbodP' 88  Y8  YboodP  888888  YbodP  88  Y8\n");
    printf("\n\n");
    do {
        printf("\t1 - Jogar\n\t2 - Tutorial\n\t3 - Sair\n");
        scanf("%d", &option);
        system("cls");

        switch (option) {
            case 1:
                PlayerSettingsBase();
                GameStart(); // Iniciar o Jogo
                break;
            case 2:
                system("cls");
                PrintTuto();
                if (!tutorial) {
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
