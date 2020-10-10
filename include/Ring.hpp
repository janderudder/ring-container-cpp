/*
    Ring container

    Resizable, uses std::vector for storage.

*/
#pragma once
#include <initializer_list>
#include <memory>
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
    Ring(size_t sz, T const& = T());
    Ring(std::initializer_list<T>);
    Ring(size_t sz, std::initializer_list<T>);

    void push_back(T const&);
    void pop_back();
    void clear();
    void resize(size_t, T const& = T());
    void shrink_to_fit();

    auto extract_data() const -> std::vector<T, Alloc>;
    void rotate_data();
    auto storage_view() const -> std::vector<T, Alloc> const&;

    auto size() const       -> size_t;
    auto item_count() const -> size_t;
    bool empty() const;

};



#include "Ring.inl.hpp"
