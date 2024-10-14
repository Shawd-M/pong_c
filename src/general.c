#include "../include/my.h"

SDL_Renderer *screenRender = NULL;

void init()
{
    //va initialiser la vidéo
    SDL_Init(SDL_INIT_VIDEO);

    //ensuite créé la fenêtre
    Createwindow();
    screenRender = getscreen();

    //pour finir le player
    initPlayerSprites(screenRender);
}

void draw(int player_number)
{
    //Va mettre les couleurs
    SDL_RenderClear(screenRender);

    //Celle du player
    drawPlayer(screenRender, player_number);

    //Va update l'écran
    SDL_RenderPresent(screenRender);
}

// Dessiner le menu
void drawMenu()
{
    SDL_RenderClear(screenRender);

    ScreenMenu();

    SDL_RenderPresent(screenRender);
}

//Fonction de fin de jeu
void drawEnd(int status)
{
    SDL_RenderClear(screenRender);

    ScreenEnd(status);

    SDL_RenderPresent(screenRender);
}

// Fonction qui clear l'écran et quitte le jeu
void endGame()
{
    clear();
    SDL_Quit();
}

// Fonction qui clear l'écran
void clear()
{
    clearPlayer();
    clearScreen();
}