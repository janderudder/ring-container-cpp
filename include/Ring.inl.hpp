#include "Ring.hpp"



 template <class T, class A>
Ring<T,A>::Ring(size_t sz, T const& item_model) noexcept
    : m_storage   (sz, item_model)
    , m_data_size {0}
    , m_end_index {0}
{
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
    if (m_data_size != 0)
    {
        --m_data_size;
        --m_end_index;

        if (m_end_index == index_t(-1)) {
            m_end_index = size()-1;
        }
    }
    else
    {
        m_end_index = 0;
    }
}




////////////////////////////////////////////////////////////////////////////////
 template <class T, class A>
auto Ring<T,A>::data() const -> std::vector<T,A>
{
    if (m_data_size == 0)
    {
        return std::vector<T,A>{};
    }
    else if (m_end_index >= m_data_size)
    {
        auto const data_start_it = m_storage.cbegin()+(m_end_index-m_data_size);
        return {data_start_it, m_storage.cbegin()+m_end_index};
    }
    else
    {
        auto const data_start_index = size() - (m_data_size - m_end_index);

        std::vector<T,A> data_vec {
            m_storage.cbegin() + data_start_index,
            m_storage.cend()
        };

        data_vec.insert(data_vec.end(),
            m_storage.cbegin(),
            m_storage.cbegin()+m_end_index);

        return data_vec;
    }
}




////////////////////////////////////////////////////////////////////////////////
 template <class T, class A>
auto Ring<T,A>::size() const -> size_t
{
    return m_storage.size();
}
