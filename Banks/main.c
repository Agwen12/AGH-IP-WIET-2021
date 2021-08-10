#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//struct osoba {
//    const char*imie;
//    char nazisko[64];
//} o = {"Anna", "Nowak"};
//
//void czytaj1(struct osoba*o) {
//    scanf("%s", o->imie);
//    scanf("%s", o->nazisko);
//}

int main() {
    char line[100];
    scanf("%s", line);
    printf("%s\n%s\n%d", line, line, strlen(line));
    return 0;

}
