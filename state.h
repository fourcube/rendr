#ifndef _STATE_H
#define _STATE_H

class State {
  public:
    float R() {
      return r;
    }

    float B() {
      return b;
    }

    float G() {
      return g;
    }

    void setColor(float r, float b , float g) {
      this->r = r;
      this->b = b;
      this->g = g;
    }
    
  private:
    float r;
    float b;
    float g;
};

#endif