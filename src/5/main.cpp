#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

std::vector<std::string> split_on_space(std::string_view str) {
    std::vector<std::string> parts{};
    std::string part{};

    for (const auto& ch : str) {
        if (std::isspace(ch)) {
            parts.push_back(part);
            part.clear();
        } else [[likely]] {
            part += ch;
        }
    }
    parts.push_back(part);

    return parts;
}

class CrateStack {
private:
    std::vector<std::vector<char>> crates{};

public:
    explicit CrateStack(const std::vector<std::string>& init_state)
        : crates((init_state.back().size() + 2) / 4) {
        const auto& reversed{
            init_state                     //
            | std::ranges::views::reverse  //
            | std::ranges::views::drop(1)
        };

        for (const auto& level : reversed) {
            size_t num_boxes{(level.size() + 1) / 4};
            for (size_t i{0}; i < num_boxes; ++i) {
                auto crate{level[4 * i + 1]};
                if (!std::isspace(crate)) {
                    crates[i].push_back(crate);
                }
            }
        }
    }

    void move_crates_one(size_t move, size_t from, size_t to) {
        for (size_t i{0}; i < move; ++i) {
            char top{crates[from].back()};
            crates[from].pop_back();
            crates[to].push_back(top);
        }
    }

    void move_crates_many(size_t move, size_t from, size_t to) {
        const auto& to_move{
            crates[from]                      //
            | std::ranges::views::reverse     //
            | std::ranges::views::take(move)  //
            | std::ranges::views::reverse
        };
        for (const auto crate : to_move) {
            crates[to].push_back(crate);
        }
        crates[from].erase(
            crates[from].end() - static_cast<int>(move), crates[from].end()
        );
    }

    std::string current_state() {
        std::string result{};
        for (const auto& col : crates) {
            result += col.back();
        }
        return result;
    }
};

namespace Part1 {
std::string solve() {
    std::string line{};

    std::vector<std::string> init_state{};
    while (std::getline(std::cin, line) && !line.empty()) {
        init_state.push_back(line);
    };

    CrateStack crate_stack{init_state};

    while (std::getline(std::cin, line)) {
        auto parts{split_on_space(line)};

        size_t move{std::stoul(parts[1])};
        size_t from{std::stoul(parts[3]) - 1};
        size_t to{std::stoul(parts[5]) - 1};

        crate_stack.move_crates_one(move, from, to);
    }

    return crate_stack.current_state();
}
}  // namespace Part1

namespace Part2 {
std::string solve() {
    std::string line{};

    std::vector<std::string> init_state{};
    while (std::getline(std::cin, line) && !line.empty()) {
        init_state.push_back(line);
    };

    CrateStack crate_stack{init_state};

    while (std::getline(std::cin, line)) {
        auto parts{split_on_space(line)};

        size_t move{std::stoul(parts[1])};
        size_t from{std::stoul(parts[3]) - 1};
        size_t to{std::stoul(parts[5]) - 1};

        crate_stack.move_crates_many(move, from, to);
    }

    return crate_stack.current_state();
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
