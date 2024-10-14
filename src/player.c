#include "../include/player.h"

enum
{
    TOP,
    BOT,
    LEFT,
    RIGHT
};
int dir_top = RIGHT;
int dir_bot = BOT;
int score_player1 = 0;
int score_player2 = 0;

// Initialisation de la position des joueurs et de la Balle
void initPlayerSprites(SDL_Renderer *screen)
{
    // Image du joueur
    player1 = IMG_Load("img/img_Player1.png");
    player1_screen = SDL_CreateTextureFromSurface(screen, player1);
    // Position + dimension
    player1_p.x = 40;
    player1_p.y = 100;
    player1_p.w = 10;
    player1_p.h = 100;

    player2 = IMG_Load("img/img_Player2.png");
    player2_screen = SDL_CreateTextureFromSurface(screen, player2);
    player2_p.x = 310;
    player2_p.y = 100;
    player2_p.w = 10;
    player2_p.h = 100;

    Balle = IMG_Load("img/img_Ball.png");
    ball_screen = SDL_CreateTextureFromSurface(screen, Balle);
    ball_pos.x = 170;
    ball_pos.y = 150;
    ball_pos.w = 20;
    ball_pos.h = 20;
}

// Donner la direction de la Balle au début de partie
void intBallDir(int player)
{
    if (player == 1)
    {
        dir_top = RIGHT;
    }
    else if (player == 2)
    {
        dir_top = LEFT;
    }
}

// Dessiner les joueurs et la Balle
void drawPlayer(SDL_Renderer *screen, int player_number)
{
    switch (player_number)
    {
    case 1:
        SDL_RenderCopy(screen, player1_screen, NULL, &player1_p);
        break;

    case 2:
        SDL_RenderCopy(screen, player1_screen, NULL, &player1_p);
        SDL_RenderCopy(screen, player2_screen, NULL, &player2_p);
        break;
    }

    SDL_RenderCopy(screen, ball_screen, NULL, &ball_pos);
}

// Fonction de mouvement
void move(int player, int direction)
{
    SDL_Rect *position = NULL;
    if (player == 1)
    {
        position = &player1_p;
    }
    else if (player == 2)
    {
        position = &player2_p;
    }
    switch (direction)
    {
    case TOP:
        if (position->y > 0)
        {
            position->y -= 7;
        }
        break;

    case BOT:
        if (position->y < 210)
        {
            position->y += 7;
        }
        break;
    }
}

// Réinitialiser la position de la Balle au milieu de l'écran
void resetBall()
{
    SDL_Rect *position = &ball_pos;
    position->x = 170;
    position->y = 150;
    if (dir_top == RIGHT)
    {
        dir_top = LEFT;
    }
    else
    {
        dir_top = RIGHT;
    }
}

// Obtenir le nombre de point du joueur
int getPoint(int player)
{
    if (player == 1)
    {
        return score_player1;
    }
    else
    {
        return score_player2;
    }
}

// Mouvement de la Balle
void Ball_movement()
{
    SDL_Rect *position = &ball_pos;
    SDL_Rect *player1_init_pos = &player1_p;
    SDL_Rect *player2_init_pos = &player2_p;
    switch (dir_top)
    {
    case RIGHT:
        if (position->x < 340)
        {
            position->x += 3;
        }
        else
        {
            resetBall();
            score_player1++;
        }
        if (position->x >= player2_init_pos->x - 20)
        {
            if (position->y >= player2_init_pos->y - 20 && position->y <= player2_init_pos->y + 99)
            {
                dir_top = LEFT;
            }
        }
        break;

    case LEFT:
        if (position->x > 0)
        {
            position->x -= 3;
        }
        else
        {
            resetBall();
            score_player2++;
        }
        if (position->x <= player1_init_pos->x + 10)
        {
            if (position->y >= player1_init_pos->y - 20 && position->y <= player1_init_pos->y + 99)
            {
                dir_top = RIGHT;
            }
        }
        break;
    }

    //Collision de la Balle en haut/bas de l'écran
    switch (dir_bot)
    {
    case TOP:
        if (position->y > 0)
        {
            position->y -= 2;
        }
        else
        {
            dir_bot = BOT;
        }
        break;

    case BOT:
        if (position->y < 290)
        {
            position->y += 2;
        }
        else
        {
            dir_bot = TOP;
        }
        break;
    }
}

// Clear texture des joueurs + Balle
void clearPlayer()
{
    SDL_DestroyTexture(player1_screen);
    SDL_FreeSurface(player1);
    SDL_DestroyTexture(player2_screen);
    SDL_FreeSurface(player2);
    SDL_DestroyTexture(ball_screen);
    SDL_FreeSurface(Balle);
}