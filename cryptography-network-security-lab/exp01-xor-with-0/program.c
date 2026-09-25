#include <stdio.h>

int main() {
    char *str = "Hello world";
    int i = 0;

    printf("Original string: %s\n", str);
    printf("Char | ASCII | XOR with 0 | Result Char\n");
    printf("----------------------------------------\n");

    while (str[i] != '\0') {
        char ch = str[i];
        char xored = ch ^ 0;  // XOR with 0 = same character
        printf("  %c  |  %3d  |     %3d    |      %c\n", ch, ch, xored, xored);
        i++;
    }

    printf("\nXOR with 0 does not change the character.\n");
    printf("Result string: %s\n", str);
    return 0;
}
