template <int...List>
struct IntList;

template <int H, int ... T>
struct IntList <H, T...>
{
    int Head=H;
    using Tail=IntList<T...>
};
template <>
struct TypeList{};
