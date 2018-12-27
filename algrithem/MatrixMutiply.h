//
//  MatrixMutiply.h
//  algrithem
//
//  Created by Apple on 2018/10/23.
//  Copyright © 2018年 Apple. All rights reserved.
//

#ifndef MatrixMutiply_h
#define MatrixMutiply_h

//矩阵连乘问题：给定的N个矩阵，求什么计算次序能够使连乘次数最少，用动态规划求解
//n是矩阵个数,p是矩阵的阶数，m[i][j]是第i矩阵到第j矩阵的最优次数，s[i][j]是矩阵i到矩阵j最优划分时从第几个矩阵切开
using namespace std;
class MatrixMutiply
{
private:
    int *p;
    string order="";
    int n;
    int s[100][100],m[100][100];
    int Mutiply(int first,int last){
        //已经求得的直接返回
        if(m[first][last]>0)return m[first][last];
        //一个矩阵最优次数为0
        if(last==first)return 0;
        //假设第一个矩阵和后面矩阵最优解次序相乘为最优解
        int min=Mutiply(first+1,last)+ p[first-1]*p[first]*p[last];
        s[first][last]=first;
        //第first到第i个矩阵的最优解 和 第i+1到第last个矩阵的最优解 相乘
        for(int i=first+1;i<last;i++){
            int a=Mutiply(first,i)+Mutiply(i+1,last)+p[first-1]*p[i]*p[last];
            if(min>a){
                min=a;
                s[first][last]=i;
            }
            
        }
        m[first][last]=min;
        return min;
    }
    void getOrderString(int first,int last){
        if(first==last)return;
        if((last-first)==1)return;
        int a=s[first][last];
        int i;
        //插入括号
        if((a-first)!=0){
            i=order.find(to_string(a));
            order.insert(i+1,")");
            i=order.find(to_string(first));
            order.insert(i,"(");
        }
        if((last-a)!=1){
            i=order.find(to_string(a+1));
            order.insert(i,"(");
            i=order.find(to_string(last));
            order.insert(i+1,")");
        }
        getOrderString(first, a);
        getOrderString(a+1, last);
    }
public:
    MatrixMutiply(int _n,int *_p){
        p=_p;
        n=_n;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                s[i][i]=0;
                m[i][i]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            order+=to_string(i);
        }
        Mutiply(1, n);
        getOrderString(1, n);
    }
    int getMinNumber(){
        return Mutiply(1, n);
    }
    
    string getOrderString(){
        
        return order;
    }
};

#endif /* MatrixMutiply_h */
