#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    const double pi = 3.14159;
    double area, raio;
    cin >> raio;
    area = pi * (raio * raio);
    
    cout << fixed << setprecision(4) << "A=" << area <<endl;
    return 0;
}