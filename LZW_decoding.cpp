#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

int main() {
    std::string s;
    std::unordered_map<int, std::string> dict;
    int i;
    for (i = 0; i < 128; ++i) {
        s = {static_cast<char>(i)};
        dict[i] = s;
    }

    int n;
    std::cin >> n;
    int code_f, code_l;

    std::cin >> code_f;
    s = dict[code_f];
    std::string c = {s[0]};
    std::string res = s;
    for (int j = 1; j < n; ++j) {
        std::cin >> code_l;
        if (dict.find(code_l) == dict.end()) {
            s = dict[code_f];
            s += c;
        } else {
            s = dict[code_l];
        }
        res += s;
        c = s[0];
        dict[i++] = dict[code_f] + c;
        code_f = code_l;
    }

    std::cout << res << std::endl;

    return 0;
}
