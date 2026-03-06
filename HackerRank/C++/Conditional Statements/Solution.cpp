#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    string w[]={"","one","two","three","four","five","six","seven","eight","nine"};
    if(a>=1 && a<=9)
    {
        cout<<w[a]<<endl;
    }
    else
    {
        cout<<"Greater than 9";
    }
    return 0;
}
