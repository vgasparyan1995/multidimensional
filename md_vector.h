#include <vector>

namespace vg_internal {

template <typename T, int D>
struct md_vector
{
    static_assert(D > 0);
    using type = std::vector<typename md_vector<T, D - 1>::type>;
};

template <typename T>
struct md_vector<T, 0>
{
    using type = T;
};

} // namespace vg_internal

namespace vg {

template <typename T, int D>
using md_vector = vg_internal::md_vector<T, D>::type;

} // namespace vg
