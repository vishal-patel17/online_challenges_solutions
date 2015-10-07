//
// Created by Hemant on 29-09-2015.
//
#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
       cin>> arr[i];
    }


int r,temp,sum;
    cout<<endl;
    for(int i = 0; i<n;i++) {
        for (temp = arr[i]; arr[i] != 0; arr[i] = arr[i] / 10) {
            r = arr[i] % 10;
            sum = sum * 10 + r;
        }
        if(temp==sum)
            cout << temp << " is a palindrome";
        else
            cout << " is not a palindrome";
    }





    return 0;
}

