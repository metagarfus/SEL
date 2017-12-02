#include <stdlib.h>
#include <stdio.h>
struct Z {
  int z;
};

struct Y {
  int y;
  struct Z z;
};

struct X {
  int x;
  struct Y y;
};

int opaque(int x);

int main () {
  int i;
  for (i = 0; i < 10000000; i++) {
    struct X x = {random(), {random(), {random()}}};
    int result = x.x + x.y.y + x.y.z.z;
    opaque(result);
    //printf("%d %d %d\n", x.x, x.y.y, x.y.z.z);
  }

}
