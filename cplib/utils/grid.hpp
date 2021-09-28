#ifndef CPLIB_GRID_HPP
#define CPLIB_GRID_HPP

#include <stdexcept>
#include <utility>

namespace cplib
{

using namespace std;

struct Direction
{
    int first;
    int second;

    bool operator==(Direction const &other) const
    {
        return first == other.first and second == other.second;
    }

    bool operator!=(Direction const &other) const
    {
        return first != other.first or second != other.second;
    }

    Direction opposite() const { return Direction{-first, -second}; }
    friend pair<int, int> operator+(pair<int, int> const &a, Direction const &b)
    {
        return make_pair(a.first + b.first, a.second + b.second);
    }
};

Direction const UP{-1, 0};
Direction const RIGHT{0, +1};
Direction const DOWN{+1, 0};
Direction const LEFT{0, -1};

char dir_to_char(Direction const &dir)
{
    if (dir == UP)
        return 'U';
    if (dir == RIGHT)
        return 'R';
    if (dir == DOWN)
        return 'D';
    if (dir == LEFT)
        return 'L';
    throw std::runtime_error("Unrecognized standard direction character.");
}

Direction char_to_dir(char c)
{
    switch (c)
    {
    case 'U':
        return UP;
    case 'R':
        return RIGHT;
    case 'D':
        return DOWN;
    case 'L':
        return LEFT;
    default:
        throw std::runtime_error("Unrecognized standard direction.");
    };
}

} // namespace cplib

#endif // CPLIB_GRID_HPP
