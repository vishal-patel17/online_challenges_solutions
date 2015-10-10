/* Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
Output

For each integer n given at input, display a line with the value of n!
Example
Sample input:

4
1
2
5
3

Sample output:

1
2
120
6

  */
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