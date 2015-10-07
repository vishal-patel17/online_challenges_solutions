
#include <iostream>
#include <forward_list>
using namespace std;

int factorial(int number){
    int temp;

    if(number <= 1) return 1;

    temp = number * factorial(number - 1);
    return temp;

}

int main() {

    int n;
    forward_list<int> mylist;
    cin>>n;
    int a;
    for(int i = 0; i<n; ++i){
        cin>>a;
        mylist.push_front(a);
    }
    mylist.reverse();

    cout<<endl;
    for(auto&x: mylist){
        cout<<endl<<factorial(x);
    }

    return 0;
}