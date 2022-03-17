#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

class Node {
public:
    Node(char ch, int freq, Node *l, Node *r) {
        this->ch = ch;
        this->freq = freq;
        this->l = l;
        this->r = r;
    }

    char ch;
    int freq;
    Node *l;
    Node *r;
    ~Node() {
        delete l;
        delete r;
    }
};

struct Comparasion {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void encode(Node *root, std::unordered_map<char, std::string> *res, std::string str) {
    if (root == nullptr) {
        return;
    }
    if (root->l == nullptr && root->r == nullptr) {
        (*res)[root->ch] = str;
    }
    encode(root->l, res, str + "0");
    encode(root->r, res, str + "1");
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    int len = str.length();
    std::unordered_map<char, int> dict;
    for (int i = 0; i < len; ++i) {
        dict[str[i]]++;
    }

    std::priority_queue<Node *, std::vector<Node *>, Comparasion> queue;

    for (auto pair : dict) {
        queue.push(new Node(pair.first, pair.second, nullptr, nullptr));
    }

    while (queue.size() != 1) {
        Node *l = queue.top();
        queue.pop();
        Node *r = queue.top();
        queue.pop();
        int a = l->freq + r->freq;
        queue.push(new Node('\0', a, l, r));
    }

    Node *root = queue.top();
    dict.clear();
    std::unordered_map<char, std::string> res;
    encode(root, &res, "");
    if (res.size() == 1) {
        res[str[0]] = "0";
    }
    std::string res_str;
    for (int i = 0; i < len; ++i) {
        res_str += res[str[i]];
    }
    std::cout << res.size() << " " << res_str.length() << std::endl;
    for (auto pair : res) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << res_str << std::endl;

    delete root;
    return 0;
}
