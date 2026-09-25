#include <stdio.h>
#include <stdlib.h>

static int s = 10; // static: one copy, lives full program

int main() {
    int local = 20;              // stack: created on function call
    int *heap = (int *)malloc(sizeof(int)); // heap: manual allocation
    *heap = 30;
    printf("static s   = %d at %p\n", s, (void *)&s);
    printf("stack local= %d at %p\n", local, (void *)&local);
    printf("heap *heap = %d at %p\n", *heap, (void *)heap);
    printf("static: fixed address, whole run\n");
    printf("stack: inside main frame\n");
    printf("heap: malloc address, free it\n");
    free(heap);
    return 0;
}
