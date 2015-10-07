//
// Created by root on 7/10/15.
//

/*

Find N'th term of this sequence.

a1=2, a2=4, a3=11, a4=36, a5=147, a6=778 ... ... ... ... aN.

 Input:
Only one natural number 7<=N<20.

 Output:
One natural number. N'th term of the sequence.

 Example:
Input:
10
Output:
3629814

*/

#include <iostream>
#include <cmath>

using namespace std;

int factorial(int number){
    int temp;

    if(number <= 1) return 1;

    temp = number * factorial(number - 1);
    return temp;

}
int main() {
   int n;
    long int ans;
    cin>>n;
    cin.ignore();
    cout<<endl;
    ans = factorial(n)+pow(2,n)-n;
    cout<<ans;
    return 0;
}
