#include <iostream>

namespace Part1 {
int solve() {
    for (std::string line{}; std::getline(std::cin, line);) {
    }
    return 0;
}
}  // namespace Part1

namespace Part2 {
int solve() {
    for (std::string line{}; std::getline(std::cin, line);) {
    }
    return 0;
}
}  // namespace Part2

int main(int argc, const char* argv[]) {
    if (argc == 1) return 1;

    switch (argv[1][0]) {
    case '1':
        std::cout << Part1::solve() << '\n';
        break;
    case '2':
        std::cout << Part2::solve() << '\n';
        break;
    default:
        return 1;
    }

    return 0;
}
