#include<iostream>
#include<vector>

using namespace std;
template<class T,class M>
void sort_m(T first,T last,M l){
    size_t s=0;
    auto n=first;
    while(first!=last){
        ++s;
        ++first;
    }
    first=n;
    for(int i=0;i<s;i++){
       auto t=first;
         while(first!=last){
        auto F=*first;
    auto m=*(first+1);
    if(m==*last){
        break;
    }
        
    if(l(F,m)){
        ++first;
    }
    else{
        *first=m;
        *(first+1)=F;
        ++first;
    }
         }
   
    first=t;
    }
}
