//
//  Knapsack.h
//  algrithem
//
//  Created by Apple on 2018/10/31.
//  Copyright © 2018 Apple. All rights reserved.
//
//0-1背包问题：有n个物品，给出每个物品的价值和占用空间大小，背包容量固定，求怎么装才能使背包里的价值最大。
//用动态规划解决：建立数组m[][]，m[i][j]意味着在容量为j的空间内，在第1个到第i个物品里面挑选的最优解的最大价值。从第1个物品到第i个物品的最优解，一定是【容量不变】时从第1个物品到第i-1个物品的最优解（没被选中），或者【容量为当前总容量-第i个物品的占用空间】时从第1个物品到第i个物品的最优解（被选中）
//容量够第i个物品时：m[i][j]=max(m[i-1][j],m[i][j-w[i]]+v[i]))，不够时：m[i][j]=m[i-1][j]
#ifndef Knapsack_h
#define Knapsack_h
//w为占用空间大小，v为价值，c为背包总容量，n为物品个数，x是输出字符串（第几个物品被选中）

template<class T>
class Knapsack{
private:
    T m[100][100];
    T v[100];
    T w[100];
    int c,n;
    void Init(){
        for(int i=0;i<=n;i++){m[i][0]=0;m[0][i]=0;}
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=c;j++)
            {
                //容量够，比较丢弃物品i的价值和放入i的价值那个大
                if(j>=w[i])
                    m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
                //容量不够，直接丢弃
                else
                    m[i][j]=m[i-1][j];
            }
        }
    }
        
public:
    Knapsack(T *_v,T *_w,int _c,int _n){
        v[0]=w[0]=0;
        for(int i=1;i<=_n;i++){
            v[i]=_v[i-1];
            w[i]=_w[i-1];
        }
        c=_c;
        n=_n;
        Init();
    }
    
    //Traceback函数为获得第几个物品被选中的字符串
    //如果m[i][j]!=m[i-1][j],则第i个物品被选中,然后总容量减去w[i]
    string GetSelectedItem(){
        string x="";
        T j=c;
        for(int i=n;i>=1;i--){
            if(m[i][j]!=m[i-1][j])
            {
                x+=to_string(i);
                j-=w[i];
            }
        }
        
        reverse(x.begin(),x.end());
        return x;
    }
    
    //获得最大价值
    int GetMaxValue(){
        return m[n][c];
    }

};

#endif /* Knapsack_h */
