#include <stdio.h>

int main() {
    char *str = "Hello world";

    printf("Original string: %s\n\n", str);

    printf("--- AND with 127 ---\n");
    printf("Char | ASCII | AND 127 | Result\n");
    printf("--------------------------------\n");
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char res = ch & 127;  // AND with 127 (01111111) clears 8th bit
        printf("  %c  |  %d  |   %d   |   %c\n", ch, ch, res, res);
    }

    printf("\n--- XOR with 127 ---\n");
    printf("Char | ASCII | XOR 127 | Result (may be non-printable)\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        char res = ch ^ 127;  // XOR with 127 flips lower 7 bits
        printf("  %c  |  %d  |   %d   |   %d\n", ch, ch, res, res);
    }

    return 0;
}
