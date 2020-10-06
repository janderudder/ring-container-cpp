#pragma once
#include <initializer_list>
#include <type_traits>
#include <vector>


 template <typename T, typename Alloc =std::allocator<T>>
class Ring
{
    std::vector<T, Alloc>   m_storage;
    size_t                  m_latest_index;

public:
    explicit Ring(Alloc const& =Alloc()) noexcept;
    Ring(size_t, std::initializer_list<T> ={}, Alloc const& =Alloc());

    template <class... Args> void emplace(Args&&...);
    void insert(T const&);
    void insert(T&&);
    void pop();
    void clear();

    auto operator[](size_t) const   -> T const&;
    auto operator[](size_t)         -> T&;
    size_t latest_index() const;
    size_t oldest_index() const;

    auto latest() const -> T const&;
    auto latest()       -> T&;
    auto oldest() const -> T const&;
    auto oldest()       -> T&;

    auto size() const   -> size_t;  // item capacity (ring's size)
    auto count() const  -> size_t;  // actual number of stored items
    bool empty() const;
    bool full() const;

};



#include "Ring.inl.hpp"
