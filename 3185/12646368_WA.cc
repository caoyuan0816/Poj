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
#define MAX_N 25

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int bowl1[MAX_N];
int bowl2[MAX_N];

void solve(){
    int res1=0;
    for (int i=0; i<19; i++) {
        if (bowl1[i]%2==1) {
            bowl1[i]++;
            bowl1[i+1]++;
            if (i+2<20) {
                bowl1[i+2]++;
            }
            res1++;
        }
    }
    bowl1[19]%2==0?res1:res1=INF;
    int res2=0;bowl2[0]++;
    for (int i=0; i<19; i++) {
        if (bowl2[i]%2==1) {
            bowl2[i]++;
            bowl2[i+1]++;
            if (i+2<20) {
                bowl2[i+2]++;
            }
            res2++;
        }
    }
    bowl2[19]%2==0?res2:res2=INF;
    
    printf("%d\n",min(res1, res2));
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    for (int i=0; i<20; i++) {
        scanf("%d",&bowl1[i]);
        bowl2[i]=bowl1[i];
    }
    
    solve();
    
    return 0;
}
