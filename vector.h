
class Vec3 {
  public:
    Vec3(float x, float y, float z): x(x), y(y), z(z) {};

    Vec3& operator+=(const Vec3& rhs) {
      this->x += rhs.x;
      this->y += rhs.y;
      this->z += rhs.z;
      return *this;
    }

    float X() {
      return this->x;
    }

  private:
    float x;
    float y;
    float z;
};