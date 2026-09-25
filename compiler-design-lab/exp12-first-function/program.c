#include <stdio.h>

int main() {
    printf("Grammar:\n");
    printf("E -> E+T | T\nT -> T*F | F\nF -> (E) | id\n\n");
    // FIRST(F): F->(E) gives '(', F->id gives id
    printf("FIRST(F) = { (, id }   [from F->(E)|id]\n");
    // FIRST(T): T->T*F|F, so FIRST(T) = FIRST(F)
    printf("FIRST(T) = FIRST(F) = { (, id }\n");
    // FIRST(E): E->E+T|T, so FIRST(E) = FIRST(T)
    printf("FIRST(E) = FIRST(T) = { (, id }\n\n");
    printf("Answer: FIRST(E)=FIRST(T)=FIRST(F)={(,id}\n");
    return 0;
}
