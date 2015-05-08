/*
 * Test file which is meant for playing around with
 * and testing things out. Like learning SDL and stuff like that.
 * Author: Julian Jocque
 */
using namespace std;
#include <stdio.h>
#include <sdl_class.h>
#include <SDL2/SDL.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 400;

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;
    SDL_Surface* image = NULL;
    SDL_Class* SDL_funcs(SCREEN_WIDTH, SCREEN_HEIGHT);

    if(!SDL_funcs->init(window, screenSurface)) {
        print("Failed to init!\n");
    }
    else {
        if(!SDL_funcs->load_media(image, "../graphics/Characters/Cat0.png")) {
            printf("Failed to load media!\n");
        }
        else {
            //apply image
            SDL_BlitSurface(image, NULL, screenSurface, NULL);

            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);
        }
    }
    SDL_funcs->quit(image, window);
    return 0;
}
