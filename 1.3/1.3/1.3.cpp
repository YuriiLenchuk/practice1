#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ios>

void readFile(std::string file, std::string& text)
{
    std::ifstream inputFile(file);
    if (inputFile.is_open())
    {
        std::getline(inputFile, text);
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

std::vector<std::string> splitString(const std::string& text) 
{
    std::istringstream iss(text);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());;
    return words;
}


void extractCommonWords(std::string& text1, const std::string& text2) 
{
    std::vector<std::string> words2 = splitString(text2);

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
        char ch = '5';
        do {
            system("cls");
            std::cout << "1 Ввести рядки через консоль" << '\n';
            std::cout << "2 Зчитати рядки з файлу" << '\n';
            std::cout << "3 Вихід" << '\n';
            ch = std::cin.get();
            std::cin.get();
            switch (ch) {
            case '1': 
            {
                std::cout << "Введіть перший текст: ";
                std::getline(std::cin, text1);
                std::cout << "Введіть другий текст: ";
                std::getline(std::cin, text2);
                std::cout << "Text 1: " << text1 << '\n';
                std::cout << "Text 2: " << text2 << '\n';
                extractCommonWords(text1, text2);
                std::cout << text1 << '\n';
                writeFile("result.txt", text1);
                break;
            }
            case '2': 
            {
                readFile("text1.txt", text1);
                readFile("text2.txt", text2);
                std::cout << "Text 1: " << text1 << '\n';
                std::cout << "Text 2: " << text2 << '\n';
                extractCommonWords(text1, text2);
                std::cout << "Result: " << text1 << '\n';
                writeFile("result.txt", text1);
                break;
            }
            case '3': return 0;
            }
            std::cin.get();
        } while (ch != '3');
}
