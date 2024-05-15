#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

char mapa[23][23];
char mapa2[13][13];

typedef struct {
    bool vivo;
    char nome[16];
    int hp;
    int PlayerX;
    int PlayerY;
    int ChaveX;
    int ChaveY;
    int PortaX;
    int PortaY;
    int BotaoX;
    int BotaoY;
    bool chavePega;
} player;

int continuar = 1;
player newPlayer;
int level = 2;
void GenerateMap1(char mapa[23][23], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY, int monsteX, int monsteY, int BotaoX, int BotaoY) {
    int i, j;
    

    if (level == 1) {
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
		newPlayer.PortaX = 7;
		newPlayer.PortaY = 7;
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 13; j++) {
                mapa[i][j] = layout[i][j];
                
            }
        }
    } else if (level == 2) {
        char layout2[23][23] = {
            "\t\t\t********************",
            "\t\t\t**        *****#O#**",
            "\t\t\t*          ****   **",
            "\t\t\t*           ***  #**",
            "\t\t\t*            **   **",
            "\t\t\t*             *#  **",
            "\t\t\t*                  *",
            "\t\t\t**                **",
            "\t\t\t*                  *",
            "\t\t\t**                **",
            "\t\t\t***              ***",
            "\t\t\t***              ***",
            "\t\t\t***              ***",
            "\t\t\t**                **",
            "\t\t\t*                  *",
            "\t\t\t**      *          *",
            "\t\t\t** ##  ***         *",
            "\t\t\t**D## *****   @   **",
            "\t\t\t********************",
        };
        newPlayer.PortaX = 5; // Ajuste das coordenadas da porta para ficarem dentro dos limites do mapa
    	newPlayer.PortaY = 17;
		
        
        for (i = 0; i < 23; i++) {
            for (j = 0; j < 23; j++) {
                mapa[i][j] = layout2[i][j];
            }
        }
    }
    mapa[PlayerY][PlayerX] = '&';
    mapa[monsteY][monsteX] = 'X';
    if(level==2){
    	mapa[BotaoX][BotaoY] = 'O';
	}
    else if (newPlayer.chavePega) {
        mapa[ChaveY][ChaveX] = ' ';
        mapa[PortaY][PortaX] = '=';
    } else {
        mapa[ChaveY][ChaveX] = '@';
        mapa[PortaY][PortaX] = 'D';
    }
}

void PrintMap(char mapa[23][23]) {
    int i, j;
    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}
void PrintMap2(char mapa2[13][13]) {
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

void PlayerSettingsBase() {
    newPlayer.vivo = true;
    newPlayer.hp = 3;
    newPlayer.chavePega = false;
    const int limiteEspinhos = 3;
}

void sair() {
    printf("Saindo do jogo...\n");
    exit(0);
}

void Interact() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !newPlayer.chavePega) {
        mapa[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        newPlayer.chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && newPlayer.chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("BAZINGA");
	}
    else {
        printf("Nada para interagir aqui.\n");
    }
}

void monstmov(int *monsteX, int *monsteY) {
    int n = 4;

    int movement = rand() % (n + 1);

    if (movement == 1) {
        (*monsteX)++;
    } else if (movement == 2) {
        (*monsteX)--;
    } else if (movement == 3) {
        (*monsteY)++;
    } else {
        (*monsteY)--;
    }
}


void GameStart() {
int monsteX = -1, monsteY = -1;
const int limiteEspinhos = 3;
newPlayer.hp = 3;
    if (level == 1) {
        newPlayer.PlayerX = 7;
        newPlayer.PlayerY = 1;
        
        newPlayer.ChaveX = 7;
        newPlayer.ChaveY = 5;

        newPlayer.PortaX = 7;
        newPlayer.PortaY = 7;
        

    } else if (level == 2) {
        newPlayer.PlayerX = 6;
        newPlayer.PlayerY = 1;

        newPlayer.ChaveX = 17;
        newPlayer.ChaveY = 17;

        newPlayer.PortaX = 5;
        newPlayer.PortaY = 17;
        
		newPlayer.BotaoX = 1;
        newPlayer.BotaoY = 19;

        monsteX = 18;
        monsteY = 14;
    }

    GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY,newPlayer.BotaoX,newPlayer.BotaoY);

    char command;

    PrintMap(mapa);
    while (1) {
        command = getch();

        switch (command) {
        case 'W':
        case 'w':
            if (mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D')
                newPlayer.PlayerY--;
         
            break;
        case 'S':
        case 's':
            if (mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D')
                newPlayer.PlayerY++;
         
            break;
        case 'D':
        case 'd':
            if (mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D')
                newPlayer.PlayerX++;
        
            break;
        case 'A':
        case 'a':
            if (mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D')
                newPlayer.PlayerX--;
          
            break;
        case 'I':
        case 'i':
            Interact();
            break;
        }
        if (level == 2) {
        int tempX = monsteX, tempY = monsteY;
        monstmov(&tempX, &tempY); // Movimento temporário do monstro

        // Verifica se o movimento do monstro colide com parede ou espinhos
        if (mapa[tempY][tempX] != '*' && mapa[tempY][tempX] != '#') {
            monsteX = tempX;
            monsteY = tempY;
        }
    }
        if (mapa[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
            newPlayer.hp--;
            printf("Voce encostou nos espinhos! Perdeu vida %d vezes.\n", newPlayer.hp);
            // Verificar se o jogador excedeu o limite de toques nos espinhos
            if (newPlayer.hp == 0) {
                // Se sim, o jogador morre
                printf("Voce encostou nos espinhos %d vezes e morreu!\n", limiteEspinhos);
                printf("Fim de jogo!\n");
                exit(0); // Ou faça qualquer ação de reiniciar o jogo ou a fase
            }
        }
        system("cls");
        GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
        PrintMap(mapa);
        if (mapa[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            system("cls");
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            level = 2;
            system("pause");
            system("cls");
            printf("\n\n");
    		printf("\t\t\t88^^Yb 888888 88^^Yb 88   88 888888 88^^Yb 888888  .o. .dP'Y8   8888b. 88   88 88b 88  dP^^b8  888888  dP^Yb  88b 88\n");
   		    printf("\t\t\t88__dP 88__   88__dP 88   88 88__   88__dP 88__   ,dP' `Ybo.'   8I  Yb 88   88 88Yb88  dP   `' 88__   dP   Yb 88Yb88\n");
    		printf("\t\t\t88^^^  88^^   88^^Yb Y8   8P 88^^   88^^Yb 88^^        o.`Y8b   8I  dY Y8   8P 88 Y88  Yb  ^88 88^^   Yb   dP 88 Y88\n");
    		printf("\t\t\t88     888888 88  Yb ^YbodP^ 888888 88  Yb 888888      8bodP^   8888Y' `YbodP' 88  Y8  YboodP  888888  YbodP  88  Y8\n");
    		printf("\n\n");
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
            GameStart();
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
            sair();
            break;
        default:
            printf("Opção invalida.");
        }
    } while (option != 3);

    getch();
    return 0;
}
