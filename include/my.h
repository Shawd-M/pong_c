#ifndef MY_H
#define MY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SOCKET_ERROR -1

#define NBLOCS_WIDTH 15 // nombre a afficher en x et y
#define NBLOCS_HEIGHT 13

#define WIDTH_TILE 24 // hauteur et largeur des tiles.
#define HEIGHT_TILE 24

enum
{
    TOP,
    BOT,
    LEFT,
    RIGHT
};

typedef int SOCKET;
void Ball_movement();
void clear();
void Createwindow();
void clearPlayer();
void clearScreen();
int client(int Port, char *Ip);
void draw(int player_number);
void drawEnd(int status);
void drawMenu();
void drawPlayer(SDL_Renderer *screen, int player_number);
void endGame();
void init();
void intBallDir(int player);
void initPlayerSprites(SDL_Renderer *screen);
int game(int idpPlayer, SOCKET socket);
int getPoint(int player);
SDL_Renderer *getscreen();
void move(int player, int direction);
void ScreenEnd(int status);
void ScreenMenu();
int setWindowColor();
int serveur(int Port);

#endif