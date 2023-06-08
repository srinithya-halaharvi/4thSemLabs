#include <iostream>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int len=0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    char ch=str[3];
    cout<<ch;
    return 0;
}

