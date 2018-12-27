//
//  MaxSubString.h
//  algrithem
//
//  Created by Apple on 2018/10/24.
//  Copyright © 2018年 Apple. All rights reserved.
//

#ifndef MaxSubString_h
#define MaxSubString_h

//寻找最长公共子序列问题：寻找两个字符串中最长的公共子序列，要求子序列在两个字符串中的顺序相同，可以不连续
//比如{A,D,F,I,O,P}和{A,B,F,O,L}最长公共子序列为{A,F,O}
//用动态规划求解
//c[i][j]是字符串1前i个子串和字符串2前j个子串的最长公共子序列长度
//b[i][j]：若xi==yj,b[i][j]=1；若xi!=yj且b[i-1][j]>b[i][j-1],则此时最长公共子序列是Yj和Xi-1的最长公共子序列，b[i][j]=2；若xi!=yj且b[i-1][j]<=b[i][j-1],则此时最长公共子序列是Yj-1和Xi的最长公共子序列，b[i][j]=3

string GetMaxSubString(string s1,string s2){
    int n1=s1.length();
    int n2=s2.length();
    int c[n1+1][n2+1],b[n1][n2];
    for(int i=0;i<=n1;i++)c[i][0]=0;
    for(int i=0;i<=n2;i++)c[0][i]=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
    
    string str="";
    int i=n1,j=n2;
    while(i&&j){
        if(b[i][j]==1){
            str+=s1[i-1];
            i--;j--;
        }else if(b[i][j]==2){
            i--;
        }else
            j--;
    }
    reverse(str.begin(), str.end());
    return str;
}

#endif /* MaxSubString_h */
