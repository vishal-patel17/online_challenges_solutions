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
using namespace std;
int main() {

    int l;
    int n[10],x[10],y[10],ans[10];
    cin>>l;
    cin.ignore();
    cout<<endl;


    for(int i = 0;i<l;i++){
        cin>>n[i];
        cin>>x[i];
        cin>>y[i];
        cin.ignore();

    }
    for(int i=0;i<l;i++) {
        for (int j = 0; j < n[i]; j++) {
            if (j % x[i] == 0 && j % y[i] != 0) {
                cout << j << " ";
            }
        }
        cout<<endl;
    }

    return 0;
}
