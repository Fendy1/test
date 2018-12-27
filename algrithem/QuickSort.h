//
//  QuickSort.h
//  algrithem
//
//  Created by Apple on 2018/10/30.
//  Copyright © 2018 Apple. All rights reserved.
//
//快速排序，用分治法思想
//在数组array从第low到第high个数中，选择一个点p(low+1)，从array[i++]到array[j--]依次与array[p]比较，小的放左边，大的放右边，直到i>=j，排序后array数组中p点左边都是比array[p]小的数，右边都是大的数。接着再对左边数组和右边数组进行上述排序。
#ifndef QuickSort_h
#define QuickSort_h

template<class T>
int findP(T *array,int low,int high){
    int i=low;
    int j=high;
    T x=array[i+1];
    while(i<j){
        while(array[i]<x&&i<j)i++;
        while(array[j]>x&&i<j)j--;
        if(i>=j)break;
        T t=array[i];
        array[i]=array[j];
        array[j]=t;
    }
    return i;
}
template<class T>
void QuickSort(T *array,int low,int high)
{
    if(low>=high)return;
    int p=findP(array,low,high);
    QuickSort(array,low,p-1);
    QuickSort(array,p+1,high);
}
#endif /* QuickSort_h */
