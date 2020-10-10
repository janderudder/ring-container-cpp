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
    class Internal_storage;

public:
    Ring(size_t sz, T const& = T());
    Ring(std::initializer_list<T>);
    Ring(size_t sz, std::initializer_list<T>);

    void push_back(T const&);
    void pop_back();
    void clear();
    void resize(size_t, T const& = T());

    auto extract_data() const -> std::vector<T, Alloc>;
    void rotate_data();

    auto size() const       -> size_t;
    auto item_count() const -> size_t;
    bool empty() const;

    auto storage() const -> Internal_storage;
    auto storage()       -> Internal_storage;

};



// nested class
////////////////////////////////////////////////////////////////////////////////
 template <typename T, typename Alloc>
class Ring<T,Alloc>::Internal_storage
{
    friend class Ring<T,Alloc>;
    std::vector<T, Alloc>* m_storage_pointer;

private:
    Internal_storage(std::vector<T, Alloc>*) noexcept;

public:
    void shrink_to_fit();

    auto operator[](size_t) const -> T const&;
    auto size() const -> size_t;
    auto capacity() const -> size_t;

    auto begin() const;
    auto end() const;
    auto cbegin() const;
    auto cend() const;
    auto rbegin() const;
    auto rend() const;
    auto crbegin() const;
    auto crend() const;

};



// inline implementation
////////////////////////////////////////////////////////////////////////////////
#include "Ring.inl.hpp"
