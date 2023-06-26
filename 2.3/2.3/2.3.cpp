#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<std::string> V = { "APPLE", "BANANA", "ELEPHANT", "CAT", "DOG" };

    std::map<char, int> M;

    for (const std::string& word : V) {
        char firstLetter = word[0];
        M[firstLetter] += word.size();
    }

    for (const auto& entry : M) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}
