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

    ///////////////
    // Main Loop //
    ///////////////
    bool quit = false;

    while (!quit)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            
        }
        
    }

    //////////////////////
    // Cleanup and Exit //
    //////////////////////
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return EXIT_SUCCESS;
}