#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

char command;

char mapa[13][13];
char mapa2[23][23];
char mapa3[43][43];

bool chavePega;

typedef struct {
    char nome[16];
    bool vivo;
    int hp;
    int PlayerX;
    int PlayerY;
    int ChaveX;
    int ChaveY;
    int PortaX;
    int PortaY;
    int BotaoX;
    int BotaoY;
} player;

int continuar = 1;

player newPlayer;

int level = 1;

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
		newPlayer.PortaX = 7;
		newPlayer.PortaY = 7;
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 13; j++) {
                mapa[i][j] = layout[i][j];
                
            }
        }
    mapa[PlayerY][PlayerX] = '&';
    if (chavePega == true) {
        mapa[ChaveY][ChaveX] = ' ';
        mapa[PortaY][PortaX] = '=';
    } else {
        mapa[ChaveY][ChaveX] = '@';
        mapa[PortaY][PortaX] = 'D';
    }
}

void GenerateMap2(char mapa2[23][23], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY, int monsteX, int monsteY, int BotaoX, int BotaoY) {
        int i, j;
        
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
                mapa2[i][j] = layout2[i][j];
            }
        }
    
    mapa2[PlayerY][PlayerX] = '&';
    mapa2[monsteY][monsteX] = 'X';
    mapa2[BotaoX][BotaoY] = 'O';

    if (chavePega == true) {
        mapa2[ChaveY][ChaveX] = ' ';
        mapa2[PortaY][PortaX] = '=';
    } else {
        mapa2[ChaveY][ChaveX] = '@';
        mapa2[PortaY][PortaX] = 'D';
    }
}

void GenerateMap3(char mapa3[43][43], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY, int monsteX, int monsteY,int monste2X,int monste2Y, int BotaoX, int BotaoY) {
    int i,j;
    
    char layout3[43][43] = {
            "\t*****************************************",
            "\t**                 *         #@#       **",
            "\t*                  *         # #        *",
            "\t*                  *    #               *",
            "\t*      #           *                 #  *",
            "\t*                  *                    *",
            "\t*            #     *    #               *",
            "\t*                  *                    *",
            "\t*                  *                 #  *",
            "\t*    #   X         *                    *",
            "\t*                  *    #               *",
            "\t*                  *                    *",
            "\t*                  *             #      *",
            "\t*                  *                    *",
            "\t*             #    *    #               *",
            "\t* <                *                  > *",
            "\t*                  *                    *",
            "\t*                  *                    *",
            "\t*                  *                #   *",
            "\t*      #           *                    *",
            "\t*                  *                    *",
            "\t*                  *      #             *",
            "\t*                  *                  O *",
            "\t*             #    *          #         *",
            "\t*   #              *                    *",
            "\t*                  *                 #  *",
            "\t*                  *                    *",
            "\t*                  *                    *",
            "\t*             #    *      #             *",
            "\t*     #            *                    *",
            "\t*                  *                    *",
            "\t*                  *                    *",
            "\t*             #    *                    *",
            "\t*                  *                    *",
            "\t*                  *         V          *",
            "\t*    #             *                    *",
            "\t*                  *                    *",
            "\t*                  *                    *",
            "\t**     # D #       *        #          **",
            "\t*****************************************",
        };

        for(i = 0; i < 43; i++) {
            for(j = 0; j < 43; j++) {
                mapa3[i][j] = layout3[i][j];
            }
        }

    mapa3[PlayerY][PlayerX] = '&';
    mapa3[monsteY][monsteX] = 'X';
    mapa3[monste2Y][monste2X] = 'V';
    mapa3[BotaoX][BotaoY] = 'O';
    if (chavePega == true) {
        mapa3[ChaveY][ChaveX] = ' ';
        mapa3[PortaY][PortaX] = '=';
    } else {
        mapa3[ChaveY][ChaveX] = '@';
        mapa3[PortaY][PortaX] = 'D';
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
void PrintMap2(char mapa2[23][23]) {
    int i, j;
    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            printf("%c", mapa2[i][j]);
        }
        printf("\n");
    }
}
void PrintMap3(char mapa3[43][43]) {
    int i, j;
    for (i = 0; i < 43; i++) {
        for (j = 0; j < 43; j++) {
            printf("%c", mapa3[i][j]);
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
    chavePega = false;
}

void sair() {
    printf("Saindo do jogo...\n");
    exit(0);
}

void Interact() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapa[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("BAZINGA");
	}
    else {
        printf("Nada para interagir aqui.\n");
    }
}

void Interact2() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapa2[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa2[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("BAZINGA");
	}
    else {
        printf("Nada para interagir aqui.\n");
    }
}

void Interact3() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapa3[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa3[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("PROCURO AMOR RECIPROCO");
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
void monstmov2(int *monste2X, int *monste2Y) {
    int n = 4;

    int movement = rand() % (n + 1);

    if (movement == 1) {
        (*monste2X)++;
    } else if (movement == 2) {
        (*monste2X)--;
    } else if (movement == 3) {
        (*monste2Y)++;
    } else {
        (*monste2Y)--;
    }
}

void mapa3start(){
    newPlayer.hp = 3;

    newPlayer.PlayerX = 10;
    newPlayer.PlayerY = 1;
        
    newPlayer.ChaveX = 31;
    newPlayer.ChaveY = 1;

    newPlayer.PortaX = 10;
    newPlayer.PortaY = 38;

    newPlayer.BotaoX = 22;
    newPlayer.BotaoY = 39;
    
    int monsteX = 20;
    int monsteY = 14;
    
    int monste2X = 20;
    int monste2Y = 10;

    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY);
    
    char command;
    PrintMap3(mapa3);

    while (1) {
        command = getch();

        switch (command) {
            case 'W':
            case 'w':
                if (mapa3[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa3[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D') {
                    newPlayer.PlayerY--;
                    
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        // Verificar se o jogador excedeu o limite de toques nos espinhos
                        if (newPlayer.hp == 0) {
                            // Se sim, o jogador morre
                            printf("Fim de jogo! Você perdeu todas as vidas.\n");
                            exit(0);
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY);
                    PrintMap3(mapa3);
                }
                break;
            case 'S':
            case 's':
                if (mapa3[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa3[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D') {
                    newPlayer.PlayerY++;
                    
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        // Verificar se o jogador excedeu o limite de toques nos espinhos
                        if (newPlayer.hp == 0) {
                            // Se sim, o jogador morre
                            printf("Fim de jogo! Você perdeu todas as vidas.\n");
                            exit(0);
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY);
                    PrintMap3(mapa3);
                }
                break;
            case 'D':
            case 'd':
                if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa3[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D') {
                    newPlayer.PlayerX++;
                    
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        // Verificar se o jogador excedeu o limite de toques nos espinhos
                        if (newPlayer.hp == 0) {
                            // Se sim, o jogador morre
                            printf("Fim de jogo! Você perdeu todas as vidas.\n");
                            exit(0);
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY);
                    PrintMap3(mapa3);
                }
                break;
            case 'A':
            case 'a':
                if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa3[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D') {
                    newPlayer.PlayerX--;
                    
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        // Verificar se o jogador excedeu o limite de toques nos espinhos
                        if (newPlayer.hp == 0) {
                            // Se sim, o jogador morre
                            printf("Fim de jogo! Você perdeu todas as vidas.\n");
                            exit(0);
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY);
                    PrintMap3(mapa3);
                }
                break;
            case 'I':
            case 'i':
                Interact3();
                break;
        }
        if(mapa3){
        int tempX = monsteX, tempY = monsteY;
        int temp2X = monste2X, temp2Y = monste2Y;
        monstmov(&tempX, &tempY); // Movimento temporário do monstro
        monstmov2(&tempX, &tempY);   
        // Verifica se o movimento do monstro colide com parede ou espinhos
        if (mapa3[tempY][tempX] != '*' && mapa3[tempY][tempX] != '#' && mapa3[temp2Y][temp2X] != '*' && mapa3[temp2Y][temp2X] != '#') {
            monsteX = tempX;
            monsteY = tempY;
            monste2X = temp2X;
            monste2Y = temp2Y;
        }
    }
        if (mapa3[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            system("cls");
            chavePega = false;
            exit(0);
        }
    }
}

     

void mapa2start(){
    newPlayer.hp = 3;

    newPlayer.PlayerX = 6;
    newPlayer.PlayerY = 1;
        
    newPlayer.ChaveX = 17;
    newPlayer.ChaveY = 17;

    newPlayer.PortaX = 5;
    newPlayer.PortaY = 17;

    newPlayer.BotaoX = 1;
    newPlayer.BotaoY = 19;
    
    int monsteX = 18;
    int monsteY = 14;
    
    GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
    
    char command;
    PrintMap2(mapa2);

    while (1) {
        command = getch();

        switch (command) {
        case 'W':
        case 'w':
            if (mapa2[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa2[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D'){
                newPlayer.PlayerY--;
                
                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                    newPlayer.hp--;
                    printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                    // Verificar se o jogador excedeu o limite de toques nos espinhos
                    if (newPlayer.hp == 0) {
                    // Se sim, o jogador morre
                        printf("Fim de jogo! Você perdeu todas as vidas.\n");
                        exit(0);
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            }
            break;
        case 'S':
        case 's':
            if (mapa2[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa2[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D'){
                newPlayer.PlayerY++;
                
                
                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                newPlayer.hp--;
                printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                // Verificar se o jogador excedeu o limite de toques nos espinhos
                if (newPlayer.hp == 0) {
                // Se sim, o jogador morre
                printf("Fim de jogo! Você perdeu todas as vidas.\n");
                exit(0);
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            }
            break;
        case 'D':
        case 'd':
            if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa2[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D'){
                newPlayer.PlayerX++;
                

                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                newPlayer.hp--;
                printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                // Verificar se o jogador excedeu o limite de toques nos espinhos
            if (newPlayer.hp == 0) {
                // Se sim, o jogador morre
                printf("Fim de jogo! Você perdeu todas as vidas.\n");
                exit(0);
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            }
            break;
        case 'A':
        case 'a':
            if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa2[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D'){
                newPlayer.PlayerX--;
                
                
                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                newPlayer.hp--;
                printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                // Verificar se o jogador excedeu o limite de toques nos espinhos
                if (newPlayer.hp == 0) {
                // Se sim, o jogador morre
                printf("Fim de jogo! Você perdeu todas as vidas.\n");
                exit(0);
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            }
            break;
        case 'I':
        case 'i':
            Interact2();
            break;
        }
        if(mapa2) {
        int tempX = monsteX, tempY = monsteY;
        monstmov(&tempX, &tempY); // Movimento temporário do monstro

        // Verifica se o movimento do monstro colide com parede ou espinhos
        if (mapa2[tempY][tempX] != '*' && mapa[tempY][tempX] != '#') {
            monsteX = tempX;
            monsteY = tempY;
        }
    }

        if (mapa2[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            system("cls");
            chavePega = false;
            system("pause");
            mapa3start();
        }
    }
}


void mapa1start() {
    // Inicialização da posição do jogador e outros elementos do mapa
    newPlayer.hp = 3;
    
    newPlayer.PlayerX = 7;
    newPlayer.PlayerY = 1;
        
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
            // Condição para mover para cima
            if (mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D') {
                newPlayer.PlayerY--; // Atualização da posição do jogador
                system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap(mapa);
            }
            break;
        case 'S':
        case 's':
            // Condição para mover para baixo
            if (mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D') {
                newPlayer.PlayerY++; // Atualização da posição do jogador
                system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap(mapa);
            }
            break;
        case 'D':
        case 'd':
            // Condição para mover para direita
            if (mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D') {
                newPlayer.PlayerX++; // Atualização da posição do jogador
                system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap(mapa);
            }
            break;
        case 'A':
        case 'a':
            // Condição para mover para esquerda
            if (mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D') {
                newPlayer.PlayerX--; // Atualização da posição do jogador
                system("cls"); // Limpar a tela antes de atualizar e imprimir o mapa
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap(mapa);
            }
            break;
        case 'I':
        case 'i':
            Interact();
            break;
        }
        // Verificação de colisão com espinhos
        if (mapa[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
            newPlayer.hp--;
            printf("Perdeu vida %d vezes.\n", newPlayer.hp);
            // Verificar se o jogador excedeu o limite de toques nos espinhos
            if (newPlayer.hp == 0) {
                // Se sim, o jogador morre
                printf("Fim de jogo!\n");
                exit(0);
            }
        }
        if (mapa[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            system("cls");
            chavePega = false;
            system("pause");
            mapa2start();
            
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
            mapa1start();
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
