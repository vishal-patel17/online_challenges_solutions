/* Problem: stop processing input after 42 and display result till 42 */


#include <iostream>

using namespace std;

int main() {

    int arr[5];
    for (int i = 0; i <5 ; ++i) {
        cin>>arr[i];
    }

    for(auto& x:arr) {

        if (x == 42) {
            break;
        }
        cout << x << endl;
    }


    return 0;
}