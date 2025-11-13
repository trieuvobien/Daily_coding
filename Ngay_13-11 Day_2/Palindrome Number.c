#include <stdbool.h>
#include<stdio.h>
#include<math.h>
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int trunggian = 0;
    while (x > trunggian) {
        trunggian = trunggian * 10 + x % 10;
        x /= 10;
    }
    return x == trunggian || x == trunggian / 10;
}