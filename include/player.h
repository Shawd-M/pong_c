#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>

SDL_Surface *player1;
SDL_Texture *player1_screen;
SDL_Rect player1_p;

SDL_Surface *player2;
SDL_Texture *player2_screen;
SDL_Rect player2_p;

SDL_Surface *Balle;
SDL_Texture *ball_screen;
SDL_Rect ball_pos;

#endif