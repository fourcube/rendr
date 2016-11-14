#include "lib.h"

#include <iostream>
#include <sstream>

using namespace std;

extern "C" GameCode* init_game_code() {
  return new GameCode;
}

extern "C" void destroy_object(GameCode* object)
{
  delete object;
}

GameCode::GameCode() {
  message = "ffff";
}

void GameCode::updateState(State* state) {
  state->setColor(1.0f, 0.0f, 0.0f);
}

void GameCode::print() {
  cout << message << endl;
}