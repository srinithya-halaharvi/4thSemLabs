#include <iostream>

using namespace std;

int main()
{
    char str[100],ss[50];
    cout<<"Enter string:";
    cin.getline(str,100);
    int len=0,lens=0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    cout<<"Enter substring to be searched for:";
    cin.getline(ss,50);
    for(int i=0;ss[i]!='\0';i++){
        lens++;
    }
    cout<<"Substring found at positions:"<<endl;
    for(int i=0;i<len;i++){
        int k=0,flag=1;
        if(str[i]==ss[0]){
            for(int j=i+1;j<(i+lens);j++){
                k++;
                if(str[j]!=ss[k]){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                cout<<i<<" ";
            }
        }
    }
    return 0;
}
