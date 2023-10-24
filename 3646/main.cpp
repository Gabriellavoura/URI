#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
 
int main() 
{
    double f1, f2;
    double total;
    cin >> f1;
    cin >> f2;
    
    total = ((((1.0 + f1/100.00) * (1.0 + f2/100.00)) - 1.0) * 100.0);
    
    cout <<fixed << setprecision(6)<< total <<endl;
    return 0;
}