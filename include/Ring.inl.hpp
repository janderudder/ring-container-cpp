#include "Ring.hpp"
#include <algorithm>



 template <class T, class A>
Ring<T,A>::Ring(size_t sz, T const& item_model)
    : m_storage   (sz, item_model)
    , m_data_size {0}
    , m_end_index {0}
{
}




 template <class T, class A>
Ring<T,A>::Ring(std::initializer_list<T> const items)
    : m_storage     {items}
    , m_data_size   {m_storage.size()}
    , m_end_index   {0}
{
}




 template <class T, class A>
Ring<T,A>::Ring(size_t sz, std::initializer_list<T> const items)
    : m_storage   {items}
    , m_data_size {std::min(sz, items.size())}
    , m_end_index {sz < items.size() ? 0 : items.size()}
{
    m_storage.resize(sz);
}




////////////////////////////////////////////////////////////////////////////////
 template <class T, class A>
void Ring<T,A>::push_back(T const& item)
{
    if (m_data_size < size()) {
        ++m_data_size;
    }

    m_storage[m_end_index] = item;
    ++m_end_index;

    if (m_end_index == size()) {
        m_end_index = 0;
    }
}




 template <class T, class A>
void Ring<T,A>::pop_back()
{
    if (m_data_size > 1)
    {
        --m_data_size;
        --m_end_index;

        if (m_end_index == index_t(-1)) {
            m_end_index = size()-1;
        }
    }
    else
    {
        m_data_size = 0;
        m_end_index = 0;
    }
}




 template <class T, class A>
void Ring<T,A>::clear()
{
    m_data_size = 0;
    m_end_index = 0;
}




////////////////////////////////////////////////////////////////////////////////
 template <class T, class A>
auto Ring<T,A>::extract_data() const -> std::vector<T,A>
{
    if (m_data_size == 0)
    {
        return std::vector<T,A>{};
    }
    else if (m_end_index >= m_data_size)
    {
        return {
            m_storage.cbegin() + (m_end_index-m_data_size),
            m_storage.cbegin() + m_end_index
        };
    }
    else
    {
        auto const data_start_index = size() - (m_data_size - m_end_index);

        std::vector<T,A> data_vec {
            m_storage.cbegin() + data_start_index,
            m_storage.cend()
        };

        data_vec.insert(
            data_vec.end(),
            m_storage.cbegin(),
            m_storage.cbegin() + m_end_index
        );

        return data_vec;
    }
}




 template <class T, class A>
void Ring<T,A>::rotate_data()
{
    std::rotate(
        m_storage.begin(),
        m_storage.begin() + size() - (m_data_size - m_end_index),
        m_storage.end());

    m_end_index = m_data_size;

    if (m_end_index == size()) {
        m_end_index = 0;
    }
}




template <class T, class A>
auto Ring<T,A>::storage_view() const -> std::vector<T,A> const&
{
    return m_storage;
}




////////////////////////////////////////////////////////////////////////////////
 template <class T, class A>
auto Ring<T,A>::size() const -> size_t
{
    return m_storage.size();
}




 template <class T, class A>
auto Ring<T,A>::item_count() const -> size_t
{
    return m_data_size;
}




 template <class T, class A>
bool Ring<T,A>::empty() const
{
    return m_data_size == 0;
}




////////////////////////////////////////////////////////////////////////////////
 template <class T, class A>
void Ring<T,A>::resize(size_t new_size, T const& item_model)
{
    // if (new_size > m_data_size && m_end_index >= m_data_size)
    // {
    //     // m_end_index =
    // }
    if (m_end_index >= new_size)
    {

    }

    if (new_size < size())
    {
        if (m_end_index >= m_data_size)
        {
            auto const data_end = m_storage.begin() + m_end_index;

            std::rotate(
                m_storage.begin(),
                data_end - new_size,
                data_end);
        }
        else
        {

        }
    }

    if (new_size > m_data_size)
    {
        if (m_end_index >= m_data_size){
        }
    }

    m_storage.resize(new_size);
}




 template <class T, class A>
void Ring<T,A>::shrink_to_fit()
{
    m_storage.shrink_to_fit();
}
