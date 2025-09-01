#include<bits/stdc++.h>
using namespace std;
double Es=0.001;
double f(double x){
return pow(x,5)-3*x+5;


}
double df(double x)
{
  return 5*pow(x,4)-3;

}
void newtonRaphson(double x0){
double x1;
int i=0;
double error=fabs(x1-x0)/x1;
while(error>=Es){
  x1= x0-f(x0)/df(x0);
  error=fabs(x1-x0)/x1;
  i++;
  x0=x1;

}
cout<<"Iteration :"<<i<<" root : "<<x1<<"f(x1) : "<<f(x1)<<" "<<endl;

}

int main(){
double x0;
cin>>x0;
int x;

newtonRaphson(x0);


}
