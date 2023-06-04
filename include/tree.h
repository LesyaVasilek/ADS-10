// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#endif  // INCLUDE_TREE_H_
#include <vector>
#include <string>
#include <iostream>

class Tree {
 private:
    struct Node {
        std::vector<Node*> pts;
        char val;
    };
    Node* cur;
    Node* r;
    std::vector<char> els;
    std::vector<char> Perm;
    std::string el;
    std::vector<std::vector<char>> Final;

 public:
      Node* make_node(char value) {
        Node* t = new Node;
        t->val = value;
        return t;
    }
    explicit Tree(std::vector<char> in) {
        els = in;
        el.resize(in.size());
        Perm.resize(in.size());
        r = new Node;
        r->val = '*';
        reduce(in, -1, 0, r);
    }
    void reduce(std::vector<char> in, int k, int num, Node* r) {
        if (in.size() == 1) {
            Final.push_back(Perm);
            return;
        }
        auto it = in.cbegin();
        if (k >= 0) {
            num++;
            in.erase(it + k);
        }
        for (int i = 0; i < in.size(); i++) {
            r->pts.push_back(make_node(in[i]));
            Perm[num] = in[i];
            reduce(in, i, num, r->pts[i]);
        }
    }
    std::vector<char> getResult(Tree tree, int num) {
        if (num > Final.size()) return {};
        return Final[num - 1];
    }
};
