#include "../include/my.h"
#include "../include/var.h"
#include "../include/serveur.h"
#include <sys/socket.h>

int main()
{
    //variables
    int port = 4444;
    char *clients = "127.0.0.1";
    bool Menu = true;
    SDL_Event event;

    // Initilisation des ressources
    init();

    while (Menu == true)
    {
        drawMenu();
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_h:
                printf("Trying to host\n");
                serveur(port);
                Menu = false;
                break;

            case SDLK_j:
                printf("Trying to join the game\n");
                client(port, clients);
                Menu = false;
                break;

            case SDLK_q:
                Menu = false;
                break;
            }
            break;
        }
    }

    return 0;
}
// Fonction de jeu principale
int game(int idpPlayer, SOCKET socket)
{
    bool quit = false;
    bool first = true;
    int timer = 0;
    char rbuff[32];
    bool game = true;

    while (!quit)
    {
        if (first == true)
        {
            send(socket, "OK", 32, 0);
        }
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {

                case SDLK_UP:
                    move(idpPlayer, TOP);
                    send(socket, "T", 32, 0);
                    break;

                case SDLK_DOWN:
                    move(idpPlayer, BOT);
                    send(socket, "B", 32, 0);
                    break;
                }
                break;
            }
        }
        if (game)
        {
            //Selon le timer, la Balle va plus ou moins vite
            if (timer < 80)
            {
                timer++;
            }
            else
            {
                timer = 0;
                Ball_movement();
            }
            //Ce que reçois l'autre serveur
            if (recv(socket, rbuff, 32, 0) != SOCKET_ERROR)
            {
                if (strcmp(rbuff, "T") == 0)
                {
                    move(2, TOP);
                }
                else if (strcmp(rbuff, "B") == 0)
                {
                    move(2, BOT);
                }
            }
            draw(2);
        }
        int player1_score = getPoint(1);
        int player2_score = getPoint(2);
        if (player1_score == 2)
        {
            drawEnd(1);
            game = false;
        }
        else if (player2_score == 2)
        {
            game = false;
            drawEnd(2);
        }
    }
    endGame();

    return 0;
}
