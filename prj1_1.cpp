#include <iostream>
using namespace std;

string PosPos(string a, string b, int limit);
void PosNeg(string a, string b, int limit, int sign);
void Pri(string str, int sign);
int main(void){
    string a, b;
    string newa, newb, complement, c;
    cin >> a >> b;
    int a_sign, b_sign;// 标记负数
    a_sign = a[0] == '-';
    b_sign = b[0] == '-'; 

    a = a.substr(a_sign);// 得到绝对值
    b = b.substr(b_sign);
    int a_size = a.length(), b_size = b.length();// 标记绝对值位数

    int com_size, limit;

    if(a_size >= b_size){
        limit = a_size;
        com_size = a_size - b_size;
        complement.assign(com_size, '0'); 
        newa = a;
        newb = complement + b;
    }
    else{
        limit = b_size;
        com_size = b_size - a_size;
        complement.assign(com_size, '0'); 
        newa = complement + a;
        newb = b;
    }// 得到补位后的绝对值

    if(!a_sign && !b_sign){
        c = PosPos(newa, newb, limit);
        Pri(c, 0);
    }
    else if(a_sign && b_sign){
        c = PosPos(newa, newb, limit);
        Pri(c, 1);
    }
    else if(!a_sign && b_sign){
        PosNeg(newa, newb, limit, 0);
    }
    else{
        PosNeg(newb, newa, limit, 0);
    }
    return 0;
}

string PosPos(string newa, string newb, int limit){
    string c(limit, 0);
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
    return "1"[1-out] + c;
    
}

void PosNeg(string newa, string newb, int limit, int sign){// a应该大于等于b
    string c(limit, '0');
    int out = 0, sum = 0;
    for(int i = limit - 1; i >= 0; i--){

        sum = (newa[i]-'0') - (newb[i]-'0') - out;
        if(sum < 0){
            out = 1;
            sum += 10;
        }
        else{
            out = 0;
        }
        c[i] = sum + '0'; 
    }
    if(out){
        PosNeg(newb, newa, limit, 1);
    }
    else{
        Pri(c, sign);
    }
}

void Pri(string str, int sign){
    int size = str.size();
    int i;
    for(i = 0; i < size && (str[i] == '0' || str[i] == 0); i++){
        ;
    }
    if(sign && size != i){
        cout << "-";
    }
    if (size == i){
        cout << "0" << endl;
    }
    else{
        cout << str.substr(i) << endl;
    }
}