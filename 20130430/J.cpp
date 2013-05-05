#include<cstdio>
#include<algorithm>
const int N=(int)(1e5);
char s[N+1];
int n,count[26],name[10][26];
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    scanf("%s",s);
    for(int i=0; i<26; ++i) {
      count[i]=0;
    }
    for(int i=0; s[i]; ++i) {
      count[s[i]-'a']++;
    }
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
      for(int j=0; j<26; ++j) {
        name[i][j]=0;
      }
      scanf("%s",s);
      for(int j=0; s[j]; ++j) {
        name[i][s[j]-'a']++;
      }
    }
    int result=0;
    for(int i=0; i<(1<<n); ++i) {
      int sum[26];
      for(int j=0; j<26; ++j) {
        sum[j]=0;
      }
      int digit=0;
      for(int j=0; j<n; ++j) {
        if(i&(1<<j)) {
          for(int k=0; k<26; ++k) {
            sum[k]+=name[j][k];
          }
          digit++;
        }
      }
      bool ok=true;
      for(int j=0; j<26; ++j) {
        if(sum[j]>count[j]) {
          ok=false;
          break;
        }
      }
      if(ok) {
        result=std::max(result,digit);
      }
    }
    printf("Case #%d: %d\n",test,result);
  }
}
