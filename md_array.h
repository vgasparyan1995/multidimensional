#include <array>

namespace vg_internal {

template <typename T, int D, int ... Ss>
struct md_array;

template <typename T, int D, int S, int ... Ss>
struct md_array<T, D, S, Ss ...>
{
    static_assert(D > 0);
    static_assert(S > 0);
    static_assert(D == 1 + sizeof...(Ss));
    using type = std::array<typename md_array<T, D - 1, Ss ...>::type, S>;
};

template <typename T>
struct md_array<T, 0>
{
    using type = T;
};

} // namespace md_internal

namespace vg {

template <typename T, int D, int ... Ss>
using md_array = vg_internal::md_array<T, D, Ss ...>::type;

} // namespace vg
