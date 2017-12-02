#include <stdio.h>

class X {
public:
  X() {
    printf("X was initialized\n");
  }
  ~X() {
    printf("X was destroyed\n");
  }
};


class Y {
public:
  X x;
  int r;
  Y() {
      printf("Y was initialized\n");
  }
~Y() {
    printf("Y was destroyed\n");
  }
};

class Z {
public:
  Z(int i) {
    printf("Ola\n");
  }
};

int main() {
  int l[14];
  Y y;
  Z z(9);
  Z z_array[1](1);
  printf("%d\n", y.r);
  return 0;
}
