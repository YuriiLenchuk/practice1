#include "list.h"
template<typename T>
list<T>& unique_rev(list<T>& L1, list<T>& L2)
{
    list<T>* rez = new list<T>;
    for (const auto& word : L1) {
        bool found = false;
        for (const auto& word2 : L2) {
            if (word == word2) {
                found = true;
                break;
            }
        }
        if (!found) {
            rez->push_front(word);
        }
    }
    return *rez;
}

int main() {
    list<std::string> L1 = { "WORD1", "WORD2", "WORD3", "WORD4", "WORD5" };
    list<std::string> L2 = { "WORD3", "WORD5" };
    (unique_rev<std::string>(L1, L2)).print();
    return 0;
}
