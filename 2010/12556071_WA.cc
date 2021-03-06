//
//  main.cpp
//  test
//
//  Created by Yuan on 14-1-29.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 100005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

long long N,C,F;
typedef pair<long long, long long> P;
P cow[MAX_N];
long long up[MAX_N],down[MAX_N];

void solve(){
    sort(cow, cow+C);
    
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    priority_queue<long long> pq;
    
    for (long long i=C-1; i>=0; i--) {
        pq.push(cow[i].second);
        if (pq.size()==N/2) {
            queue<long long> que;
            rep(N/2){
                up[i]+=pq.top();
                que.push(pq.top());
                pq.pop();
            }
            rep(N/2){
                pq.push(que.front());
                que.pop();
            }
        }
        if (pq.size()==N/2+1) {
            if (pq.top()==cow[i].second) {
                pq.pop();
                up[i]=up[i+1];
            }else{
                up[i]=up[i+1]+cow[i].second-pq.top();
                pq.pop();
            }
        }
    }
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i=0; i<C; i++) {
        pq.push(cow[i].second);
        if (pq.size()==N/2) {
            queue<long long> que;
            rep(N/2){
                down[i]+=pq.top();
                que.push(pq.top());
                pq.pop();
            }
            rep(N/2){
                pq.push(que.front());
                que.pop();
            }
        }
        if (pq.size()==N/2+1) {
            if (pq.top()==cow[i].second) {
                pq.pop();
                down[i]=down[i-1];
            }else{
                down[i]=down[i-1]+cow[i].second-pq.top();
                pq.pop();
            }
        }
    }

    for (long long i=C-N/2-1; i>=N/2; i--) {
        if (up[i]+down[i]+cow[i].second<=F) {
            printf("%lld\n",cow[i].first);
            return ;
        }
    }
    printf("-1\n");
    
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%lld %lld %lld",&N,&C,&F);
    for (int i=0; i<C; i++) {
        scanf("%lld %lld",&cow[i].first,&cow[i].second);
    }
    
    solve();
    
    return 0;
}
