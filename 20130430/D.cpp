#include<cstdio>
#include<cmath>
#include<algorithm>
const double eps=1e-9;
const int N=(int)(1e2);
const int MAX_SUM=(int)(1e3);
int signum(double x) {
  return x>eps?1:(fabs(x)<eps?0:-1);
}
int n,time,b[N],bSum,course[N][10],contest[2][3],base[2][3][N],initial[N],dp[2][MAX_SUM+1];
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    scanf("%d%d",&n,&time);
    bSum=0;
    for(int i=0; i<n; ++i) {
      scanf("%d",&b[i]);
      bSum+=b[i];
      for(int j=0; j<10; ++j) {
        scanf("%d",&course[i][j]);
      }
    }
    for(int i=0; i<2; ++i) {
      for(int j=0; j<3; ++j) {
        scanf("%d",&contest[i][j]);
        for(int k=0; k<n; ++k) {
          scanf("%d",&base[i][j][k]);
        }
      }
    }
    double result=-1.0;
    for(int i=0; i<4; ++i) {
      for(int j=0; j<4; ++j) {
        int contestScore=0,left=time;
        for(int k=0; k<n; ++k) {
          initial[k]=0;
        }
        if(i!=3) {
          left-=contest[0][i];
          contestScore+=i+1;
          for(int k=0; k<n; ++k) {
            initial[k]=std::max(initial[k],base[0][i][k]);
          }
        }
        if(j!=3) {
          left-=contest[1][j];
          contestScore+=j+1;
          for(int k=0; k<n; ++k) {
            initial[k]=std::max(initial[k],base[1][j][k]);
          }
        }
        for(int k=0; k<n; ++k) {
          initial[k]=std::min(initial[k],10);
        }
        if(left>=0) {
          int x=0,y=1;
          for(int k=0; k<=left; ++k) {
            dp[x][k]=0;
          }
          for(int p=0; p<n; ++p) {
            for(int q=0; q<=left; ++q) {
              dp[y][q]=-1;
              for(int score=initial[p],need=0; score<=10; ++score) {
                if(score>=6) {
                  if(q>=need&&dp[x][q-need]!=-1) {
                    if(dp[y][q]==-1) {
                      dp[y][q]=dp[x][q-need]+score*10*b[p];
                    } else {
                      dp[y][q]=std::max(dp[y][q],dp[x][q-need]+score*10*b[p]);
                    }
                  }
                }
                if(score!=10) {
                  need+=course[p][score];
                }
              }
            }
            std::swap(x,y);
          }
          for(int q=0; q<=left; ++q) {
            if(dp[x][q]!=-1) {
              result=std::max(result,(double)dp[x][q]/bSum+contestScore);
            }
          }
        }
      }
    }
    if(!signum(result+1)) {
      printf("Case #%d: Impossible\n",test);
    } else {
      printf("Case #%d: %.2lf\n",test,result);
    }
  }
}
