#ifndef TENSOR_LAYOUT_HPP
#define TENSOR_LAYOUT_HPP

namespace ck {
namespace tensor_layout {

struct BaseTensorLayout
{
};

namespace gemm {

struct RowMajor : public BaseTensorLayout
{
    static constexpr const char* name = "RowMajor";
};

struct ColumnMajor : public BaseTensorLayout
{
    static constexpr const char* name = "ColumnMajor";
};
} // namespace gemm

namespace convolution {

// 1D Conv
struct NWC : public BaseTensorLayout
{
    static constexpr const char* name = "NWC";
};

struct KXC : public BaseTensorLayout
{
    static constexpr const char* name = "KXC";
};

struct NWK : public BaseTensorLayout
{
    static constexpr const char* name = "NWK";
};

struct NCW : public BaseTensorLayout
{
    static constexpr const char* name = "NCW";
};

struct KCX : public BaseTensorLayout
{
    static constexpr const char* name = "KCX";
};

struct NKW : public BaseTensorLayout
{
    static constexpr const char* name = "NKW";
};

// 2D Conv
struct NHWC : public BaseTensorLayout
{
    static constexpr const char* name = "NHWC";
};

struct KYXC : public BaseTensorLayout
{
    static constexpr const char* name = "KYXC";
};

struct NHWK : public BaseTensorLayout
{
    static constexpr const char* name = "NHWK";
};

struct NCHW : public BaseTensorLayout
{
    static constexpr const char* name = "NCHW";
};

struct KCYX : public BaseTensorLayout
{
    static constexpr const char* name = "KCYX";
};

struct NKHW : public BaseTensorLayout
{
    static constexpr const char* name = "NKHW";
};

struct NDHWC : public BaseTensorLayout
{
};

struct KZYXC : public BaseTensorLayout
{
};

struct NDHWK : public BaseTensorLayout
{
};

} // namespace convolution

template <
    typename Layout,
    typename std::enable_if<std::is_base_of<BaseTensorLayout, Layout>::value, bool>::type = false>
std::ostream& operator<<(std::ostream& os, const Layout&)
{
    os << Layout::name;
    return os;
}

} // namespace tensor_layout
} // namespace ck
#endif