#include <iostream>

int main() {
    char ch;
    char s[1000000];
    int counter = 1;
    while ((ch = std::getchar()) != '\n') {
        s[counter++] = ch;
    }

    int er = 0;
    for (int i = 1; i < counter; ++i) {
        if (s[i] == '1') {
            er = er ^ i;
        }
    }

    if (er != 0) {
        if (s[er] == '1') {
            s[er] = '0';
        } else {
            s[er] = '1';
        }
    }

    for (int i = 1; i < counter; ++i) {
        if ((i & (i - 1)) != 0) {
            std::cout << s[i];
        } 
    std::cout << std::endl;
    return 0;
}
