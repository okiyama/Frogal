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
    public:
        SDL_Class(int, int);
        bool init(SDL_Window*, SDL_Surface*);
        bool load_media(SDL_Surface*, char*);
        void quit(SDL_Surface*, SDL_Window*);
};

#endif
