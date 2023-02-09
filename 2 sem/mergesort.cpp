#include <iostream>
#include <vector>
#include <algorithm>

using i64 = int64_t;
using Array = std::vector<i64>;

void Merge(Array::iterator a_beg, Array::iterator a_end, Array::iterator b_beg, Array::iterator b_end, Array::iterator out)
{
    while ((a_beg != a_end) && (b_beg != b_end))
    {
        if (*a_beg < *b_beg)
        {
            *out = *a_beg;
            ++out;
            ++a_beg;
        }
        else
        {
            *out = *b_beg;
            ++out;
            ++b_beg;
        }
    }
    while (a_beg != a_end)
    {
        *out = *a_beg;
        ++out;
        ++a_beg;
    }
    while (b_beg != b_end)
    {
        *out = *b_beg;
        ++out;
        ++b_beg;
    }
    return;
}
void MergeSort(Array::iterator beg, size_t n, Array::iterator buff)
{
    if (n == 1)
        return;
    if (n == 2)
    {
        if(*beg>*(beg+1)) std::swap(*beg, *(beg+1));
    }
    MergeSort(beg, n / 2, buff);
    MergeSort(beg + n / 2, n - n / 2, buff);
    Merge(beg, beg + n / 2, beg + n / 2, beg + n, buff);
    for (i64 i = 0; i < n; i++)
    {
        *(beg + i) = *(buff + i);
    }
}

int main()
{
    Array data{0, 2, 1, 8, 10, 7};
    Array buff(data.size());
    MergeSort(data.begin(), data.size(), buff.begin());
    for (auto i : data)
        std::cout << i << ' ';
}