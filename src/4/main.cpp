#include <array>
#include <iostream>

struct Range {
    int start;
    int end;
};

using Ranges = std::array<Range, 2>;

Ranges parse_ranges(std::string_view line) {
    size_t range_idx{0};

    std::array<Range, 2> ranges{};
    std::string token{};

    for (const auto& c : line) {
        if (std::isdigit(c)) {
            token += c;
        } else if (c == '-') {
            ranges[range_idx].start = std::stoi(token);
            token.clear();
        } else if (c == ',') {
            ranges[range_idx].end = std::stoi(token);
            token.clear();
            range_idx++;
        }
    }
    ranges[range_idx].end = std::stoi(token);

    return ranges;
}

namespace Part1 {
int solve() {
    int sum{0};
    for (std::string line{}; std::getline(std::cin, line);) {
        auto [r1, r2] = parse_ranges(line);
        if ((r1.start <= r2.start && r1.end >= r2.end)
            || (r2.start <= r1.start && r2.end >= r1.end)) {
            sum++;
        }
    }
    return sum;
}
}  // namespace Part1

namespace Part2 {
int solve() {
    int sum{0};
    for (std::string line{}; std::getline(std::cin, line);) {
        auto [r1, r2] = parse_ranges(line);
        if (r1.start <= r2.end && r1.end >= r2.start) {
            sum++;
        }
    }
    return sum;
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
