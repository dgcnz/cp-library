#ifndef CPLIB_GRID_HPP
#define CPLIB_GRID_HPP

#include <stdexcept>
#include <utility>

namespace cplib
{
using namespace std;
struct Direction
{
    int const first;
    int const second;

    constexpr bool operator==(Direction const &other) const
    {
        return first == other.first and second == other.second;
    }
    constexpr bool operator!=(Direction const &other) const
    {
        return first != other.first or second != other.second;
    }

    constexpr Direction opposite() const { return Direction{-first, -second}; }
    constexpr friend pair<int, int> operator+(pair<int, int> const &a,
                                              Direction const &     b)
    {
        return make_pair(a.first + b.first, a.second + b.second);
    }

    static const Direction UP;
    static const Direction RIGHT;
    static const Direction DOWN;
    static const Direction LEFT;
};

char dir_to_char(Direction const &dir)
{
    if (dir == Direction::UP)
        return 'U';
    if (dir == Direction::RIGHT)
        return 'R';
    if (dir == Direction::DOWN)
        return 'D';
    if (dir == Direction::LEFT)
        return 'L';
    throw std::runtime_error("Unrecognized standard direction character.");
}

Direction char_to_dir(char c)
{
    switch (c)
    {
    case 'U':
        return Direction::UP;
    case 'R':
        return Direction::RIGHT;
    case 'D':
        return Direction::DOWN;
    case 'L':
        return Direction::LEFT;
    default:
        throw std::runtime_error("Unrecognized standard direction.");
    };
}

Direction const Direction::UP    = {-1, 0};
Direction const Direction::RIGHT = {0, +1};
Direction const Direction::DOWN  = {+1, 0};
Direction const Direction::LEFT  = {0, -1};

} // namespace cplib

#endif // CPLIB_GRID_HPP
