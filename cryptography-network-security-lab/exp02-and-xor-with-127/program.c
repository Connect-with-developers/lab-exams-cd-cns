#include <stdio.h>

int main() {
    char *str = "Hello world";
    int i = 0;

    printf("Original string: %s\n\n", str);

    printf("--- AND with 127 ---\n");
    printf("Char | ASCII | AND 127 | Result\n");
    printf("--------------------------------\n");
    i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        char res = ch & 127;  // AND with 127 (01111111) clears 8th bit
        printf("  %c  |  %3d  |   %3d   |   %c\n", ch, ch, res, res);
        i++;
    }

    printf("\n--- XOR with 127 ---\n");
    printf("Char | ASCII | XOR 127 | Result (may be non-printable)\n");
    printf("-------------------------------------------------------\n");
    i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        char res = ch ^ 127;  // XOR with 127 flips lower 7 bits
        printf("  %c  |  %3d  |   %3d   |   %d\n", ch, ch, res, res);
        i++;
    }

    return 0;
}
