#include <stdio.h>

int main() {
    char *str = "Hello world";

    printf("Original string: %s\n", str);
    printf("Char | ASCII | XOR with 0 | Result Char\n");
    printf("----------------------------------------\n");

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char xored = ch ^ 0;  // XOR with 0 = same character
        printf("  %c  |  %d  |     %d    |      %c\n", ch, ch, xored, xored);
    }

    printf("\nXOR with 0 does not change the character.\n");
    printf("Result string: %s\n", str);
    return 0;
}
