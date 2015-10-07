
#include <iostream>
#include <forward_list>
using namespace std;

int reverse_function(int number){
    int reverse = 0;


    for(;number!=0;){
        reverse = reverse * 10;
        reverse = reverse + number%10;
        number = number/10;

    }
    return reverse;

}

int main() {

    int n;
    int a,b;
    forward_list<int>mylist;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        cin>>b;

        mylist.push_front(reverse_function(a)+reverse_function(b));

    }


    mylist.reverse();
    forward_list<int>::iterator it;
    for(it = mylist.begin();it!=mylist.end();++it){
        cout<<endl<<reverse_function(*it);

    }
    cout<<endl;






    return 0;
}