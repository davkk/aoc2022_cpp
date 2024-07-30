#include <array>
#include <cstdlib>
#include <format>
#include <iostream>
#include <stdexcept>

enum Shape {
    Rock,
    Paper,
    Scissors,
};

constexpr Shape to_shape(char c) {
    switch (c) {
    case 'A':
    case 'X':
        return Rock;
    case 'B':
    case 'Y':
        return Paper;
    case 'C':
    case 'Z':
        return Scissors;
    default:
        throw std::runtime_error(std::format("unrecognized shape {}", c));
    }
}

namespace Part1 {
int solve() {
    int result{0};

    for (std::string line; std::getline(std::cin, line);) {
        auto opponent{to_shape(line.front())};
        auto you{to_shape(line.back())};

        int round_score{you + 1};

        if (opponent == you) {
            result += round_score + 3;
            continue;
        }

        switch (opponent) {
        case Rock:
            round_score += (you == Paper) * 6;
            break;
        case Paper:
            round_score += (you == Scissors) * 6;
            break;
        case Scissors:
            round_score += (you == Rock) * 6;
            break;
        }

        result += round_score;
    }

    return result;
}
}  // namespace Part1

namespace Part2 {
int solve() {
    int result{0};

    constexpr std::array<Shape, 3> beats{Scissors, Rock, Paper};

    for (std::string line; std::getline(std::cin, line);) {
        auto opponent{to_shape(line.front())};

        switch (line.back()) {
        case 'X':  // loss
            ++result += 0 + beats[opponent];
            continue;
        case 'Y':  // draw
            ++result += 3 + opponent;
            continue;
        case 'Z':  // win
            ++result += 6 + beats[beats[opponent]];
            continue;
        }
    }

    return result;
}
}  // namespace Part2

int main() {
    // std::cout << Part1::solve() << '\n';
    std::cout << Part2::solve() << '\n';

    return 0;
}
