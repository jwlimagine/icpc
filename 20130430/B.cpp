#include<cstdio>
#include<cmath>
const int eps=1e-9;
int signum(double x) {
  return x>eps?1:(fabs(x)<eps?0:-1);
}
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    double x,y,t,s,result;
    scanf("%lf%lf%lf%lf",&x,&y,&t,&s);
    if(signum(x-y)<=0) {
      result=s/x;
    } else {
      double previous=y*t;
      result=0;
      while(signum(s/x-previous/(x-y))>0) {
        result+=previous/(x-y);
        previous+=y*(previous/(x-y));
      }
      result+=s/x;
    }
    printf("Case #%d: %.3lf\n",test,result+eps);
  }
}
