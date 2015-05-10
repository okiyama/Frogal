/*
 * Header file for an SDL class that deals with basics like initialization
 * and things like that.
 * Author: Julian Jocque
 */
#ifndef SDL_Class_h
#define SDL_Class_h
#include <string>
#include <SDL2/SDL.h>

class SDL_Class {
    private:
        int window_width, window_height;
        SDL_Window* window;
        SDL_Surface* surface;
    public:
        SDL_Class(int, int);
        bool load_media(char*);
        void quit();
    private:
        SDL_Window* init_window(int, int);
        SDL_Surface* init_surface(SDL_Window*);
        bool init_SDL();
};

#endif
