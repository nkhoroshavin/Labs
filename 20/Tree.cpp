#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    tree_ t;
    int n;
    cout << "N > ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t.insert(a);
    }
    t.print();
    t.min();
}