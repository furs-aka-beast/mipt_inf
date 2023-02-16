#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <fstream>

using i64 = int64_t;
using Array = std::vector<i64>;

void InsertionSort(Array::iterator begin, Array::iterator end)
{
    i64 n = end - begin;
    Array::iterator it = begin;
    for (i64 i = 0; i < n; i++)
    {
        it = begin + i;
        i64 x = *it;
        while (it != begin)
        {
            if (x < *it)
            {
                *(it + 1) = *it;
                *it = x;
            }
            it--;
        }
        if (x < *it)
        {
            *(it + 1) = *it;
            *it = x;
        }
    }
}

void InsSort(Array::iterator beg, Array::iterator end)
{
    for (i64 i = 1; i < end - beg; i++)
    {
        if (*(beg + i) < *(beg + i - 1))
        {
            i64 c = i - 2;
            while (c >= 0)
            {
                if (c < *(beg + i))
                    break;
            }
            i64 tmp = *(beg + i);
            for (i64 j = i - 1; j > c; j--)
            {
            }
        }
    }
}

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
void MergeSort(Array::iterator beg, size_t n, Array::iterator buff, i64 act)
{
    if (n == 1)
        return;
    if (n == 2)
    {
        if (*beg > *(beg + 1))
            std::swap(*beg, *(beg + 1));
    }
    else if (n < act)
    {
        InsertionSort(beg, beg + n);
    }
    else
    {
        MergeSort(beg, n / 2, buff, act);
        MergeSort(beg + n / 2, n - n / 2, buff, act);
        Merge(beg, beg + n / 2, beg + n / 2, beg + n, buff);
        for (i64 i = 0; i < n; i++)
        {
            *(beg + i) = *(buff + i);
        }
    }
}
void FillArray(Array::iterator begin, i64 n)
{

    std::mt19937 engine;
    engine.seed(std::time(nullptr));
    for (i64 i = 0; i < n; i++)
    {
        *(begin + i) = engine() % 100000;
    }
}

int main()
{
    std::ofstream fout;
    fout.open("optimised.csv");
    fout << "number of elements"
         << ","
         << "time1"
         << ","
         << "time2"
         << ","
         << "time3"
         << ","
         << "time4" << std::endl;
    for (i64 n = 500; n <= 100000; n += 500)
    {
        fout << n;
        for (i64 i = 0; i < 4; i++)
        {
            Array data(n);
            FillArray(data.begin(), n);
            Array buff(data.size());
            auto start = std::chrono::steady_clock::now();
            MergeSort(data.begin(), data.size(), buff.begin(),16);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            fout << "," << (double)elapsed_seconds.count();
        }
        fout << std::endl;
    }
}