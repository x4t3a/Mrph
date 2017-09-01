#ifndef X4_MRPH_STATIC_POLYMORPHISM_HEADER_GUARD
#   define X4_MRPH_STATIC_POLYMORPHISM_HEADER_GUARD

namespace x4 {
    namespace mrph {

// In order to provide your class (assume it encapsulates two fields, x and y)
// with all the comp. operators implement the == and < operators  in your class, e.g:
//   friend inline bool operator == (YourClass const& lhs,
//                                   YourClass const& rhs)
//   { return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y); }
// and inherit it this way:
//   class YourClass : x4::intf::Comparable<YourClass>
        template <typename T>
        struct Comparable {
            friend inline bool
            operator > (T const& lhs, T const& rhs) noexcept
            { return  (rhs < lhs); }

            friend inline bool
            operator <= (T const& lhs, T const& rhs) noexcept
            { return !(lhs > rhs); }

            friend inline bool
            operator >= (T const& lhs, T const& rhs) noexcept
            { return !(lhs < rhs); }

            friend inline bool
            operator != (T const& lhs, T const& rhs) noexcept
            { return !(lhs == rhs); }
        }; /// Comparable

        template <typename T>
        struct LazyComparable : public Comparable<T> {
            friend inline bool
            operator == (T const& lhs, T const& rhs) noexcept
            { return  !(lhs > rhs) && !(lhs < rhs); }
        }; /// LazyComparable
    } /// mrph
} /// x4

#endif /// X4_MRPH_STATIC_POLYMORPHISM_HEADER_GUARD
