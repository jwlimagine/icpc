#include<cstdio>
#include<algorithm>
#define mp std::make_pair
#define pii std::pair<char,int>
const int N=(int)(1e6);
char brackets[N+1];
pii stack[N];
int length[N];
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    scanf("%s",brackets);
    int top=0,result=0;
    for(int i=0; brackets[i]; ++i) {
      length[i]=0;
      if(brackets[i]=='('||brackets[i]=='['||brackets[i]=='{') {
        stack[top++]=mp(brackets[i],i);
      } else if(brackets[i]==')') {
        if(top==0||stack[top-1].first!='(') {
          top=0;
        } else {
          length[i]=i-stack[top-1].second+1;
          if(stack[top-1].second>0) {
            length[i]+=length[stack[top-1].second-1];
          }
          --top;
        }
      } else if(brackets[i]==']') {
        if(top==0||stack[top-1].first!='[') {
          top=0;
        } else {
          length[i]=i-stack[top-1].second+1;
          if(stack[top-1].second>0) {
            length[i]+=length[stack[top-1].second-1];
          }
          --top;
        }
      } else if(brackets[i]=='}') {
        if(top==0||stack[top-1].first!='{') {
          top=0;
        } else {
          length[i]=i-stack[top-1].second+1;
          if(stack[top-1].second>0) {
            length[i]+=length[stack[top-1].second-1];
          }
          --top;
        }
      }
      result=std::max(result,length[i]);
    }
    if(!result) {
      printf("Case #%d: I think H is wrong!\n",test);
    } else {
      printf("Case #%d: %d\n",test,result);
    }
  }
}

