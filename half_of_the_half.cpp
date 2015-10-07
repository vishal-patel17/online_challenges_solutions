

/*
 Input:
4
your
progress
is
noticeable

Output:
y
po
i
ntc

 */

#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

int main() {

    forward_list<string> forward_list1;
    int n;
    cin>>n;
    cin.ignore();
    cout<<endl;
    string s;

    for(int i = 0; i<n; i++){
        cin>>s;
        forward_list1.push_front(s);
    }

    forward_list1.reverse();
    for(auto&x: forward_list1) {
//        x.length()/2;
        x.resize(x.length()/2);
    }









    return 0;
}
