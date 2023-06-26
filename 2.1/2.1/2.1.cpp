#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    std::vector<double> numbers = { 1.2, 3.4, 5.6, 7.8 };

    auto begin = numbers.begin();
    auto end = numbers.end();

    std::ostream_iterator<double> output(std::cout, " ");

    std::copy(begin, end, output);
    std::cout << std::endl;

    return 0;
}