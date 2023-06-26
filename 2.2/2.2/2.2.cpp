#include <iostream>
#include <deque>
#include <algorithm>

bool isNegative(int num) {
    return num < 0;
}

int main() {
    std::deque<int> D = { 1, -2, 3, -4, 5, -6 };

    std::deque<int> D0(D.begin(), D.begin() + D.size() / 2);

    std::replace_copy_if(D0.rbegin(), D0.rend(), std::back_inserter(D), isNegative, 0);

    for (const auto& num : D) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
