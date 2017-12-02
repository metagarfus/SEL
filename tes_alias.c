#include <stdio.h>
struct Y {
  int x;
};

struct X {
  int x;
};

struct R {
  char l;
  int r;
  char l2;
  int s;
};

void foo(struct X *x, struct Y *y) {
  x->x = 3;
  y->x = 2;
  printf("oi %d\n", x->x);
}

void bar(struct R *r, int *s) {
  r->s = 3;
  *s = 2;
  printf("oi %d\n", r->s);
}

int main() {
  struct X x;
  struct Y y = *(struct Y *)&x;
  struct R r;
  foo(&x, (struct Y *)&x);
  bar(&r, &r.s);
}
