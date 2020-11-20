//
// Created by Foo on 18-11-2020.
//

#include "Tree.h"

std::ostream& operator<<(std::ostream& o, Tree t)  {
    //std::string to_add = t.to_str_with_prefix(0);
    o << "I am a tree";
    return o;
}

std::string Tree::to_str_with_prefix(int prefix) const {
    std::string res(prefix * 4, ' ');
    if (data == -1) {
        res += "-\n" + left->to_str_with_prefix(prefix + 1) + right->to_str_with_prefix(prefix + 1);
    } else {
        res.push_back(data);
        res += "\n";
    }
    return res;
}



