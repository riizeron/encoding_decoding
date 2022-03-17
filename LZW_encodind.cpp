#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

int main() {
    std::string s;
    std::unordered_map<std::string, int> dict;
    int i;
    for (i = 0; i < 128; ++i) {
        s = {static_cast<char>(i)};
        dict[s] = i;
    }

    char h;
    int code[1000000];
    int iter = 0;
    h = std::getchar();
    std::string p = {h};
    while (h != '\n') {
        h = std::getchar();
        if (dict.find(p + h) != dict.end()) {
            p += h;
        } else {
            code[iter++] = dict[p];
            dict[p + h] = i++;
            p = {h};
        }
    }

    std::cout << iter << std::endl;
    for (int j = 0; j < iter; ++j) {
        std::cout << code[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}
