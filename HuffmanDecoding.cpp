#include <string.h>
#include <iostream>
#include <utility>

struct Node {
    explicit Node(char ch) {
        this->ch = ch;
    }
    char ch;
    Node *l = nullptr, *r = nullptr;
    ~Node() {
        delete r;
        delete l;
    }
};

void decode(Node *root, char *str, int *ind) {
    if (root == nullptr) {
        return;
    }
    if (!root->l && !root->r) {
        std::cout << root->ch;
        return;
    }
    (*ind)++;
    if (str[*ind] == '0') {
        decode(root->r, str, ind);
    } else {
        decode(root->l, str, ind);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k, l;
    std::cin >> k >> l;
    char s[2];
    char *c;
    std::pair<char, char *> *d = new std::pair<char, char *>[k];
    for (int i = 0; i < k; ++i) {
        c = new char[1000000];
        std::cin >> s >> c;
        d[i] = std::pair<char, char *>(s[0], c);
    }

    char *code = new char[l];
    std::cin >> code;

    Node *root = new Node('\0');
    Node *temporary;
    std::pair<char, char *> pair;
    size_t bit = 0;
    for (int iter = 0; iter < k; ++iter) {
        pair = d[iter];
        temporary = root;
        bit = 0;
        while (bit < strlen(pair.second)) {
            if (pair.second[bit] == '0') {
                if (temporary->r == nullptr || bit == strlen(pair.second) - 1) {
                    temporary->r = new Node(pair.first);
                }
                temporary = temporary->r;
            } else {
                if (temporary->l == nullptr || bit == strlen(pair.second) - 1) {
                    temporary->l = new Node(pair.first);
                }
                temporary = temporary->l;
            }
            bit++;
        }
    }

    if (l == 1) {
        std::cout << pair.first << std::endl;
    } else {
        int ind = -1;
        while (ind < l - 1) {
            decode(root, code, &ind);
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < k; ++i) {
        delete[] d[i].second;
    }
    delete[] d;
    delete[] code;

    delete root;
    return 0;
}
