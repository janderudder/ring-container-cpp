#include "Ring.hpp"
#include "echo.hpp"
#include "test-tool.hpp"
#include <iostream>
#include <vector>


int main()
{
    constexpr size_t ring_size = 5;

    Ring<int> r {ring_size, 0};
    EXPECT(r.size() == ring_size, "ring size is ring_size");
    {
    auto const data = r.data();
    EXPECT(data.empty(), "ring's data is empty");
    }

    r.push_back(0);
    EXPECT(r.size() == ring_size, "ring size didn't change after insertion");
    {
    auto const data = r.data();
    EXPECT(data.size() == 1, "ring's data size is 1");
    }

    for (size_t n=0; n < ring_size; ++n) {
        r.push_back(n);
    }

    EXPECT(r.size() == ring_size, "ring size didn't change after filling ring");
    {
    auto const data = r.data();
    EXPECT(data.size() == ring_size, "data size is now ring_size");
    }


    r.push_back(-1);

    EXPECT(r.size() == ring_size, "ring size didn't change after inserting more than size of data");
    {
    auto const data = r.data();
    EXPECT(data.size() == ring_size, "data size is still ring_size");
    EXPECT(data[ring_size-1] == -1, "last element of ring.data() is lastly inserted element (-1)");

    for (size_t i=0; i < ring_size-1; ++i) {
        EXPECT(data[i] == int(i+1), "other elements from data are still here, correctly shifted, except the first");
     }
    }

    r.pop_back();
    EXPECT(r.size() == ring_size, "ring size didn't change after pop_back()");
    {
    auto const data = r.data();
    EXPECT(data.size() == ring_size-1, "data size is ring_size-1 after 1 pop_back()");
    }

}
