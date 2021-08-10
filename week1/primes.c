//#include <stdio.h>
//
//
//int is_prime(int number) {
//    if (number <= 3 && number > 1)
//        return 1;            // as 2 and 3 are prime
//    else if (number % 2 == 0 || number % 3 == 0)
//        return 0;     // check if number is divisible by 2 or 3
//    else {
//        unsigned int i;
//        for (i = 5; i * i <= number; i += 6) {
//            if (number % i == 0 || number % (i + 2) == 0)
//                return 0;
//        }
//        return 1;
//    }
//}
//
//int main() {
//    int n, numberToPrint, iCopy;
//    scanf("%d", &n);
//
//    if (n >= 2) {
//        printf("2\n");
//    }
//    for (int i = 3; i < n; i+=2) {
//        // jesli jest pierwsza to sprawdza czy cyfry tworza ciag
//        if (is_prime(i) == 1) {
//            numberToPrint = i;
//            iCopy = i;
//            // sprawdza czy kolejne cyfry spelniaja warunek
//            while (iCopy % 10 >= (iCopy % 100) / 10 && iCopy != 0) {
//                iCopy = iCopy / 10;
//            }
//            // jesli tak wypisuje liczbe
//            if (iCopy == 0) {
//                printf("%d\n", numberToPrint);
//            }
//        }
//    }
//    return 0;
//}