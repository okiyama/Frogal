/*
 * Test file which is meant for playing around with
 * and testing things out. Like learning SDL and stuff like that.
 * Author: Julian Jocque
 */
using namespace std;
#include <iostream>
#include <sdl_class.h>
#include <SDL2/SDL.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 400;

int main(int argc, char* args[]) {
    SDL_Class SDL_funcs(SCREEN_WIDTH, SCREEN_HEIGHT);

    //char filename[] = "../graphics/Characters/Cat0.png";
    char filename[] = "../graphics/hello_world.bmp";
    if(!SDL_funcs.load_media(filename)) {
        printf("Failed to load media!\n");
    }
    SDL_funcs.quit();
    return 0;
}
