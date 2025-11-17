#include <string.h>

int getValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int result = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        // Nếu ký tự hiện tại nhỏ hơn ký tự tiếp theo, hãy trừ nó đi.
        // Ví dụ: IV (5-1=4), IX (10-1=9)
        if (i < len - 1 && getValue(s[i]) < getValue(s[i+1])) {
            result -= getValue(s[i]);
        } else {
            result += getValue(s[i]);
        }
    }

    return result;
}