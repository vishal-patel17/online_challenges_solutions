//
/*
 Input
Number N of test cases in a single line. ( N <= 30 ) Each of the next N lines consists of 6 integer numbers -- the lengths of the edges of a tetrahedron separated by single spaces. The edges are not longer than 1000 and for the tetrahedron WXYZ, the order of the edges is: WX, WY, WZ, XY, XZ, YZ.

 Output
N lines, each consisting of a real number given with four digits decimal precision equal to the radius of a sphere inscribed in the given tetrahedron.

 Example

Input:
2
1 1 1 1 1 1
1000 999 998 5 5 6

Output:
0.2041
1.4189
 */

#include <iostream>
#include<cstdio>
#include<cmath>
#include <forward_list>

#define sqr(x) (x)*(x)
using namespace std;

int test;

inline double Calc(double a,double b,double c)
{
    return (sqr(a)+sqr(b)-sqr(c))/(2*a*b);
}
inline double Area(double a,double b,double c)
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    forward_list<double> forward_list1;


    for (scanf("%d",&test);test--;)
    {

        double x,y,z,a,b,c;
        scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&a,&b,&c);
        double alpha=Calc(x,y,a);
        double beta=Calc(x,z,b);
        double gama=Calc(y,z,c);
        double V=(x*y*z)/6.0*sqrt(1+2*alpha*beta*gama-sqr(alpha)-sqr(beta)-sqr(gama));
        double S1=Area(a,b,c),S2=Area(x,y,a),S3=Area(x,z,b),S4=Area(y,z,c);
        double R=3*V/(S1+S2+S3+S4);
        forward_list1.push_front(R);




    }
    forward_list1.reverse();
    for(auto& x:forward_list1){
        printf("%.4lf\n",x);
    }


    return 0;
}

