#include <iostream>

struct Point_3D {
    double x, y, z;
};

double distance_sqr(Point_3D const &a, Point_3D const &b){
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2) + pow(a.z-b.z, 2);
};

Point_3D middle(Point_3D const &a, Point_3D const &b){
    return (Point_3D) {(a.x - b.x) / 2 + b.x, (a.y - b.y) / 2 + b.y, (a.z - b.z) / 2 + b.z};
};
Point_3D center_of_mass(Point_3D const *begin, Point_3D const *end){
    Point_3D center={0,0,0};
    for (int i = 0; (begin + i) != end; i++){
        center.x=(center.x*i + (begin+i)->x/(i+1));
    };
    return center;
};
struct Point_3D_Cloud {
    Point_3D *points = nullptr;
    unsigned size = 0;
};

Point_3D_Cloud cloud_new(unsigned N){
    Point_3D_Cloud a;
    a.points = new Point_3D[N];
    a.size = N;
    return a;
}; //N>0
void cloud_free(Point_3D_Cloud &cloud){
     //delete[cloud.size)] cloud.points;
}


int main(){
    int a;
    std::cin>>a;
    std::cout<<a;
}