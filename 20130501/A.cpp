#include<map>
#include<cmath>
#include<cstdio>
#define pdd std::pair<double,double>
#define mp std::make_pair
const int N=(int)(2e2);
pdd points[N];
bool connect[N][N];
std::map<pdd,int> map;
const double eps=1e-9;
int signum(double x) {
  return x>eps?1:(fabs(x)<eps?0:-1);
}
bool collinear(int a,int b,int c) {
  return signum((points[b].first-points[a].first)*(points[c].second-points[a].second)-
                (points[c].first-points[a].first)*(points[b].second-points[a].second))==0;
}
int main() {
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF) {
    map.clear();
    for(int i=0; i<n; ++i) {
      scanf("%lf%lf",&points[i].first,&points[i].second);
      map[points[i]]=i;
    }
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        connect[i][j]=false;
      }
    }
    for(int i=0; i<m; ++i) {
      double x1,y1,x2,y2;
      scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
      int a=map[mp(x1,y1)];
      int b=map[mp(x2,y2)];
      connect[a][b]=connect[b][a]=true;
    }
    for(int k=0; k<n; ++k) {
      for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
          if(connect[i][k]&&connect[k][j]&&collinear(i,k,j)) {
            connect[i][j]=true;
          }
        }
      }
    }
    int count=0;
    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        for(int k=j+1; k<n; ++k) {
          if(connect[i][j]&&connect[j][k]&&connect[k][i]&&(!collinear(i,j,k))) {
            count++;
          }
        }
      }
    }
    printf("%d\n",count);
  }
}
