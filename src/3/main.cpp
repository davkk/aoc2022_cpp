#include <iostream>
#include <ranges>
#include <unordered_set>

int char_to_score(char c) {
    return std::islower(c) ? (c - 'a' + 1) : (c - 'A' + 27);
}

namespace Part1 {
int solve() {
    int sum{0};

    for (std::string line{}; std::getline(std::cin, line);) {
        int size{static_cast<int>(line.size())};
        auto half{line.begin() + size / 2};
        std::unordered_set<char> first_half(line.begin(), half);

        for (auto second_half : std::ranges::subrange(half, line.end())) {
            if (first_half.contains(second_half)) {
                sum += char_to_score(second_half);
                break;
            }
        }
    }

    return sum;
}
}  // namespace Part1

namespace Part2 {
int solve() {
    std::string line1, line2, line3;
    auto sum{0};

    while (std::getline(std::cin, line1) && std::getline(std::cin, line2)
           && std::getline(std::cin, line3)) {
        std::unordered_set<char> set2(line2.begin(), line2.end());
        std::unordered_set<char> set3(line3.begin(), line3.end());

        auto common_all = line1
                        | std::ranges::views::filter([&set2](const char &c) {
                              return set2.contains(c);
                          })
                        | std::ranges::views::filter([&set3](const char &c) {
                              return set3.contains(c);
                          });

        if (!common_all.empty()) {
            sum += char_to_score(common_all.front());
        }
    }
    return sum;
}
}  // namespace Part2

int main() {
    // std::cout << Part1::solve() << '\n';
    std::cout << Part2::solve() << '\n';
    return 0;
}
