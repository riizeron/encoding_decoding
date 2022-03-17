#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    int str_len = str.length();
    int add = 0;

    for (int i = 0; i < str_len; ++i) {
        if (((i + 1) & i) == 0) {
            add++;
        }
    }

    char res[1000000];

    int res_len = str_len + add;

    int str_iter = 0;
    for (int i = 0; i < res_len; ++i) {
        if (((i + 1) & i) == 0) {
            res[i] = '0';
        } else {
            res[i] = str[str_iter++];
        }
    }

    int value;
    int t;
    int counter = 0;
    for (int iter = 0; iter < res_len; ++iter) {
        if ((iter & (iter + 1)) == 0) {
            value = 0;
            for (int j = iter; j < res_len; ++j) {
                t = j - iter;
                if (((t >> counter) & 1) == 0) {
                    value += (res[j] - '0');
                }
            }
            res[iter] = static_cast<char>('0' + value % 2);
            counter++;
        }
    }
    for (int i = 0; i < res_len; ++i) {
        std::cout << res[i];
    }
    std::cout << std::endl;

    return 0;
}
