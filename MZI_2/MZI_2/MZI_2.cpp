#include <iostream>
#include <vector>
#include <string>
#include <fstream>

typedef unsigned int uint;

bool check_prime(uint a, uint b);
std::vector<int> LCG(uint n, uint seed, uint m, uint a, uint c);
std::string output_vector(std::vector<int> v);

int main()
{
    uint n = 0, seed = 0, m = 0, a = 0, c = 0;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter seed: ";
    std::cin >> seed;
    std::cout << "Enter m: ";
    std::cin >> m;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter c: ";
    std::cin >> c;
    if (m < 2) {
        std::cout << "Too little value of m\n";
        return 1;
    }
    if (a > m || a < 0) {
        std::cout << "Incorrect value of a\n";
        return 2;
    }
    if (c > m || c < 0) {
        std::cout << "Incorrect value of c\n";
        return 3;
    }
    std::ofstream out("generated.txt");
    if (!out.is_open()) {
        std::cout << "File ws not opened\n";
        return 4;
    }

    std::string generated = output_vector(LCG(n, seed, m, a, c));
    std::cout << generated;
    out << generated;
    out.close();
}

bool check_prime(uint a, uint b) {
    return true;
}

std::vector<int> LCG(uint n, uint seed, uint m, uint a, uint c) {
    std::vector<int> numbers(n);
    numbers[0] = seed;
    for (int i = 0; i < n - 1; i++) {
        numbers[i + 1] = (a * numbers[i] + c) % m;
    }

    return numbers;
}

std::string output_vector(std::vector<int> v) {
    std::string res = "";
    for (auto n : v)
        res += std::to_string(n) + " ";
    return res + '\n';
}