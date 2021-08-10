#include <stdio.h>
#include <string.h>

int digit(char c);
int to_int(char roman[]);
void convertToRoman (int val, char *res);

int main() {

    char roman_number1[100];
    char roman_number2[100];
    char roman_result[100];
    int num1, num2, result;
    scanf("%s %s", roman_number1, roman_number2);

    num1 = to_int(roman_number1);
    num2 = to_int(roman_number2);
    result = num1 + num2;
    convertToRoman(result, roman_result);
    printf("%s", roman_result);

    
    return 0;
}

int to_int(char roman[]) {
    int i = 0;
    int number = 0;
    while (roman[i]) {
        if (digit(roman[i]) >= digit(roman[i + 1])) {
            number += digit(roman[i]);
        } else {
            number += (digit(roman[i + 1]) - digit(roman[i]));
            i++;
        }
        i++;
    }

    return number;
}

void convertToRoman (int val, char *res) {

    char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};

    while (val >= 1000) {
        *res++ = 'M';
        val -= 1000;
    }

    strcpy (res, huns[val/100]); res += size[val/100]; val = val % 100;
    strcpy (res, tens[val/10]);  res += size[val/10];  val = val % 10;
    strcpy (res, ones[val]);     res += size[val];

    *res = '\0';
}


int digit(char c) {
    
    int value = 0;

    switch (c) {
        case 'I': value = 1; break;
        case 'V': value = 5; break;
        case 'X': value = 10; break;
        case 'L': value = 50; break;
        case 'C': value = 100; break;
        case 'D': value = 500; break;
        case 'M': value = 1000; break;
        case '\0': value = 0; break;
        default: value = -1;
    }
    return value;
}
