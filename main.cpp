#include <SDL3/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Cross Shape (SDL3)", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);


    int running = 1;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int w, h;
        SDL_GetWindowSize(window, &w, &h);

        float cx = w / 2.0f;
        float cy = h / 2.0f;

        float size = 100.0f;
        float offset = 120.0f;

        SDL_FRect top = { cx - size / 2, cy - offset - size / 2, size, size };
        SDL_FRect bottom = { cx - size / 2, cy + offset - size / 2, size, size };
        SDL_FRect left = { cx - offset - size / 2, cy - size / 2, size, size };
        SDL_FRect right = { cx + offset - size / 2, cy - size / 2, size, size };

       
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   
        SDL_RenderFillRect(renderer, &top);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);   
        SDL_RenderFillRect(renderer, &bottom);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);   
        SDL_RenderFillRect(renderer, &left);

        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 
        SDL_RenderFillRect(renderer, &right);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}