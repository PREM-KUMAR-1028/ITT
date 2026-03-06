#include<iostream>
#include<string>
using namespace std;
class student
 {
    private:
     int a;
     string fn;
     string sn;
     int c;
    public:
     void get()
     {
         cin>>a;
         cin>>fn;
         cin>>sn;
         cin>>c;
     }
     void display()
     {
        cout<<a<<endl;
        cout<<sn<<", "<<fn<<endl;
        cout<<c<<endl;
        cout<<endl;
        cout<<a<<","<<fn<<","<<sn<<","<<c<<endl;
     }
    };
int main()
    {
        student s1;
        s1.get();
        s1.display();
        return 0;
    }
