#include<set>
#include<cstdio>
#include<algorithm>
#define pii std::pair<int,int>
#define mp std::make_pair
typedef long long ll;
const int N=(int)(1e3);
pii a[N],at[N];
std::set<pii> set;
int main() {
  int testCount;
  scanf("%d",&testCount);
  while(testCount--) {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i) {
      scanf("%d%d",&a[i].first,&a[i].second);
      at[i]=mp(a[i].second,a[i].first);
    }
    set.clear();
    for(int i=0; i<m; ++i) {
      for(int j=0; j<m; ++j) {
        if(a[i].second==at[j].first) {
          set.insert(mp(a[i].first,at[j].second));
        }
      }
    }
    printf("%d\n",set.size());
  }
}
