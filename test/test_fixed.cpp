#include "fixed_size_map.hpp"

using namespace std;
int main(){
    fixed_size_unordered_map<int,int,20> fixed_map{std::make_pair(1,1),std::make_pair(10,10),std::make_pair(20,20)};

    for(auto iter=fixed_map.begin();iter!=fixed_map.end();++iter){
        std::cout<<iter->first<<" "<<iter->second<<std::endl;
    }
    return 0;
}

