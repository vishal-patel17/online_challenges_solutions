
#include <iostream>
#include <forward_list>
using namespace std;
int main() {

    int l;
    int n,x,y;
    cin>>l;
    cin.ignore();
    cout<<endl;
    forward_list<int> forward_list1;


    for(int i = 0;i<l;i++){
        cin>>n;
        cin>>x;
        cin>>y;
        cin.ignore();
        forward_list1.push_front(n);
        forward_list1.push_front(x);
        forward_list1.push_front(y);
        forward_list1.reverse();



    }
    forward_list1.reverse();
    for(auto&x: forward_list1) {

        for(int i = 0; i<n;i++){

            if(i % x ==0 && i % y != 0){
                cout<<i<<" ";
            }
        }
    }




    return 0;
}
