#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int a = 44;              // 32+8+4 101100
    int b = 22;              // 16+4+2 010110
    cout << (a | b) << endl; // 32+16+8+4+2 111110
    cout << (a & b) << endl;
    cout << (a ^ b) << endl; // 异或
    cout << ~a << endl;
    cout << (a >> 1) << endl;
    cout << (a << 1) << endl;
}