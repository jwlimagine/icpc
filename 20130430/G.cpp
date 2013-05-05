#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
typedef long long ll;
const int SIGMA_SIZE=26;
const int N=(int)(1e5+1);
const int MAX_LENGTH=(int)(1e6+1);
struct trie_node_st {
  int next[SIGMA_SIZE],s,fail;
} node[N];
int count;
void add() {
  std::fill(node[count].next,node[count].next+SIGMA_SIZE,-1);
  node[count].s=INT_MAX;
  count++;
}
void init() {
  count=0;
  add();
}
void insert(const char *p) {
  int curr=0;
  for(int i=0; p[i]; ++i) {
    int id=p[i]-'a';
    if(node[curr].next[id]==-1) {
      node[curr].next[id]=count;
      add();
    }
    curr=node[curr].next[id];
  }
  node[curr].s=strlen(p);
}
int queue[N],head,tail;
void construct() {
  node[0].fail=0;
  head=tail=0;
  queue[tail++]=0;
  while(head!=tail) {
    int u=queue[head++];
    for(int i=0; i<SIGMA_SIZE; ++i) {
      if(node[u].next[i]!=-1) {
        int v=node[u].next[i];
        queue[tail++]=v;
        node[v].fail=0;
        if(u==0) {
          continue;
        }
        int curr=u;
        while(curr) {
          curr=node[curr].fail;
          if(node[curr].next[i]!=-1) {
            node[v].fail=node[curr].next[i];
            break;
          }
        }
        node[v].s=std::min(node[v].s,node[node[v].fail].s);
      } else {
        int curr=u;
        while(curr) {
          curr=node[curr].fail;
          if(node[curr].next[i]!=-1) {
            node[u].next[i]=node[curr].next[i];
            break;
          }
        }
        if(node[u].next[i]==-1) {
          node[u].next[i]=0;
        }
      }
    }
  }
}
char text[MAX_LENGTH],p[N];
int main() {
  int testCount;
  scanf("%d",&testCount);
  for(int test=1; test<=testCount; ++test) {
    scanf("%s",text);
    int n;
    scanf("%d",&n);
    init();
    for(int i=0; i<n; ++i) {
      scanf("%s",p);
      insert(p);
    }
    construct();
    ll result=0;
    int curr=0,length=0;
    for(int i=0; text[i]; ++i) {
      length++;
      int id=text[i]-'a';
      curr=node[curr].next[id];
      if(node[curr].s!=INT_MAX) {
        length=std::min(length,node[curr].s-1);
      }
      result+=length;
    }
    printf("Case #%d: %lld\n",test,result);
  }
}
