#include<cstdio>
const int N=(int)(1e3);
int a[N],b[N];
int main() {
  int n;
  while(scanf("%d",&n)!=EOF) {
    for(int i=0; i<n; ++i) {
      scanf("%d",&a[i]);
    }
    for(int i=0; i<n; ++i) {
      scanf("%d",&b[i]);
    }
    int result=0,index;
    for(int i=0; i<n; ++i) {
      if(a[i]*b[i]>result) {
        result=a[i]*b[i];
        index=i+1;
      }
    }
    printf("%d\n",index);
  }
}
