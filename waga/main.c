#include <stdio.h>
#define SIZE 100



int weight(int *mass, int sum, int w, int n, int i) {
    if (sum == w) { return 1; } // znaleziono odpowiednia sume
    if (i == n) { return 0;} // uzyto wszytkich odwaznikow

    int output1, output2;
    output1 = weight(mass, sum + mass[i], w, n, i + 1); // odwaznik na jedna strone
    output2 = weight(mass, sum - mass[i], w, n, i + 1); // odwaznik na druga strone

    return output1 + output2;
}


int main() {

    int n, w;
    int mass[SIZE];
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) { scanf("%d", &mass[i]); }
    if (weight(mass, 0, w, n, 0) > 0) {
        printf("YES");
    } else { printf("NO"); }


    return 0;
}

