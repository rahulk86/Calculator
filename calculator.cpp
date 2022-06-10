#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
using namespace std;

class calculator
{
  float x;
  int Size;
  string s;
public:
 calculator(){x=0;Size=0;}
 void display();

 void add(float n){
     int y=n;
     s=s+to_string(y);
     if(n!=float(y))
     {
       int x=n*100;
       s.push_back('.');
       s=s+to_string(x%100);
     }
     s.push_back('+');
     x=x+n;
     }
 void sub(float n){
     int y=n;
     s=s+to_string(y);
     if(n!=float(y))
     {
       int x=n*100;
       s.push_back('.');
       s=s+to_string(x%100);
     }
     s.push_back('-');
     x?x=x-n:(x=n);
     }
 void sinX(float a){x=sin(a);}
 void cosX(float a){x=cos(a);}
 void tanX(float a){x=tan(a);}
 void mult(float n){
     int y=n;
     s=s+to_string(y);
     if(n!=float(y))
     {
       int x=n*100;
       s.push_back('.');
       s=s+to_string(x%100);
     }
     s.push_back('x');
     x?x*=n:(x=n);
     }
 void div(float n){
     int y=n;
     s=s+to_string(y);
     if(n!=float(y))
     {
       int x=n*100;
       s.push_back('.');
       s=s+to_string(x%100);
     }
     s.push_back('/');
     x?x/=n:(x=n);
     }
 void log2X(float n){x=log2(n);}
 void rem(float n){x?(x=int(x)%int(n)):(x=n);}
 void gotoxy(int,int);
 float view();
 float gcd(float,float);
 void lcm(float,float);
 void log10X(int k){x=log10(k);}
 void logex(int k){x=log(k);}
 void pow2x(int k){x=pow(2,k);}

 void setca(){s.clear();x=0;}
 void pow1(int n)
 {
     int k=int(x);
     if(x)
        x=pow(k,n);
        else
        x=n;
 }
 void lcm2(float k)
 {
     if(x)
        lcm(k,x);
     else
        x=k;
 }
 void gcd1(int k)
 {
     if(k)
      x=gcd(k,x);
     else
        x=k;
 }
};
void calculator :: gotoxy(int x,int y)
{
    COORD v;
    v.X=x;
    v.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),v);
}
float calculator :: view(){
    if(Size<=7)
        Size=s.size();
    gotoxy(16,5);
    int k=s.size();
       if(k<=12)
        cout<<s;
       else{
    for(int i=k-12;i<k;i++)
          cout<<s[i];
       }
    gotoxy(29,6);
    cout<<"=";
    gotoxy(30,6);
    return x;
    }
void calculator :: display()
{
    int x=30;
  for(int i=0;i<x;i++)
     for(int j=0;j<46;j++)
       {
           gotoxy(9+j,i);
         if(i<2||i>8&&i<12||i>27||j<2||j>43)
         {
             if(i==14)
             {
               cout<<"** 1.+ |  2.- |3.sin     | 4.cos   | 5.tan  **";
               break;
             }
             else
             if(i==18)
             {
               cout<<"** 6.x |  7./ |8.log2()  | 9.X^1/3 |10.LCM  **";
               break;
             }
             else
             if(i==22)
             {
               cout<<"**11.% |12.X^Y|13.log10()|14.loge()|15.2^n  **";
               break;
             }
             else
             if(i==26)
             {
               cout<<"**16.= |17.cls|18.X^1/2  |19.cos^-1|20.HCF  **";
               break;
             }
             else
             cout<<"*";
         }
         else
            if(i>=12&&(j==7||j==14||j==25||j==35))
            cout<<"|";
         else
             if(i==15||i==19||i==23||i==27)
             cout<<"-";
         else
            cout<<" ";
       }
}
float calculator:: gcd(float a,float b)
{
    if(a==0)
        return b;
    return gcd(int(b)%int(a),a);

}
void calculator:: lcm(float a,float b)
{

    x=a*b/gcd(a,b);
}
int main()
{
 calculator c;
 c.display();
 while(1)
 {

     c.gotoxy(22,6);cout<<"                        ";c.gotoxy(22,6);cout<<c.view();//c.gotoxy(0,30);
     float n;
     int k;
     c.gotoxy(40,8);
     cin>>k;
     if(k!=17&&k<21)
         cin>>n;
     c.gotoxy(40,8);
     cout<<"            ";
     switch(k)
     {
        case 1:c.add(n);break;
        case 2:c.sub(n);break;
        case 3:c.sinX(n);break;
        case 4:c.cosX(n);break;
        case 5:c.tanX(n);break;
        case 6:c.mult(n);break;
        case 7:c.div(n);break;
        case 8:c.log2X(n);break;
        case 9:break;
        case 10:c.lcm2(n);break;
        case 11:c.rem(n);break;
        case 12:c.pow1(n);break;
        case 13:c.log10X(n);break;
        case 14:c.logex(n);break;
        case 15:c.pow2x(n);break;
        case 16:break;
        case 17:c.setca();break;
        case 18:break;
        case 19:break;
        case 20:c.gcd1(n);break;
        default:system("cls");exit(0);
     }
 }
}
