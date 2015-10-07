//
// Created by root on 7/10/15.
//

/*  We have to input 3 integers n,x,y. So here in this example (1st case) n=7,x=2,y=4.
and in the second case n=35, x=5, y=12
so we have to print the numbers which are divisible by x but not by y
and those numbers should be less than n.
So in the first case we have to print those numbers which are divisible by 2
 but not by 4 and less than 7 so the answer is 2, 6
 which is divisible by 2 but not by 4 and those are less than 7.

 Input:
2
7 2 4
35 5 12
Output:
2 6
5 10 15 20 25 30

 */

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
    for(auto& x:forward_list1) {
        for(int i = 0; i<n;i++){
            if(i % x ==0 && i % y != 0){
                cout<<i<<" ";
            }
        }
    }




    return 0;
}
