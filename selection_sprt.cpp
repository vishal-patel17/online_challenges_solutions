//
// Created by Hemant on 30-09-2015.
//

#include <iostream>

using namespace std;

//void selection_sor

int main() {
    int data[] = {43,56,32,12,76,9};
    int temp;
    for(int i = 0 ; i < 6; i++){
        cout<<data[i]<<" ";
    }
    for(int i = 0; i< 6-1; ++i){
        for(int j = i + 1; j<6; j++){

            if(data[i]>data[j]){
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }

        }
    }
    cout<<endl;
    for(auto&x:data) cout<<" "<<x;
    cout<<endl;
    return 0;
}