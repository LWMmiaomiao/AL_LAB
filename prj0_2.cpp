#include <iostream>
#include <vector>
#define ISDIG(a) ((a) >= '0' && (a) <= '9')
#define ISSUP(a) ((a) >= 'A' && (a) <= 'Z')
#define ISLOW(a) ((a) >= 'a' && (a) <= 'z')
#define TOLOW(ch) ((char)((ch) - 'A' + 'a'))
using namespace std;
int main(void){
    char ch;
    vector <char> str;
    while(cin >> ch){
        if(ISDIG(ch)){
            str.push_back(ch);
        }
        else if(ISSUP(ch)){
            str.push_back(TOLOW(ch));
        }
        else if(ISLOW(ch)){
            str.push_back(ch);
        }
    }

    int end = str.size() - 1;
    int i;
    for(i = 0; i <= end/2 && str[i] == str[end - i]; i++){
        ;
    }
    cout << (i > end/2 ? "YES" : "NO") << endl;
    return 0;
}