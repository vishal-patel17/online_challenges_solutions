
#include <iostream>

using namespace std;

int main() {
   int n ,sum = 0;
    while (cin>>n){
        sum += sum + n;
        cout<<sum;
    }
    return 0;



}
