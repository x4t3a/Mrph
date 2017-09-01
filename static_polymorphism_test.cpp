#include "static_polymorphism.hpp"
#include <limits>
#include <cmath>
#include <iostream>

class Circle : x4::mrph::Comparable<Circle> {
    private:
        using Radius = double;
        static constexpr auto LengthEpsilon = std::numeric_limits<Radius>::epsilon();
        Radius radius;

    public:
        Circle(Radius r = {}) : radius{ r } {}

    public:
        friend inline bool operator == (Circle const& lhs,
                                        Circle const& rhs)
        { return (std::abs(lhs.radius - rhs.radius) < Circle::LengthEpsilon); }

        friend inline bool operator < (Circle const& lhs,
                                       Circle const& rhs)
        { return lhs.radius < rhs.radius; }
};

int
main(int argc, char* argv[])
{
    Circle small{ 3.0 };
    Circle small2{ 3.0 };
    Circle big{ 15.0 };
    std::cout << (small < big) << std::endl;
    std::cout << (small > big) << std::endl;
    std::cout << (small == small2) << std::endl;
}