#include "renderer.h"
// OpenGL / glew Headers
#define GL3_PROTOTYPES 1
#include <OpenGL/gl.h>

Renderer::Renderer() {

}

void Renderer::render(State* state) {
     /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f);
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT );

    glRotatef(0.4f,0.0f,1.0f,0.0f);    // Rotate The cube around the Y axis
    glColor3f(state->R(), state->B(), state->G()); 

    glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f( 0.5f, -0.5f );
        glVertex2f( 0.5f, 0.5f );
        glVertex2f( -0.5f, 0.5f );
    glEnd();
    
    SDL_GL_SwapWindow(displayWindow);
}

void Renderer::init(int argc, char ** argv) {
    int width = 640;
    int height = 480;
    SDL_Init(SDL_INIT_VIDEO);
    signal(SIGINT, SIG_DFL);
    
    displayWindow = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    glContext = SDL_GL_CreateContext(displayWindow);
    SDL_GL_SetSwapInterval(1);

    /* Height / width ration */
    GLfloat ratio;

    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    /* Set the background black */
    glClearColor( 0.f, 0.f, 0.f, 1.f );
}