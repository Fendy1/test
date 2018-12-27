//
//  ChessBoard.h
//  algrithem
//
//  Created by Apple on 2018/10/16.
//  Copyright © 2018年 Apple. All rights reserved.
//

#ifndef ChessBoard_h
#define ChessBoard_h
#include <iostream>
//棋盘问题：在2^k * 2^k 棋盘上有一个特殊方块，其他空白处用3块组成的L型木块进行覆盖，不允许重叠

//算法核心思想是分治法，即将棋盘四等分，有特殊点的那一部分接着四等分，其他部分在离中间最近的一个点铺上方块，（即将一块L型木块分成3小块，三小块成为新的特殊点，再接着四等分，如此循环下去，直到棋盘大小为1*1）


//填充一块
void FillBlock(int row,int column){
}
//leftTopRow是左上角所处的行，leftTopColumn是左上角所处的列，spRow是特殊方块所处的行，spCOlumn是特殊方块所处的列，size是棋盘大小，如2*2的棋盘size=2
void ChessBoard(int leftTopRow,int leftTopColumn,int spRow,int spColumn,int size){
    if(size==1)return;
    //棋盘大小四等分
    size/=2;
    //特殊点在左上角部分
    if(spRow<(size+leftTopRow)&&spColumn<(size+leftTopColumn))
        //继续四等分
        ChessBoard(leftTopRow,leftTopColumn,spRow,spColumn,size);
    else {
        //不在左上角部分，填充左上部分右下角小方块
        FillBlock(leftTopRow+size-1,leftTopColumn+size-1);
        //继续四等分，特殊点是右下角方块
        ChessBoard(leftTopRow,leftTopColumn,leftTopRow+size-1,leftTopColumn+size-1,size);
    }
    
    //特殊点在右上角部分
    if(spRow<(size+leftTopRow)&&spColumn>=(size+leftTopColumn))
        //继续四等分
        ChessBoard(leftTopRow,leftTopColumn+size,spRow,spColumn,size);
    else {
        //不在右上角部分，填充左下角小方块
        FillBlock(leftTopRow+size-1,leftTopColumn+size);
        //继续四等分，特殊点是左下角方块
        ChessBoard(leftTopRow,leftTopColumn+size,leftTopRow+size-1,leftTopColumn+size,size);
    }
    
    //特殊点在左下角部分
    if(spRow>=(size+leftTopRow)&&spColumn<(size+leftTopColumn))
        //继续四等分
        ChessBoard(leftTopRow+size,leftTopColumn,spRow,spColumn,size);
    else {
        //不在左下角部分，填充右上角小方块
        FillBlock(leftTopRow+size,leftTopColumn+size-1);
        //继续四等分，特殊点是右上角方块
        ChessBoard(leftTopRow+size,leftTopColumn,leftTopRow+size,leftTopColumn+size-1,size);
    }
    //特殊点在右下角部分
    if(spRow>=(size+leftTopRow)&&spColumn>=(size+leftTopColumn))
        //继续四等分
        ChessBoard(leftTopRow+size,leftTopColumn+size,spRow,spColumn,size);
    else {
        //不在右下角部分，填充左上角小方块
        FillBlock(leftTopRow+size,leftTopColumn+size);
        //继续四等分，特殊点是左上角方块
        ChessBoard(leftTopRow+size,leftTopColumn+size,leftTopRow+size,leftTopColumn+size,size);
    }
}

#endif /* ChessBoard_h */
