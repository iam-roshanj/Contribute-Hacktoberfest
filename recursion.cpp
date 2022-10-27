#include <iostream>
using namespace std;

long int tailFactorial(long int n, long int result=1) {
    if (n==0) return result;
    return tailFactorial(n-1, result*n);     // The last executed statement is recursive call
}

long int tailFibonacci(long int n, long int a=1, long int b=1) {
    if (n==1) return a;
    if (n==2) return b;
    return tailFibonacci(n-1, b, a+b);
}

int main() {
    cout << tailFibonacci(10) << endl;
    cout << tailFactorial(7);
}
