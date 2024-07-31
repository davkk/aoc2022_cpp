#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <set>
#include <string_view>

namespace Part1 {
std::optional<char> find_same(const std::string_view line) {
    auto size = line.size();
    for (size_t i = 0; i < size / 2; ++i) {
        for (size_t j = size; j >= size / 2; --j) {
            if (line[i] == line[j]) {
                return line[i];
            }
        }
    }
    return std::nullopt;
}

int solve() {
    std::string line;
    auto sum = 0;
    while (std::getline(std::cin, line)) {
        auto item = find_same(line);
        if (item) {
            if (*item >= 'A' && *item <= 'Z') {
                sum += *item - 'A' + 27;
            } else {
                sum += *item - 'a' + 1;
            }
        }
    }
    return sum;
}
}  // namespace Part1

namespace Part2 {
std::optional<char> find_same(const std::string_view line1,
                              const std::string_view line2) {
    for (size_t i = 0; i < line1.size(); ++i) {
        for (size_t j = 0; j < line2.size(); ++j) {
            if (line1[i] == line2[j]) {
                return line1[i];
            }
        }
    }
    return std::nullopt;
}
int solve() {
    std::string line1, line2, line3;
    auto sum = 0;

    while (                               //
        std::getline(std::cin, line1) &&  //
        std::getline(std::cin, line2) &&  //
        std::getline(std::cin, line3)     //
    ) {
        std::set<char> set1(line1.begin(), line1.end());
        std::set<char> set2(line2.begin(), line2.end());
        std::set<char> set3(line3.begin(), line3.end());

        std::set<char> tmp;
        std::set_intersection(set1.begin(), set1.end(), set2.begin(),
                              set2.end(), std::inserter(tmp, tmp.begin()));

        std::set<char> common;
        std::set_intersection(tmp.begin(), tmp.end(), set3.begin(), set3.end(),
                              std::inserter(common, common.begin()));

        if (common.size() > 0) {
            char item = *std::begin(common);
            if (item >= 'A' && item <= 'Z') {
                sum += item - 'A' + 27;
            } else {
                sum += item - 'a' + 1;
            }
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
