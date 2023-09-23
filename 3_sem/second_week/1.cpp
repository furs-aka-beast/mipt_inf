#include <algorithm>
struct Point {
    int const x, y;
    Point(): x(0), y(0){}
    Point(int a, int b): x(a), y(b){}
    Point minx(Point const sec) const {
        return Point(std::min(this->x, sec.x), this->y);
    }
    Point miny(Point const sec) const {
        return Point(this->x,std::min(sec.y, this->y));
    }
    Point maxx(Point  const sec) const {
        return Point(std::max(this->x, sec.x), this->y);
    }
    Point maxy(Point const sec) const{
        return Point(this->x,std::max(sec.y, this->y));
    }
};