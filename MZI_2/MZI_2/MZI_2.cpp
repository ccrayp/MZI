#include <iostream>
#include <vector>
#include <string>
#include <fstream>

typedef unsigned int uint;

bool is_prime(uint a, uint b);
std::vector<int> LCG(uint n, uint seed, uint m, uint a, uint c);
std::string output_vector(std::vector<int> v);
std::vector<int> factorise(int m);
int LCG_init();

int main()
{
    return LCG_init();
}

int LCG_init() {
    uint n = 0, seed = 0, a = 0, c = 0, m = 0;
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
    if (!is_prime(c, m)) {
        std::cout << "c and m is not prime\n";
        return 4;
    }
    int b = a - 1;
    if (m % 4 == 0 && b % 4 != 0) {
        std::cout << "c and m is not prime\n";
        return 5;
    }
    std::ofstream out("generated.txt", std::ios_base::binary);
    if (!out.is_open()) {
        std::cout << "File ws not opened\n";
        return 6;
    }

    std::vector<int> gen = LCG(n, seed, m, a, c);
    for (auto val : gen) {
        out.write(reinterpret_cast<char*>(&val), sizeof(int));
    }
    out.close();

    std::cout << output_vector(gen) << std::endl;
}

bool is_prime(uint a, uint b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    if (a == 1)
        return true;
    else
        return false;
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

std::vector<int> factorise(int m) {
    return std::vector<int>();
}