#include<cstdio>
const int N=(int)(1e6);
const int mod=(int)(1e8+9);
typedef long long ll;
ll pow[N+1];
char text[N+1];
int main() {
  for(int i=0; i<=N; ++i) {
    if(i==0) {
      pow[i]=1;
    } else {
      pow[i]=(pow[i-1]*2)%mod;
    }
  }
  int testCount;
  scanf("%d",&testCount);
  while(testCount--) {
    scanf("%s",text);
    int xCount=0,yCount=0;
    for(int i=0; text[i]; ++i) {
      if(text[i]=='L'||text[i]=='R') {
        yCount++;
      } else {
        xCount++;
      }
    }
    ll result=0;
    if(text[0]=='L'||text[0]=='R') {
      if(xCount>=1) {
        result=(result+pow[xCount-1]*(pow[yCount]-2))%mod;
      }
      result=(result+pow[yCount-1]*(pow[xCount]-1))%mod;
      if(!xCount) {
        result=(result+(pow[yCount-1]-1))%mod;
      }
    } else {
      if(yCount>=1) {
        result=(result+pow[yCount-1]*(pow[xCount]-2))%mod;
      }
      result=(result+pow[xCount-1]*(pow[yCount]-1))%mod;
      if(!yCount) {
        result=(result+(pow[xCount-1]-1))%mod;
      }
    }
    printf("%lld\n",result);
  }
}
