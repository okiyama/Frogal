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
 * Constructor, just sets the width and height for now.
 */
SDL_Class::SDL_Class(int width, int height) {
    const int window_width = width;
    const int window_height = height;
    init_SDL();
    cout << "Initing window" << std::endl;
    SDL_Window* window = init_window(window_width, window_height);
    //SDL_Window* window = SDL_CreateWindow("Learning SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
    cout << "Initing surface" << std::endl;
    SDL_Surface* surface = init_surface(window);
    //SDL_Surface* surface = SDL_GetWindowSurface(window);
    cout << "Done with init!" << std::endl;
    cout << "Window is now: " << window << std::endl;
    cout << "Surface is now: " << surface << std::endl;
}

/**
 * Initializes and SDL_Window pointer then returns it. Returns a nullptr on failure.
 */
SDL_Window* SDL_Class::init_window(int height, int width) {
    SDL_Window* window = SDL_CreateWindow("Learning SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
    cout << "Window is:" << &window << std::endl;
    if (window == NULL) {
        printf("Couldn't create window! Error: %s\n", SDL_GetError());
        return nullptr;
    }
    return window;
}

/**
 * Initializes an SDL_Surface pointer then returns it. Returns a nullptr on failure.
 */
SDL_Surface* SDL_Class::init_surface(SDL_Window *givenWindow) {
    //Get window surface from the window
    cout << "Window in init surface is: " << givenWindow << std::endl;
    SDL_Surface* surface = NULL;
    surface = SDL_GetWindowSurface(givenWindow);
    cout << "Surface is: " << surface << std::endl;
    if (surface == NULL) {
        cout << "Surface failed to create!\n" << std::endl;
        return nullptr;
    }
    return surface;
}

/**
 * Init SDL along with a window and a surface to work with.
 */
bool SDL_Class::init_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL failed to initialize. Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

/**
 * Blits an image onto the surface member variable.
 */
bool SDL_Class::load_media(char* filename) {
    //image = IMG_Load(filename);
    cout << "Loading image" << std::endl;
    SDL_Surface* image = SDL_LoadBMP(filename);
    cout << "Image is now: " << image << std::endl;
    if (image == NULL) {
        printf("Unable to load image %s! Error: %s", filename, SDL_GetError());
        return false;
    }
    else {
        //apply image
        SDL_BlitSurface(image, NULL, surface, NULL);
        
        //cout << "Screen Surface is:" << screenSurface << std::endl;
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
    cout << "quitting" << std::endl;
    SDL_DestroyWindow(window);
    cout << "destroyed window" << std::endl;
    SDL_Quit();
}

