//
//  MaxSum.h
//  algrithem
//
//  Created by Apple on 2018/10/24.
//  Copyright © 2018年 Apple. All rights reserved.
//

#ifndef MaxSum_h
#define MaxSum_h
//最大子段和问题：寻找一组数中子段和最长的序列，用动态规划求解
//如果a[j]之前和为负数，则最大和的子段一定是从a[j]开始
//b为子段和，max为最大子段和
int MaxSum(int *a,int n){
    int max=0;
    int b=a[0];
    for(int i=1;i<n;i++){
        if(b>0)
            b+=a[i];
        else b=a[i];
        if(b>max)
            max=b;
    }
    return max;
}
#endif /* MaxSum_h */
