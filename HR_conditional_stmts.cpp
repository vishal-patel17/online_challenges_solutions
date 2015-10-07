//
// Created by Hemant on 26-09-2015.
//
#include <iostream>
//#define MAXSIZE 100
#include <forward_list>
using namespace std;

int main() {

    forward_list<int> forward_list1;
    bool flag = true;
    int n;
    while (flag){
        cin>>n;
        forward_list1.emplace_front(n);
        if(n == 0){
            flag = false;
            break;
        }
    }

    cout<<"Output: "<<endl;

    forward_list1.reverse();
    for(auto& x:forward_list1){
//        cout<<x<<endl;
        if (x == 42){
            break;
        }cout<<x<<endl;



    }






    return 0;
}
