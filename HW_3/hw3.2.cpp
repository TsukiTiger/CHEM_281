#include <iostream>
#include <list>

void printSequence(const std::list<int>& sequence) {
    std::cout << "[";
    for (auto it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != sequence.end()) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

void findSequences(int x, int last, std::list<int>& current) {
    if (x == 0) {
        printSequence(current);
        return;
    }

    for (int i = std::min(x, last); i > 0; --i) {
        current.push_back(i);
        findSequences(x - i, i, current);
        current.pop_back();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    int x = std::stoi(argv[1]);
    std::list<int> sequence;
    findSequences(x, x, sequence);

    return 0;
}
