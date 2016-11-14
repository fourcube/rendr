#ifndef _LIB_H
#define _LIB_H

#include <dlfcn.h>
#include <string>
#include "state.h"

class GameCode {
  public:
    GameCode();

    virtual void print();
    virtual void updateState(State* state);

  private:
    std::string message;
    int index;
};

#endif