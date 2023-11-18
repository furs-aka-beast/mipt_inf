#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::vector <std::vector <int>> data = {{1, 2 ,3}, {4, 5}, {8}};
    auto l = [](std::vector <int> &vec){
        int sum=0;
        for (int i=0; i<vec.size(); i++){
            sum+=vec[i];
        }
        if(sum%2==0){
            for (int i=0; i<vec.size(); i++){
            vec[i]=vec[i]*vec[i];
            }
        }
    };
    std::for_each(data.begin(),data.end(), l);
    for (int i=0; i<data.size(); i++){
            for (int j=0; j<data[i].size(); j++){
            std::cout<<data[i][j]<<' ';
            }
        std::cout<<std::endl;
        }
}