#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "Tree.h"


std::vector<char> get_data() {
    //create new stream, reading BINARY and placing the caret At The End of the file
    std::ifstream infile(R"(C:\Users\Foo\CLionProjects\playground\toCompress.txt)", std::ios::binary|std::ios::ate);
    //pos is the position of the caret
    std::ifstream::pos_type pos = infile.tellg();
    //create a vector that is the length of the caret's position
    std::vector<char>  data(pos);

    //move the caret to the start of the file (with offset 0)
    infile.seekg(0, std::ios::beg);
    //reads POS characters to the vector at location result[0]
    infile.read(&data[0], pos);
    return data;
}


Tree poll_lowest(std::multiset<Tree>& queue) {
    Tree last = *queue.begin();
    queue.erase(last);
    return last;
}

int main() {
    setbuf(stdout, 0);
    std::vector<char> data = get_data(); //all characters in the file
    std::vector<int> frequencies(128); //how often each char occurs in the file
    std::set<char> allCharsThatOccur(data.begin(), data.end()); //set of all characters that occur at least once in the file
    for (char i : data) {
        frequencies[i]++;
    }
    std::multiset<Tree> queue;
    for (char i : allCharsThatOccur) {
        queue.insert(Tree(i, frequencies[i]));
    }
    while (queue.size() > 1) {
        Tree lowest = poll_lowest(queue);
        Tree second_lowest = poll_lowest(queue);
        Tree newTree = Tree(lowest, second_lowest);
        queue.insert(newTree);
    }
    std::cout << "Hello, World! " <<  std::endl;
    return 0;
}
