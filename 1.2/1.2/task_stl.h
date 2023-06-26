#pragma once
#include <iostream>
#include <list>
#include <algorithm>

int task_stl() {
    std::list<std::string> L1 = { "WORD1", "WORD2", "WORD3", "WORD4", "WORD5" };
    std::list<std::string> L2 = { "WORD3", "WORD5" };

    std::list<std::string> result;

    for (const std::string& word : L1) 
    {
        if (std::find(L2.begin(), L2.end(), word) == L2.end()) 
        {
            result.push_front(word);
        }
    }

    for (const std::string& word : result) 
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
