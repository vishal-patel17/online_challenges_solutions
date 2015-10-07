//
// Created by root on 5/10/15.
//

/* Input

Two numbers: a and b separated by space, where 1 <= a <= b <=100.
Output

Computed sum: a*a + (a+1)*(a+1) + ... + (b-1)*(b-1) + b*b

 */

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

    int x,y;
    cin >> x >> y;

    int z = 0;
    for(int i = x;i <= y;i++)
    {
        z += (i*i);
    }

    cout<<endl;
    cout<< z;


    return 0;
}