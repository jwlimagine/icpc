#include<cstdio>
typedef long long ll;
const int N=(int)(1e5);
int n,m;
ll height[N][2];
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    ll previous=0,result=0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i) {
      scanf("%lld",&height[i][0]);
      if(i-m>=0) {
        previous-=height[i-m][1];
      }
      if(previous>=height[i][0]) {
        height[i][1]=0;
      } else {
        height[i][1]=height[i][0]-previous;
        result+=height[i][1];
        previous+=height[i][1];
      }
    }
    printf("Case #%d: %lld\n",test,result);
  }
}
