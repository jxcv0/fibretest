#include <stdio.h>

typedef struct Context {
  void *rip, *rsp;
  void *rbx, *rbp, *r12, *r13, *r14, *r15;
} Context;

extern void get_context(Context *c);
extern void set_context(Context *c);

int main() {
  volatile int x = 0;

  Context c;
  get_context(&c);

  printf("hello, world!\n");

  if (x == 0) {
    x++;
    set_context(&c);
  }

  return 0;
}
