#include <array>
#include <deque>
#include <iostream>
#include <numeric>

constexpr size_t char_to_idx(char ch) { return static_cast<size_t>(ch - 'a'); }

size_t find_distinct(size_t n) {
    std::deque<char> window{};
    std::array<int, 26> counts{0};

    size_t idx{1};
    for (char ch{}; std::cin.get(ch); idx++) {
        window.push_back(ch);
        counts[char_to_idx(ch)]++;

        if (window.size() > n) [[likely]] {
            counts[char_to_idx(window.front())]--;
            window.pop_front();

            int result{std::accumulate(
                counts.cbegin(), counts.cend(), 1,
                [](const auto& acc, const auto& count) {
                    return count > 0 ? acc * count : acc;
                }
            )};

            if (result == 1) {
                return idx;
            }
        }
    }

    return 0;
}

namespace Part1 {
size_t solve() { return find_distinct(4); }
}  // namespace Part1

namespace Part2 {
size_t solve() { return find_distinct(14); }
}  // namespace Part2

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        return 1;
    }

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
