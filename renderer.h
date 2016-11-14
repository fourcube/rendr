#ifndef _RENDERER_H
#define _RENDERER_H

#include <SDL.h>
#include <stdlib.h>

#include "state.h"

using namespace std;

class Renderer {
  public:
    Renderer();
    
    void init(int argc, char ** argv);
    void render(State* state);

  private:
    SDL_Window* displayWindow;
    SDL_GLContext glContext;
};

#endif