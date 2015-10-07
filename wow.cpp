//
// Created by root on 5/10/15.
//

/*
 * Input

Given a positive integer 0 < x < 50.
Output

Print one word: Wo...ow (letter o must be repeted x times).
 *
 * */
#include <iostream>

using namespace std;

int main() {

    int n;
    string s[50];
    cin>>n;
    cin.ignore();
    cout<<endl;
    for(int i = 0; i<=n;i++){
        s[i] = "o";
    }
    cout<<"W";
    for (int j = 1; j < 50; ++j) {
        cout<<s[j];
    }
    cout<<"w";


    return 0;
}