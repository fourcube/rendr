#include <string>
#include <iostream>
#include <chrono>
#include <thread>


#include "lib.h"
#include "hotreload.h"
#include "renderer.h"
#include "state.h"

using namespace std;

int main(int argc, char ** argv) {
  void* handle = reload(nullptr);
  mutex* lock = new mutex;
  GameCode* obj = init_game_code();

  Renderer* renderer = new Renderer;
  State* state = new State;
  state->setColor(0.0f, 0.0f, 0.0f);
  renderer->init(argc, argv);

  std::thread ([&] () mutable {
    while (true)
    {
      if(has_changed(lib)) {
        lock->lock();
        destroy(obj);

        handle = reload(handle);
        obj = init_game_code();
        lock->unlock();
      }

      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }).detach();
  
  while(1) {
    lock->lock();
    renderer->render(state);
    obj->updateState(state);
    lock->unlock();
  }

  destroy(obj);
}