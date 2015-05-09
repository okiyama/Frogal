/*
 * A class that runs SDL commands for init and things like then 
 * then returns the relevant objects.
 * Author: Julian Jocque
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <sdl_class.h>
#include <SDL2/SDL_image.h>

/**
 * Constructor, just sets the width and height for now.
 */
SDL_Class::SDL_Class(int width, int height) {
    window_width = width;
    window_height = height;
}

/**
 * Init SDL along with a window and a surface to work with.
 */
bool SDL_Class::init(SDL_Window* window, SDL_Surface* surface) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL failed to initialize. Error: %s\n", SDL_GetError());
        return false;
    }
    else {
        window = SDL_CreateWindow("Learning SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Couldn't create window! Error: %s\n", SDL_GetError());
            return false;
        }
        else {
            //Get window surface from the window
            surface = SDL_GetWindowSurface(window);
        }
    }
    return true;
}

/**
 * Loads an image onto the given surface.
 */
bool SDL_Class::load_media(SDL_Surface* image, char* filename) {
    image = IMG_Load(filename);
    if (image == NULL) {
        printf("Unable to load image %s! Error: %s", filename, SDL_GetError());
        return false;
    }

    return true;
}

/**
 * Closes the SDL window and cleans objects
 */
void SDL_Class::quit(SDL_Surface* image, SDL_Window* window) {
    SDL_FreeSurface(image);
    delete image;
    SDL_DestroyWindow(window);
    SDL_Quit();
}

