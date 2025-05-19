#include <SDL2/SDL.h>
#include <stdio.h>
#include "extra_file.h"
#include <stdbool.h>
#include <stdlib.h>

int main(int argv, char** args)
{
    (void)argv;
    (void)args;

    print_from_lib();

    //////////////////////////////////
    // Initialize the SDL Subsystem //
    //////////////////////////////////
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("Error ---> %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    /////////////////////////////
    // Create a new SDL Window //
    /////////////////////////////
    SDL_Window *window = SDL_CreateWindow(
        "SuperMega",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        800,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        SDL_Log("Error ---> %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    /////////////////////////
    // Create SDL Renderer //
    /////////////////////////
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if(!renderer)
    {
        SDL_Log("Error on creating render: %s",SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    ///////////////
    // Main Loop //
    ///////////////

    SDL_RenderClear(renderer);

    bool quit = false;

    while (!quit)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            /////////////////////////////////////
            // Polling Events are handled here //
            /////////////////////////////////////
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_MOUSEBUTTONDOWN:
                printf("Mouse buttone has been pressed\n");

            default:
                break;
            }

            /////////////////////////////
            // Game State Updated Here //
            /////////////////////////////

        }

    }

    //////////////////////
    // Cleanup and Exit //
    //////////////////////
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
