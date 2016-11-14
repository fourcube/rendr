#ifndef _HOT_RELOAD_H
#define _HOT_RELOAD_H

#include <dlfcn.h>
#include <iostream>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

static const char* lib = "bin/lib.dylib"; 
long lib_last_modified = 0;
GameCode* (*init_game_code)();
void (*destroy)(GameCode*);

bool has_changed(const char *path) {
    struct stat attr;
    stat(path, &attr);
    if(lib_last_modified != attr.st_mtime) {
      cout << path << " has changed." << endl;
      lib_last_modified = attr.st_mtime;
      return true;
    }
    
    return false;
}

void* reload(void* handle) {
  if(handle != nullptr) {
    dlclose(handle);
  }

  handle = dlopen(lib, RTLD_LAZY | RTLD_NOW);
  init_game_code = (GameCode* (*)())dlsym(handle, "init_game_code");
  destroy = (void (*)(GameCode*))dlsym(handle, "destroy_object");
  return handle;
}

#endif