/*
 * A class that runs SDL commands for init and things like then 
 * then returns the relevant objects.
 * Author: Julian Jocque
 */
using namespace std;
#include <iostream>
#include <SDL2/SDL.h>
#include <sdl_class.h>
#include <SDL2/SDL_image.h>

/**
 * Constructor, initializes everything we need.
 */
SDL_Class::SDL_Class(int width, int height):
    window_width(width),
    window_height(height),
    window(init_window(window_width, window_height)),
    surface(init_surface(window))
{
}

/**
 * Initializes an SDL_Window pointer then returns it. Returns a nullptr on failure.
 */
SDL_Window* SDL_Class::init_window(int height, int width) {
    SDL_Window* win = SDL_CreateWindow("Learning SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        cout << "Couldn't create window! Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    return win;
}

/**
 * Initializes an SDL_Surface pointer then returns it. Returns a nullptr on failure.
 */
SDL_Surface* SDL_Class::init_surface(SDL_Window *givenWindow) {
    //Get window surface from the window
    SDL_Surface* toRet = SDL_GetWindowSurface(givenWindow);
    if (surface == nullptr) {
        cout << "Surface failed to create!\n" << std::endl;
        return nullptr;
    }
    return toRet;
}

/**
 * Init SDL along with a window and a surface to work with.
 */
bool SDL_Class::init_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL failed to initialize. Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

/**
 * Blits an image onto the surface member variable.
 */
bool SDL_Class::load_media(char* filename) {
    SDL_Surface* image = IMG_Load(filename);
    //image = SDL_LoadBMP(filename);
    if (image == NULL) {
        cout << "Unable to load image " << filename << "! Error: " << SDL_GetError() << std::endl;
        return false;
    }
    else {
        //apply image
        SDL_BlitSurface(image, NULL, surface, NULL);
        
        //SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);

        SDL_FreeSurface(image);
        //delete image;

        SDL_Delay(2000);
    }

    return true;
}

/**
 * Closes the SDL window and cleans objects
 */
void SDL_Class::quit() {
    cout << "Quitting" << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
}

