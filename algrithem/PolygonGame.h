//
//  PolygonGame.h
//  algrithem
//
//  Created by Apple on 2018/11/1.
//  Copyright © 2018 Apple. All rights reserved.
//
//多边形游戏：一个缺一条边的多边形的顶点是数字（可为负数），边是+或者*，每次拿去一条边并对顶点和边进行计算得到新的数字，直到最后剩下唯一一个数字，求这个数字的最大值。
//用动态规划求解
//设m[i][j][0]是从顶点i到顶点j的最大值，m[i][j][1]是最小值，m[i][j][0]必定是max{m[i][k][0]+[k+1][j][0]}或者乘法时m[i][k][0],m[i][k][1]与m[k+1][j][0],m[k+1][j][1]相乘的最大值（考虑负数情况）(i<=k<=j)
//point[]是点的数值，line是每条边是+或者*，n是点的个数
#ifndef PolygonGame_h
#define PolygonGame_h
template<class T>
class PolygonGame{
private:
    int n;
    char line[100];
    T point[100];
    T m[100][100][2];
    //p是从边p开始划分（第p+1条边）
    //填充m[first][last][0]和m[first][last][1]数组
    void BetweenTwoGroup(int first,int last,int p,T &max,T &min){
        if(line[p]=='+'){
          max=min= m[first][p][0]+m[p+1][last][0];
        }else{
            T e[4]={
                m[first][p][0]*m[p+1][last][0],
                m[first][p][1]*m[p+1][last][0],
                m[first][p][0]*m[p+1][last][1],
                m[first][p][1]*m[p+1][last][1]
            };
            min=max=e[0];
            for(int i=1;i<4;i++){
                if(e[i]>max)max=e[i];
                if(e[i]<min)min=e[i];
            }
        }
    }
public:
    PolygonGame(T *_point,char *_line,int _n){
        n=_n;
        for(int i=0;i<n;i++){
            line[i]=_line[i];
            point[i]=_point[i];
        }
        for(int i=0;i<n;i++){
            m[i][i][0]=m[i][i][1]=point[i];
        }
        for(int i=0;i<n-1;i++){
            if(line[i]=='+')
                m[i][i+1][0]=m[i][i+1][1]=point[i]+point[i+1];
            else{
                m[i][i+1][0]=m[i][i+1][1]=point[i]*point[i+1];
            }
        }
    }
    T GetMaxNumber(){
        //p是间隔，i是first,j是分割点(从first到last，即i到i+p)
        //p从1增大到n-1
        int max,min;
        max=min=0;
        int maxf,minf;
        for(int p=2;p<n;p++){
            for(int i=0;i<n-p;i++){
                BetweenTwoGroup(i,i+p,i,max,min);
                maxf=max;minf=min;
                for(int j=i+1;j<i+p;j++){
                    BetweenTwoGroup(i,i+p,j,max,min);
                    if(max>maxf)maxf=max;
                    if(min<minf)minf=min;
                }
                m[i][i+p][0]=maxf;m[i][i+p][1]=minf;
            }
        }
        return m[0][n-1][0];
    }
};

#endif /* PolygonGame_h */
