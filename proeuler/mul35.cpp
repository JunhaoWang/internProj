#include<vector>
#include<iostream>

// easy problems
int multipleSum(std::vector<int> muls,int thre){
    int count = 0;
    for (int i = 1; i < thre; ++i){
        for (auto j: muls){
            if (! (i % j)){
                count += i;
                break;
            }
        }
    }
    return count;
}

int evenFibSum(int thre){
    std::vector<int> v {1,2};
    int count = 2;
    while (v.back() < thre){
        v.push_back(v[v.size()-1]+v[v.size()-2]);
        if (!(v.back()%2)){
            count+=v.back();
        }
    }
    return count;
}

// medium problems


int main() {
    std::cout << multipleSum({3, 5}, 1000) << '\n';
    std::cout << evenFibSum(4000000) << '\n';
    return 0;
}
