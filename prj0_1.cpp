#include <iostream>
using namespace std;
int main(void){
    string a, b;
    string newa, newb, complement, c;
    cin >> a >> b;
    int a_sign, b_sign;
    a_sign = a[0] == '-';
    b_sign = b[0] == '-';
    int a_size = a.length(), b_size = b.length(), com_size, limit;

    if(a_size >= b_size){
        limit = a_size;
        com_size = a_size - b_size;
        complement.assign(com_size, '0'); 
        newa = a;
        newb = complement + b;
        c = a;
    }
    else{
        limit = b_size;
        com_size = b_size - a_size;
        complement.assign(com_size, '0'); 
        newa = complement + a;
        newb = b;
        c = b;
    }

    int out = 0, sum = 0;
    for(int i = limit - 1; i >= 0; i--){
        sum = newa[i]-'0' + newb[i]-'0' + out;
        if(sum >= 10){
            out = 1;
            sum -= 10;
        }
        else{
            out = 0;
        }
        c[i] = sum + '0'; 
    }
    cout << "1"[1-out] << c << endl;
    return 0;
}