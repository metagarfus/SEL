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
    int xx = x.x;
    struct Y y = x.y;
    int yy = y.y;
    struct Z z = y.z;
    int zz = z.z;
    int result = xx + yy + zz;
    opaque(result);
    // printf("%d %d %d\n", xx, yy, zz);
  }

}
