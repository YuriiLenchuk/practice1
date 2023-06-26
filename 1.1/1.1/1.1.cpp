#include <iostream>
#include<iomanip>

unsigned long long fact(unsigned int x)
{
    return (x == 0 || x == 1) ? 1 : x * fact(x - 1);
}

double pow(double x, unsigned int n)
{
    return (x == 1 || x == 0 || n == 0) ? 1 : x * pow(x, n - 1);
}

double sum(unsigned int k, int n, double a, double b)
{
    double rez = (a * b) / fact(k + 1);
    std::cout << "a = " << std::setw(15) << a << "  b = " << std::setw(15) << b << "  rez = " << std::setw(15) << rez << '\n';
    return (k == n) ? rez : rez + sum(++k, n, 0.3 * a + 0.2 * b, pow(a, 2) + pow(b, 2));
}

int main()
{
    int n, k = 1, a = 1, b = 1;
    std::cout << "Enter n: "; std::cin >> n; 
    std::cout << "\nFinal rez = " << sum(k, n, a, b);
    return 0;
}