//
// Created by Foo on 18-11-2020.
//

#ifndef PLAYGROUND_TREE_H
#define PLAYGROUND_TREE_H

#include <vector>
#include <iostream>


class Tree {
    public:

    char data = -1;
    const int frequency;
    Tree *left;
    Tree *right;

    Tree(char data, int frequency): data(data), left(nullptr), right(nullptr), frequency(frequency) {
    }

    Tree(Tree left, Tree right) : data(-1), frequency(left.frequency + right.frequency) {
        this->left = &left;
        this->right = &right;
    }
    bool operator==(const Tree& other) const {
        return data == other.data && left == other.left && right == other.right;
    }

    friend std::ostream& operator<<(std::ostream& os, Tree dt);
    std::string to_str_with_prefix(int prefix) const;


    bool operator<(const Tree& other) const {
        return frequency < other.frequency;
    }

    bool operator=(const Tree& other) const {
        return data == other.data && left == other.left && right == other.right;
    }
};


#endif //PLAYGROUND_TREE_H
