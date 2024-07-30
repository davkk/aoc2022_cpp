#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>
#include <string>

namespace Part1 {
int solve() {
    std::string line;

    int max = 0;
    int sum = 0;

    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            sum += std::stoi(line);
        } else {
            if (sum > max) {
                max = sum;
            }
            sum = 0;
        }
    }

    return max;
}
}  // namespace Part1

namespace Part2 {
int solve() {
    std::string line;

    std::set<int, std::greater<int>> cals;
    int sum = 0;

    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            sum += std::stoi(line);
        } else {
            cals.emplace(sum);
            sum = 0;
        }
    }

    return std::ranges::fold_left(cals | std::views::take(3), 0, std::plus{});
}
}  // namespace Part2

int main() {
    // std::cout << Part1::solve() << '\n';
    std::cout << Part2::solve() << '\n';

    return 0;
}
