#include<cstdio>
#include<algorithm>
typedef long long ll;
struct SegmentTreeNode {
  ll add,height;
} tree[1<<19];
int n,m;
inline void pushdown(int m,int l,int r,int rt) {
  if(tree[rt].add) {
    tree[rt<<1].add+=tree[rt].add;
    tree[rt<<1].height+=tree[rt].add;
    tree[rt<<1|1].add+=tree[rt].add;
    tree[rt<<1|1].height+=tree[rt].add;
    tree[rt].add=0;
  }
}
void construct(int l,int r,int rt) {
  tree[rt].add=0;
  if(l==r) {
    scanf("%lld",&tree[rt].height);
  } else {
    int m=(l+r)>>1;
    construct(l,m,rt<<1);
    construct(m+1,r,rt<<1|1);
  }
}
int query(int x,int l,int r,int rt) {
  if(l==r) {
    return tree[rt].height;
  } else {
    int m=(l+r)>>1;
    pushdown(m,l,r,rt);
    if(x<=m) {
      return query(x,l,m,rt<<1);
    } else {
      return query(x,m+1,r,rt<<1|1);
    }
  }
}
void modify(int sl,int sr,ll add,int l,int r,int rt) {
  if(sl>r||sr<l) {
    return ;
  } else {
    if(sl<=l&&r<=sr) {
      tree[rt].height+=add;
      tree[rt].add+=add;
    } else {
      int m=(l+r)>>1;
      pushdown(m,l,r,rt);
      modify(sl,sr,add,l,m,rt<<1);
      modify(sl,sr,add,m+1,r,rt<<1|1);
    }
  }
}
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    scanf("%d%d",&n,&m);
    m=std::min(n,m);
    construct(0,n-1,1);
    ll result=0;
    for(int i=0; i<n; ++i) {
      ll height=query(i,0,n-1,1);
      if(height>0) {
        result+=height;
        modify(i,std::min(i+m-1,n-1),-height,0,n-1,1);
      }
    }
    printf("Case #%d: %lld\n",test,result);
  }
}
