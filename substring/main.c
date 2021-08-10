#include <stdio.h>

int main() {
    char input[51];
    scanf("%s", input);
    int index = 0;
    int index2 = 1;
    while (input[index] != '\0') {
        while (input[index2] != '\0') {
            if (input[index2] > input[index]) { index = index2; }

            index2 += 1;
        }
        printf("%c", input[index]);
        index += 1;
        index2 = index + 1;
    }
    return 0;
}
