#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=(int)(1e6);
const int mod=(int)(1e9+7);
const int p=(int)(1e6+7);
char s[N+1];
int size,tree[1<<21],top,stack[N],previous[N],digit[N];
ll pow[N+1],value[N];
void pushup(int rt) {
  if(s[tree[rt<<1]]>=s[tree[rt<<1|1]]) {
    tree[rt]=tree[rt<<1];
  } else {
    tree[rt]=tree[rt<<1|1];
  }
}
void construct(int l,int r,int rt) {
  if(l==r) {
    tree[rt]=l;
  } else {
    int m=(l+r)>>1;
    construct(l,m,rt<<1);
    construct(m+1,r,rt<<1|1);
    pushup(rt);
  }
}
int query(int sl,int sr,int l,int r,int rt) {
  if(sl>r||sr<l) {
    return -1;
  } else {
    if(sl<=l&&r<=sr) {
      return tree[rt];
    } else {
      int m=(l+r)>>1;
      int lIndex=query(sl,sr,l,m,rt<<1);
      int rIndex=query(sl,sr,m+1,r,rt<<1|1);
      if(lIndex==-1||(rIndex!=-1&&s[lIndex]<s[rIndex])) {
        return rIndex;
      } else {
        return lIndex;
      }
    }
  }
}
int main() {
  for(int i=0; i<=N; ++i) {
    if(i==0) {
      pow[i]=1;
    } else {
      pow[i]=(pow[i-1]*p)%mod;
    }
  }
  while(scanf("%s",s)!=EOF) {
    size=strlen(s);
    construct(0,size-1,1);
    top=0;
    for(int i=0; i<size; ++i) {
      while(top&&s[stack[top-1]]<s[i]) {
        --top;
      }
      digit[i]=top+1;
      if(top) {
        previous[i]=stack[top-1];
        value[i]=(value[stack[top-1]]*p+(int)s[i])%mod;
      } else {
        previous[i]=-1;
        value[i]=s[i];
      }
      stack[top++]=i;
    }
    int queryCount;
    scanf("%d",&queryCount);
    while(queryCount--) {
      int l,r;
      scanf("%d%d",&l,&r);
      --l,--r;
      int index=query(l,r,0,size-1,1);
      while(index>=l) {
        index=previous[index];
      }
      ll result;
      if(index==-1) {
        result=value[r];
      } else {
        result=(value[r]-(value[index]*pow[digit[r]-digit[index]])%mod+mod)%mod;
      }
      printf("%lld\n",result);
    }
  }
}
