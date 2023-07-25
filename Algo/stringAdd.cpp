#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string addString(string s1, string s2){
    if(s1.length() > s2.length()){
        swap(s1, s2);
    }

    const int n = s1.size();
    const int m = s2.size();
    const int diff = m - n;

    string res{""};
    int sum{0}, carry{0};

    for(int i = n - 1; i >= 0; i--){
        sum = ((s1[i] - '0') + (s2[i + diff] - '0') + carry);
        carry = sum / 10;
        res.push_back((sum % 10) + '0');
    }

    for(int i = diff - 1; i >= 0; i--){
        sum = (s2[i] - '0') + carry;
        carry = sum / 10;
        res.push_back((sum % 10) + '0');
    }

    if(carry){
        res.push_back(carry + '0');
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(){
    string s1{""}, s2{""};
    cin>>s1>>s2;
    cout<<"Addition is: "<<addString(s1, s2)<<endl;
    return 0;
}
