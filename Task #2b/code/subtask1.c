#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int v;
    struct node*left;
    struct node*right;
}node;

typedef struct q{
    node**a;
    int f;
    int r;
    int n;
}q;

q*newq(int n){
    q*t=(q*)malloc(sizeof(q));
    t->a=(node**)malloc(sizeof(node*)*n);
    t->f=t->r=0;
    t->n=n;
    return t;
}

bool empty(q*t){
    return t->f==t->r;
}

void push(q*t,node*x){
    t->a[t->r++]=x;
}

node*pop(q*t){
    return t->a[t->f++];
}

node*newnode(){
    node*t=(node*)malloc(sizeof(node));
    t->v=1;
    t->left=t->right=NULL;
    return t;
}

node*maketree(int*a,int n){
    if(n==0||a[0]==0)return NULL;
    q*t=newq(n);
    node*r=newnode();
    push(t,r);
    int i=1;
    while(i<n&&!empty(t)){
        node*cur=pop(t);
        if(i<n&&a[i]==1){
            cur->left=newnode();
            push(t,cur->left);
        }
        i++;
        if(i<n&&a[i]==1){
            cur->right=newnode();
            push(t,cur->right);
        }
        i++;
    }
    return r;
}

int ans=0;

int dfs(node*t){
    if(!t)return 1;
    int l=dfs(t->left);
    int r=dfs(t->right);
    if(l==2||r==2){
        ans++;
        return 0;
    }
    if(l==0||r==0)return 1;
    return 2;
}

int solve(node*r){
    if(!r)return 0;
    int s=dfs(r);
    if(s==2)ans++;
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    int*a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    node*r=maketree(a,n);
    printf("%d\n",solve(r));
    return 0;
}

