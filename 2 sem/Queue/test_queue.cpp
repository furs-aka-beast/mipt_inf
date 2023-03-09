#include <iostream>
#include <deque>
#include <algorithm>
#include <fstream>
//#include "DoubleVectorQueue.h"
//#include "LinkArr.h"
#include "CircBuff.h"

using i64 = int64_t;

int main(){

  std::deque <i64> q{};
  Queue Q{};
  
  for (i64 i = 0; i < 1000; i++){
    i64 value = std::rand()%100;
    i64 oper = std::rand()%2;
    std::cout<<"Mine"<<std::endl;
      for(i64 j=Q.Size()-1;j>=0;j--){std::cout<<Q[j]<<' ';}
      std::cout<<std::endl<<"Std:"<<std::endl;
      for(i64 j=q.size()-1;j>=0;j--){std::cout<<q[j]<<' ';}
      std::cout<<'\n'<<oper<<'\n';
    if (q.size() != 0 && oper == 0){
      q.pop_front();
      Q.PopFront();
    }
    else{
      q.push_back(value);
      Q.PushBack(value);
    }
    for(i64 j=q.size()-1;j>=0;j--){
      if(q[j]!=Q[j]){std::cout<<"Error"<<'\n';
      std::cout<<"Mine"<<std::endl;
      for(i64 j=Q.Size()-1;j>=0;j--){std::cout<<Q[j]<<' ';}
      std::cout<<std::endl<<"Std:"<<std::endl;
      for(i64 j=q.size()-1;j>=0;j--){std::cout<<q[j]<<' ';}
      return 0;
      }
    }
  }
  std::cout<<"Success";

}
