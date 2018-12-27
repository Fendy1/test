//
//  MergeSort.h
//  algrithem
//
//  Created by Apple on 2018/10/27.
//  Copyright © 2018年 Apple. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h
//合并排序，用分治法
//将得到的元素分成大小大致相同的两个子集合，分别对两个子集合进行排序，然后对两个子集进行合并。合并中对两个数组从第一个元素进行比对，小的加入临时数组，指针加一，大的元素数组指针不加，等待下一次比对。
//array为原数组，low是第一个元素位置，high是最后一个元素位置，middle是中间位置。分成两个数组array[low,middle]和array[middle+1,high]，分别进行排序
template<class T>
void Merge(T *array,int low,int high,int middle){
    int i=low,j=middle+1;
    T temp[high-low+1];
    int k=0;
    while(i<=middle&&j<=high)
    if(array[i]<array[j]){
        temp[k++]=array[i++];
    }else{
        temp[k++]=array[j++];
    }
    while(i<=middle)temp[k++]=array[i++];
    while(j<=high)temp[k++]=array[j++];
    for(int i=low;i<=high;i++){
        array[i]=temp[i-low];
    }
}
template<class T>
void MergeSort(T *array,int low,int high){
    if(low>=high)return;
    int middle=(low+high)/2;
    MergeSort(array,low,middle);
    MergeSort(array,middle+1,high);
    Merge(array,low,high,middle);
}
#endif /* MergeSort_h */
