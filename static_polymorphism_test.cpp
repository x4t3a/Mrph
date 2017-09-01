#include <cmath>
#include <iostream>
#include <limits>
#include <ostream>

#include "static_polymorphism.hpp"

class Circle : x4::mrph::Comparable<Circle> {
    private:
        using Radius = double;
        static constexpr auto Epsilon = std::numeric_limits<Radius>::epsilon();
        Radius radius;

    public:
        Circle(Radius r = {}) : radius{ r } {}

    public:
        friend inline bool
        operator == (Circle const& lhs,
                     Circle const& rhs)
        { return (std::abs(lhs.radius - rhs.radius) < Circle::Epsilon); }

        friend inline bool
        operator < (Circle const& lhs,
                    Circle const& rhs)
        { return (lhs.radius < rhs.radius); }

    public:
        friend inline std::ostream&
        operator << (std::ostream& os,
                     Circle const& circle)
        {
            os << "Circle{ Radius: " << circle.radius << " }";
            return os;
        }
}; /// Circle

class Train : x4::mrph::LazyComparable<Train> {
    private:
        using CarriagesNumber = unsigned long;
        CarriagesNumber carriages_number;

    public:
        Train(CarriagesNumber cn = {}) : carriages_number{ cn } {}

    public:
        friend inline bool
        operator < (Train const& lhs,
                    Train const& rhs)
        { return (lhs.carriages_number < rhs.carriages_number); }

    public:
        friend inline std::ostream&
        operator << (std::ostream& os,
                     Train const& train)
        {
            os << "Train{ Carriages Number: " << train.carriages_number << " }";
            return os;
        }
}; /// Train

int
main(int argc, char* argv[])
{
    {
        Circle small{ 3.1 };
        Circle small2{ 3.1 };
        Circle big{ 15.0 };

        std::cout << small << " < " << big << " ? " << (small < big) << std::endl;
        std::cout << small << " > " << big << " ? " << (small > big) << std::endl;
        std::cout << small << " == " << small2 << " ? " << (small == small2) << std::endl;
    }

    {
        Train small{ 3 };
        Train small2{ 3 };
        Train big{ 15 };

        std::cout << small << " < " << big << " ? " << (small < big) << std::endl;
        std::cout << small << " > " << big << " ? " << (small > big) << std::endl;
        std::cout << small << " == " << small2 << " ? " << (small == small2) << std::endl;
    }
}
