#include <iostream>
#include <fstream>
#include <vector>
#include <ios>

void readFile(std::string file, std::string& text, std::vector<std::string>& words)
{
    std::ifstream inputFile(file);
    if (inputFile.is_open())
    {
        std::string word;
        while (inputFile >> word) 
        {
            words.push_back(word);
        }
        for (auto& word : words) text += word + ' ';
        inputFile.close();
    }
    else
    {
        std::cerr << "Помилка відкриття файлу для читання" << std::endl;
    }
}

void writeFile(std::string file, std::string& text)
{
    std::ofstream outputFile(file, std::ios::app);
    if (outputFile.is_open())
    {
        outputFile << text << '\n';
        outputFile.close();
        std::cout << "Результат записано у файл 'result.txt'" << std::endl;
    }
    else
    {
        std::cerr << "Помилка відкриття файлу для запису" << std::endl;
    }
}

void extractCommonWords(std::string& text1, const std::string& text2, std::vector<std::string>& words2)
{
    std::vector<std::string> commonWords;

    for (std::string word : words2)
    {
        if (text1.find(word) <= text1.size())
        {
            commonWords.push_back(word);
        }
    }
    for (auto& word : commonWords)
    {
        text1.erase(text1.find(word), word.size());
    }
}

int main() 
{
    setlocale(LC_ALL, "ukr");
    std::string text1;
    std::string text2;
    std::vector<std::string> words1;
    std::vector<std::string> words2;
    readFile("text1.txt", text1, words1);
    readFile("text2.txt", text2, words2);
    std::cout << "Text 1: " << text1 << '\n';
    std::cout << "Text 2: " << text2 << '\n';
    extractCommonWords(text1, text2, words2);
    std::cout << "Result: " << text1 << '\n';
    writeFile("result.txt", text1);
    return 0;
}
