#pragma once
#include <initializer_list>
#include <memory>
#include <type_traits>
#include <vector>


 template <typename T, typename Alloc =std::allocator<T>>
class Ring
{
public:
    using index_t = std::size_t;

private:
    std::vector<T, Alloc>   m_storage;
    size_t                  m_data_size;
    index_t                 m_end_index;

public:
    Ring(size_t sz, T const& = T()) noexcept;

    void push_back(T const&);
    void pop_back();

    auto data() const -> std::vector<T, Alloc>;

    auto size() const -> size_t;

};



#include "Ring.inl.hpp"
