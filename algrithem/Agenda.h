//
//  Agenda.h
//  algrithem
//
//  Created by Apple on 2018/11/24.
//  Copyright © 2018 Apple. All rights reserved.
//

#ifndef Agenda_h
#define Agenda_h
//利用分治法处理比赛日程问题：共n=2^k个选手，每个选手必须与其他选手各赛一次，每个选手一天只能比赛一次，比赛一共进行n-1天
//将日程表等分成四块，左下角复制右上角数组，右下角复制左上角数组，左上和右上继续划分成四块，直到剩下一个数无法继续划分
class Agenda{
private:
    int PlayersNumber;//参赛选手数量
    int agenda[100][100];//日程表数组
    void GetAgenda(int w1,int w2,int h1,int h2){
        if(w1==w2)return;
        if(h1==h2)return;
        GetAgenda(w1,w1+(w2-w1)/2,h1,h1+(h2-h1)/2);  //左上角继续划分
        GetAgenda(w1+(w2-w1)/2+1,w2,h1,h1+(h2-h1)/2);  //右上角继续划分
        Copy(w1,w1+(w2-w1)/2,h1+(h2-h1)/2+1,h2,true);  //左下角复制右上角数组
        Copy(w1+(w2-w1)/2+1,w2,h1+(h2-h1)/2+1,h2,false);  //右下角复制左上角数组
    }
    void Copy(int w1,int w2,int h1,int h2,bool isLeft){
        int internal=w2-w1+1;
        for(int i=0;i<internal;i++){
            for(int j=0;j<internal;j++){
                if(isLeft)
                agenda[h1+i][w1+j]=agenda[h1-internal+i][w1+j+internal];
                else agenda[h1+i][w1+j]=agenda[h1-internal+i][w1+j-internal];
            }
        }
    }
public:
    Agenda(int n){
        PlayersNumber=n;
        //初始化第一行和第一列
        for(int i=0;i<n;i++){
            agenda[0][i]=i+1;
            agenda[i][0]=i+1;
        }
        GetAgenda(0,n-1,0,n-1);
    }
    //输出日程表数组
    void Output(){
        for(int i=0;i<PlayersNumber;i++){
            for(int j=0;j<PlayersNumber;j++){
                cout<<agenda[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

#endif /* Agenda_h */
