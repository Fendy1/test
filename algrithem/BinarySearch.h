//
//  BinarySearch.h
//  algrithem
//
//  Created by Apple on 2018/10/12.
//  Copyright © 2018年 Apple. All rights reserved.
//

#ifndef BinarySearch_h
#define BinarySearch_h

/*二分搜索法*/
template<class T>
//在数组a中查找目标T，共n个元素，返回下标，默认已经排序好
int BinarySearch(T a[],const T &target,int n){
    int left=0,right=n-1,middle;
    //左边界大于右边界时停止循环，没找到
    while(left<=right){
        //中界线
        middle=(left+right)/2;
        //中界线是目标，返回下标，退出搜索
        if(a[middle]==target)return middle;
        //目标大于中界线数值，左边界移至中界线右边
        else if(a[middle]<target)left=middle+1;
        //目标小于中界线数值，右边界移至中界线左边
        else right=middle-1;
    }
    //没找到返回-1
    return -1;
}
#endif /* BinarySearch_h */
